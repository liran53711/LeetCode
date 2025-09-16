
class Solution(object):
    def nextGreaterElements(self,nums):
        n=len(nums)
        result=[-1]*n
        stack = []
        for i in range(2*n):
            if i>=n:
                index = i-n
            else:
                index = i

            num = nums[index]

            while stack and num > nums[stack[-1]]:
                result[stack[-1]] = num
                stack.pop()

            if i<n:
                stack.append(i)

        return result

    def largestRectangleArea(self, heights):
        n=len(heights)
        uncalculated= []
        uncalculated.append(-1)
        max_area = 0
        for i in range(n):
            while len(uncalculated)!=1 and heights[uncalculated[-1]]>heights[i]:
                height = heights[uncalculated[-1]]
                uncalculated.pop()
                length = i-uncalculated[-1]-1
                max_area = max (max_area,length*height)
            uncalculated.append(i)
        while len(uncalculated ) > 1  :
            right = n
            height = heights[uncalculated[-1]]
            uncalculated.pop()
            length = right-uncalculated[-1]-1
            max_area = max(max_area,length*height)
        return max_area

    def maximalRectangle(self, matrix):
        column_number = len(matrix[0])
        row_number = len(matrix)
        max_area =0
        for bottom in range(column_number):
           heights = [0]*row_number
           for i in range(row_number):
               index = bottom
               while index < column_number and matrix[i][index]=='1':
                   heights[i]+=1
                   index += 1
           max_of_bottom = self.largestRectangleArea(heights)
           max_area = max(max_area,max_of_bottom)
        return max_area













