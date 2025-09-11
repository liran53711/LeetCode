#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea1(vector<int>& height) {//暴力枚举，会增加很多无用的枚举
        int right = 1,maxNum = 0 ;
        while ( right < height.size() ) {
            for ( int left  = 0 ; left < right ; left ++) {
                int pre = min(height[left],height[right]) * (right - left);
                maxNum = max(maxNum,pre);
            }
            right ++;
        }
        return maxNum;
    }


    int maxArea(vector<int>& height){//正确做法，双指针从两边向中间逼近，每一次移动一条边
                                       //移动的过程中遵循贪心原则，总是优先行对容积正向的移动

        int left = 0 , right = height.size()-1 ,maxNum = 0 ;
        while ( left < right ) {
            int pre = min(height[left],height[right]) * (right - left);
            maxNum = max(maxNum,pre);

            if (height[left] < height[right] ) {
                left ++;
            }else {
                right --;
            }
        }
return maxNum;
    }
};



int main() {

    vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    vector<int>v2 = {1,2,3,4};

    cout << Solution().maxArea(v1) << endl;
    cout << Solution().maxArea(v2) << endl;

}