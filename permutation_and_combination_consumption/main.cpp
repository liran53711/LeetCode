#include<iostream>
#include"methords.h"
#include<vector>


int main() {
 vector<int> v = {1,2,3,4,5,6,7,8,9,10};
 vector<vector<int>> vec = methords::full_permutation(v);
 vector<int>v2 = {1,6,2,2,2,3,8,3,3,4,5};
 vector<vector<int>> vec2 = methords::full_permutation_remove_repetition(v2);

}