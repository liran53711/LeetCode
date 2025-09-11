#include <iostream>
#include <vector>
#include "Solution.h"

int main() {


     std :: vector <int> nums1 = {1,2};
     std :: vector <int> nums2 = {3,4};
    Solution solution;
     std :: cout << solution.findMedianSortedArrays(nums1, nums2 ) << std::endl;


    return 0;
}