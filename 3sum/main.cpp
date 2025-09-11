#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums );
        //remove_repeat_nums(nums);
        int first ,second ,third;
        vector<vector<int>> valids;
        int size = nums.size();
        for ( first = 0 ; first < size -2 && nums[first] <=0 ; first ++) {
            int fir_val = nums[first];
             second = first + 1 ;
             third = nums.size() -1;
            while ( second < third ) {
                int se_val = nums[second],thi_val = nums[third];
                if ( fir_val + se_val + thi_val == 0) {
                    vector<int> valid;
                    valid.push_back(fir_val);
                    valid.push_back(se_val);
                    valid.push_back(thi_val);
                    valids.push_back(valid);

                    while ( nums[second + 1]==nums[second])second ++;
                    second ++ ;
                    while ( nums[third -1 ]==nums[third])third --;
                    third -- ;
                }else if (  fir_val + se_val + thi_val > 0 ) {
                    while ( nums[third -1 ]==nums[third])third --;
                    third--;
                }else {
                    while ( nums[second + 1]==nums[second])second ++;
                    second ++;
                }

            }
            while ( nums[first + 1] == nums[first] && first < size - 3 )first ++ ;


        }
        return valids;

    }

   void  sort ( vector<int>& nums ) {
        quickSort( nums, 0, nums.size()-1 );
    }

private:

    // void remove_repeat_nums(vector<int>& nums) {
    //     vector<int>new_nums;
    //     int prev=nums[0];
    //     new_nums.push_back(prev);
    //     for ( int i = 1; i < nums.size(); i++ ) {
    //         if ( nums[i] != prev ) {
    //             new_nums.push_back( nums[i] );
    //             prev = nums[i];
    //         }
    //     }
    //     nums = new_nums;
    // }


    void quickSort( vector<int>&nums ,int left ,int right) {
        if ( left >= right )return;
        int departure = partition(nums,left,right);
        quickSort(nums,left,departure-1);
        quickSort(nums,departure+1,right);

    }

    int  partition(vector<int>&nums, int left ,int right) {
        int pivot = nums[left];
        int i = right + 1 ;
        int j;
        for (  j= right;j >= left ; j-- ) {
            if ( nums[j] > pivot) {
                i--;
                swap ( nums[i],nums[j]);
            }
        }
        swap ( nums[i-1],nums[left]);

        return i-1;
    }


};

int main() {

    vector<vector<int>> nums = {{-1,0,1,2,-1,-4},{0,1,1},{0,0,0}};
    vector<vector<vector<int>>> outs;
    int i= 0;
    // Solution().sort(nums[0]);
    // Solution().sort(nums[1]);
    // Solution().sort(nums[2]);
    for ( vector <int>  num : nums ) {
        outs.push_back(Solution().threeSum(num));
    }




}