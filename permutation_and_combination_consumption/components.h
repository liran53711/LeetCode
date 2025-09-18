//
// Created by li on 25-9-12.
//

#ifndef COMPONENTS_H
#define COMPONENTS_H
#include <vector>

using namespace  std;
class components {

public :
    static long long int factorial(int end ,int begin);
    static long long int factorial(int end);
    static void heapsPermutate(vector<int>& nums,int n,vector<vector<int>>&result);

};



#endif //COMPONENTS_H
