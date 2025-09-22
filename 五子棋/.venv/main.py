import pygame
import sys
import math

# 五子棋游戏实现
# 棋盘大小
BOARD_SIZE = 15
CELL_SIZE = 40
BOARD_WIDTH = BOARD_SIZE * CELL_SIZE
BOARD_HEIGHT = BOARD_SIZE * CELL_SIZE
LINE_COLOR = (0, 0, 0)
BG_COLOR = (255, 165, 0)  # 米色背景
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

# 棋子类型
EMPTY = 0
BLACK_PIECE = 1
WHITE_PIECE = 2

class Gomoku:
    def __init__(self):
        self.board = [[EMPTY for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]
        self.current_player = BLACK_PIECE
        self.game_over = False
        self.winner = None

    def make_move(self, x, y, player):
        if 0 <= x < BOARD_SIZE and 0 <= y < BOARD_SIZE and self.board[y][x] == EMPTY:
            self.board[y][x] = player
            if self.check_winner(x, y, player):
                self.game_over = True
                self.winner = player
            self.current_player = 3 - player  # 切换玩家
            return True
        return False

    def check_winner(self, x, y, player):
        directions = [(1,0), (0,1), (1,1), (1,-1)]
        for dx, dy in directions:
            count = 1
            # 正方向
            nx, ny = x + dx, y + dy
            while 0 <= nx < BOARD_SIZE and 0 <= ny < BOARD_SIZE and self.board[ny][nx] == player:
                count += 1
                nx += dx
                ny += dy
            # 反方向
            nx, ny = x - dx, y - dy
            while 0 <= nx < BOARD_SIZE and 0 <= ny < BOARD_SIZE and self.board[ny][nx] == player:
                count += 1
                nx -= dx
                ny -= dy
            if count >= 5:
                return True
        return False

    def is_full(self):
        return all(all(cell != EMPTY for cell in row) for row in self.board)

    def get_valid_moves(self):
        moves = []
        for y in range(BOARD_SIZE):
            for x in range(BOARD_SIZE):
                if self.board[y][x] == EMPTY:
                    moves.append((x, y))
        return moves

# 评估函数 - 特征棋谱分数表
# 定义棋型分数 (简单版: 基于连子数和类型)
PIECE_VALUE = {
    1: 10,      # 单子
    2: 100,     # 活二
    3: 1000,    # 活三
    4: 10000,   # 活四
    5: 1000000, # 五连
    # 可以扩展更多棋型如冲四、跳三等
}

def evaluate_board(board, player):
    score = 0
    opponent = 3 - player
    # 检查所有方向的连子
    directions = [(1,0), (0,1), (1,1), (1,-1)]
    for y in range(BOARD_SIZE):
        for x in range(BOARD_SIZE):
            if board[y][x] == player:
                for dx, dy in directions:
                    # 计算连子长度
                    length = 1
                    nx, ny = x + dx, y + dy
                    while 0 <= nx < BOARD_SIZE and 0 <= ny < BOARD_SIZE and board[ny][nx] == player:
                        length += 1
                        nx += dx
                        ny += dy
                    if length >= 2:  # 至少二连
                        # 简单评估: 连子长度分数，乘以位置权重 (中心高)
                        pos_weight = 1 + math.sin(math.pi * (x + 0.5) / BOARD_SIZE) * math.sin(math.pi * (y + 0.5) / BOARD_SIZE)
                        score += PIECE_VALUE.get(length, 0) * pos_weight
    # 减去对手分数
    opp_score = 0
    for y in range(BOARD_SIZE):
        for x in range(BOARD_SIZE):
            if board[y][x] == opponent:
                for dx, dy in directions:
                    length = 1
                    nx, ny = x + dx, y + dy
                    while 0 <= nx < BOARD_SIZE and 0 <= ny < BOARD_SIZE and board[ny][nx] == opponent:
                        length += 1
                        nx += dx
                        ny += dy
                    if length >= 2:
                        pos_weight = 1 + math.sin(math.pi * (x + 0.5) / BOARD_SIZE) * math.sin(math.pi * (y + 0.5) / BOARD_SIZE)
                        opp_score += PIECE_VALUE.get(length, 0) * pos_weight
    score -= opp_score // 2  # 对手威胁减半
    return score

# Minimax with Alpha-Beta Pruning and Depth Limit
def minimax(game, depth, alpha, beta, maximizing_player):
    if depth == 0 or game.game_over or game.is_full():
        return evaluate_board(game.board, BLACK_PIECE if maximizing_player else WHITE_PIECE)

    valid_moves = game.get_valid_moves()
    if not valid_moves:
        return 0

    if maximizing_player:
        max_eval = -float('inf')
        for move in valid_moves:
            x, y = move
            game.make_move(x, y, BLACK_PIECE)
            eval_score = minimax(game, depth - 1, alpha, beta, False)
            game.board[y][x] = EMPTY  # 撤销
            game.current_player = WHITE_PIECE  # 恢复
            max_eval = max(max_eval, eval_score)
            alpha = max(alpha, eval_score)
            if beta <= alpha:
                break
        return max_eval
    else:
        min_eval = float('inf')
        for move in valid_moves:
            x, y = move
            game.make_move(x, y, WHITE_PIECE)
            eval_score = minimax(game, depth - 1, alpha, beta, True)
            game.board[y][x] = EMPTY  # 撤销
            game.current_player = BLACK_PIECE  # 恢复
            min_eval = min(min_eval, eval_score)
            beta = min(beta, eval_score)
            if beta <= alpha:
                break
        return min_eval

def get_best_move(game, depth=3):
    best_score = -float('inf')
    best_move = None
    valid_moves = game.get_valid_moves()
    for move in valid_moves:
        x, y = move
        game.make_move(x, y, game.current_player)
        board_score = minimax(game, depth - 1, -float('inf'), float('inf'), game.current_player == WHITE_PIECE)
        game.board[y][x] = EMPTY
        game.current_player = 3 - game.current_player
        if board_score > best_score:
            best_score = board_score
            best_move = move
    return best_move

# Pygame界面
def draw_board(screen, game):
    screen.fill(BG_COLOR)
    # 画线
    for i in range(BOARD_SIZE + 1):
        pygame.draw.line(screen, LINE_COLOR, (CELL_SIZE * i, 0), (CELL_SIZE * i, BOARD_HEIGHT), 1)
        pygame.draw.line(screen, LINE_COLOR, (0, CELL_SIZE * i), (BOARD_WIDTH, CELL_SIZE * i), 1)
    # 画棋子
    for y in range(BOARD_SIZE):
        for x in range(BOARD_SIZE):
            if game.board[y][x] == BLACK_PIECE:
                pygame.draw.circle(screen, BLACK, (x * CELL_SIZE + CELL_SIZE // 2, y * CELL_SIZE + CELL_SIZE // 2), CELL_SIZE // 2 - 2)
            elif game.board[y][x] == WHITE_PIECE:
                pygame.draw.circle(screen, WHITE, (x * CELL_SIZE + CELL_SIZE // 2, y * CELL_SIZE + CELL_SIZE // 2), CELL_SIZE // 2 - 2)
                pygame.draw.circle(screen, BLACK, (x * CELL_SIZE + CELL_SIZE // 2, y * CELL_SIZE + CELL_SIZE // 2), CELL_SIZE // 2 - 2, 1)

def main():
    global game
    pygame.init()
    screen = pygame.display.set_mode((BOARD_WIDTH + 20, BOARD_HEIGHT + 100))  # 增加高度显示状态
    pygame.display.set_caption("五子棋 - Minimax AI")
    clock = pygame.time.Clock()
    game = Gomoku()

    running = True
    ai_thinking = False
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN and not game.game_over and not ai_thinking:
                if game.current_player == WHITE_PIECE:  # 玩家是白棋，AI是黑棋
                    mx, my = pygame.mouse.get_pos()
                    x = mx // CELL_SIZE
                    y = my // CELL_SIZE
                    if 0 <= x < BOARD_SIZE and 0 <= y < BOARD_SIZE and game.make_move(x, y, WHITE_PIECE):
                        draw_board(screen, game)
                        pygame.display.flip()
                        if not game.game_over:
                            ai_thinking = True
                            # AI回合 (黑棋)
                            best_move = get_best_move(game, depth=3)
                            if best_move:
                                x, y = best_move
                                game.make_move(x, y, BLACK_PIECE)
                            ai_thinking = False
                            draw_board(screen, game)
                            pygame.display.flip()

        draw_board(screen, game)
        # 显示状态
        font = pygame.font.Font(None, 36)
        if game.game_over:
            text = font.render(f"{'黑棋 (AI)' if game.winner == BLACK_PIECE else '白棋 (玩家)'} 获胜!", True, (255, 0, 0))
            screen.blit(text, (10, BOARD_HEIGHT + 10))
        elif game.is_full():
            text = font.render("平局!", True, (0, 0, 255))
            screen.blit(text, (10, BOARD_HEIGHT + 10))
        else:
            player_name = "黑棋 (AI)" if game.current_player == BLACK_PIECE else "白棋 (玩家)"
            text = font.render(f"轮到: {player_name}", True, (0, 0, 0))
            screen.blit(text, (10, BOARD_HEIGHT + 10))
        if ai_thinking:
            think_text = font.render("AI 思考中...", True, (0, 0, 255))
            screen.blit(think_text, (BOARD_WIDTH // 2 - 50, BOARD_HEIGHT + 10))

        pygame.display.flip()
        clock.tick(60)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()