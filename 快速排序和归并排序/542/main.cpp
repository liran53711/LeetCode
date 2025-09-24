#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        if (row == 0) return {};
        int col = mat[0].size();
        int max_dist = row + col; // 最大可能距离（矩阵对角线长度）

        vector<vector<int>> dist(row, vector<int>(col, max_dist));

        // 第一次遍历：左上角 -> 右下角（处理上方和左方）
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }
        }

        // 第二次遍历：右下角 -> 左上角（处理下方和右方）
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (i < row - 1) dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                if (j < col - 1) dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
            }
        }

        return dist;
    }
};



int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
    Solution solution;
    vector<vector<int>> new_mat = solution.updateMatrix(mat);
    return 0;
}