#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1) {
        vector<int>nums2(nums1.begin(), nums1.end());
        for (int num : nums1) {
            nums2.push_back(num);
        }
        unordered_map<int,int> next_map;//number,distance from next bigger;
        stack <pair < int ,int >> stack;//value,index;
        int total_size = nums1.size();
        for ( int i=0 ;i<total_size;i++) {
            next_map[nums2[i]] = -1;
            while ( !stack.empty() && stack.top().first < nums2[i] ) {
                next_map[stack.top().first] = nums2[i];
                stack.pop();
            }
            stack.push({nums2[i],i});
        }
        vector<int>result;
        for ( int request : nums1) {
            result.push_back(next_map[request]);
        }
        return result;
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {1,2,1},nums2 = {1,2,3,4};
    vector<int> result1 = solution.nextGreaterElement(nums1);
    for (int result :  result1) {
        printf("%d",result);
    }
}
