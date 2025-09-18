from typing import List

class solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        size = len(nums)
        if size <= 2 :
            return True
        dp = [[0] * (size +1) for _ in range(size +1)]#represent how much the first can win in the sublist i to j
        for i in range(1,size+1):
            dp[i][i] = nums[i-1]
        for length in range(2, size + 1 ):#because the length of our consizered substring is geroing longger withing the process, when the later come functing using this message , it will always be guare
            for left in range( 1, size - length + 2 ):
                right = left + length - 1

                left_num = nums[left-1]
                left_consequence = dp[left+1][right]
                right_num = nums[right-1]
                right_consequence = dp[left][right-1]
                dp[left][right] = max(left_num - left_consequence, right_num - right_consequence)
        return dp[1][size] >=0





if __name__ == '__main__':
    solution = solution()
    num1 : List[int] = [1,5,2]
    num2 : List[int] = [1,5,233,7]
    print(solution.predictTheWinner(num1))
    print(solution.predictTheWinner(num2))