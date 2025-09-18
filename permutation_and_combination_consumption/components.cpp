//
// Created by li on 25-9-12.
//

#include "components.h"

long long int components::factorial(int end, int begin) {
    long long int result = 1;
    for (int i = begin; i <= end; i++) {
        result *= i;
    }
    return result ;
}

long long int components::factorial(int end) {
    long long int result = 1;
    for (int i = 1; i <= end; i++) {
        result *= i;
    }
    return result ;
}

void components::heapsPermutate(vector<int> &nums, int n, vector<vector<int> > &result) {
    if ( n==1 ) {
        result.push_back(nums);
        return;
    }
    for ( int i=0 ; i<n; i++) {
        heapsPermutate(nums, n-1, result);
        if ( n%2 == 0 ) {
            swap(nums[i],nums[n-1]);
        }else {
            swap(nums[0],nums[n-1]);
        }
    }
}


