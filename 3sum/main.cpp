#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(  nums );

        int first ,second ,third;
        for ( first ; first<nums.size();first++) {


        }

    }

   void  sort ( vector<int>& nums ) {
        
    }
};

int main() {

    vector<vector<int>> nums = {{-1,0,1,2,-1,-4},{0,1,1},{0,0,0}};
    vector<vector<vector<int>>> outs;
    int i= 0;
    Solution().sort(nums[0]);
    for ( vector <int>  num : nums ) {
        outs.push_back(Solution().threeSum(num));
    }

}