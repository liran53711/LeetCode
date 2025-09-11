
#include <vector>

#ifndef SOLUTION_H
#define SOLUTION_H

using namespace std;



class Solution {
public: double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if ( nums1.size() >nums2.size() ) return findMedianSortedArrays(nums2, nums1);

    int m=nums1.size();
    int n=nums2.size();

    int totalLeft = (m+n+1)/2; //when total is even, it is half, when total is odd, the left is bigger
    int left = 0 ;
    int right = m;
    while ( left <= right ) {
        int i = left + (right -left )/2;
        int j = totalLeft -i;

        int aLeft = i<=0 ? INT_MIN : nums1[i-1];
        int aRight = i>=m ? INT_MAX : nums1[i];
        int bRight = j>=n ? INT_MAX : nums2[j];
        int bLeft = j<=0 ? INT_MIN : nums2[j-1];

        if ( aLeft <= bRight &&  aRight >= bLeft ) {
            if (( m+n )%2 == 0 ) return (max( aLeft, bLeft ) + min( aRight, bRight )) / 2.0;
            else return (double)max( aLeft, bLeft );
        }else if (aLeft > bRight) {
            right = i-1;
        }else left = i+1;

    }




return 0.0;

}

//     if ( nums1.size()==0 ) {
//         return nums2.size()%2==0 ? (double)((nums2[nums2.size()/2] + nums2[nums2.size()/2-1])/2.0) : nums2[nums2.size()/2];
//     }
//     if ( nums2.size()==0 ) {
//         return nums1.size()%2==0 ? (double)((nums1[nums1.size()/2] + nums1[nums1.size()/2-1])/2.0) : nums1[nums1.size()/2];
//     }
//
//
//
//     vector<int> (&smaller) = nums1[0] >=  nums2[0] ? nums2 : nums1;
//     vector<int> (&bigger) =  nums1[0] < nums2[0] ? nums2 : nums1;
//
//
//     int s = smaller.size();
//     int b = bigger.size();
//
//     bool even = (s+b) % 2 == 0;
//     int left_numbers;
//
//      if ( even ) {
//          left_numbers  = ( s + b ) /2;
//     //     if ( smaller[s-1] < bigger[0] ) {//specially the two have been sorted;
//     //         return s >= left_numbers ? smaller[left_numbers -1] : bigger[left_numbers - s -1];
//     //     }
//     //
//      }else {
//           left_numbers =  ( s + b ) /2 + 1;
//     //     if ( smaller[s-1] < bigger[0] ) {//specially the two have been sorted;
//     //         return s >= left_numbers ? smaller[left_numbers -1] : bigger[left_numbers - s -1];
//     //     }
//      }
//
//     int des_left = 0 ;
//     int des_right = s;
//     while ( des_left < des_right ) {
//         int left_in_1 = (des_left + des_right) / 2;
//         int left_in_2 = left_numbers-2 - left_in_1;
//
//         int left_in_1_value =  smaller[left_in_1];
//         int right_in_1_value = left_in_1 + 1 >= s ? INT_MAX : smaller[left_in_1 + 1];
//         int left_in_2_value = left_in_2 >=0 ? bigger[left_in_2]:INT_MIN;
//         int right_in_2_value = left_in_2 + 1 < b ? bigger[left_in_2 + 1]:INT_MAX;
//
//         if (left_in_1_value <= right_in_2_value && right_in_1_value >= left_in_2_value) {
//             if ( even ) {
//                 return (double)(max(left_in_1_value, left_in_2_value) + min(right_in_1_value, right_in_2_value))/2.0;
//             } else return max ( left_in_1_value ,  left_in_2_value );
//         }else if (left_in_1_value > right_in_2_value ) {
//             des_right = left_in_1;
//         }else if (right_in_1_value < left_in_2_value ) {
//             des_left = left_in_1;
//         }
//     }
//
// }
//
//
//
//






// public: double findMedianSortedArrays_abandon(vector<int>& nums1, vector<int>& nums2) {
//         int m=nums1.size();
//         int n=nums2.size();
//
//     vector<int> result;
//     int ptr1 = 0 ;
//     int ptr2 = 0 ;
//
//     bool even = ( m + n )%2 ==0;//m=2,n=2,limit = 2 ; m=1 ,n=2 , limit = 1;
//     int limit = (m+n)/2;
//
//     while ( (ptr1 < m || ptr2 < n) && ptr1 + ptr2 <= limit ) {
//
//         if ( ptr1 == m ) {
//             result.push_back(nums2[ptr2]);
//             ptr2 ++;
//             continue ;
//         }
//         if ( ptr2 == n ) {
//             result.push_back(nums1[ptr1]);
//             ptr1 ++;
//         }
//
//         if (  nums1[ptr1] < nums2[ptr2] ) {
//             result.push_back(nums1[ptr1]);
//             ptr1 ++;
//         }else {
//             result.push_back(nums2[ptr2]);
//             ptr2 ++;
//         }
//     }
//
//     return even ? (result[limit] + result[limit-1])/2.0 :  result[limit];
//
//
//
//
//
//     }
//














};



#endif //SOLUTION_H
