from solution_class import Solution


def test():
    solution = Solution()
    nums1 = [1,2,1]
    result1=solution.nextGreaterElements(nums1)
    expected1=[2,-1,2]
    assert result1 == expected1,f"Test failed: expect {expected1}, got {result1}"
    print("test passed")

    nums2 = [2,1,5,6,2,3]
    result2 = solution.largestRectangleArea(nums2)
    expected2 = 10
    assert result2 == expected2,f"Test failed: expect {expected2}, got {result2}"
    print("test passed")

    matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    result3 = solution.maximalRectangle(matrix)
    expected3 = 6
    assert result3==expected3,f"Test failed: expect {expected3}, got {result3}"
    print("test passed")
