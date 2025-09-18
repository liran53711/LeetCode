//
// Created by li on 25-9-12.
//

#ifndef METHORDS_H
#define METHORDS_H


#include <vector>
using namespace std ;
class methords {
public :
    static vector<vector<int>> full_permutation ( vector<int>&elements) ;
    static vector<vector<int>> full_permutation_remove_repetition (vector<int>&elements);


private :
    static void permutation_track_back (const vector<int>&elements,vector<vector<int>>&result,vector<bool>&used,vector<int>&now) ;

};



#endif //METHORDS_H
