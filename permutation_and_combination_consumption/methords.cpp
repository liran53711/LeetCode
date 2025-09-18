//
// Created by li on 25-9-12.
//

#include "methords.h"
#include "components.h"


vector<vector<int> > methords::full_permutation(vector<int>& elements) {
    vector<vector<int> > result = {};
    int size = elements.size();
    if ( size ==0 )return result;
    ranges::sort(elements.begin(), elements.end());
    int prem_size = components::factorial(size);
    //result.resize(prem_size);
    components::heapsPermutate(elements,size,result);
    return result;
}
/*
 * 第一个实现的是不考虑重复元素的全排列，使用的是heaps算法，
 * 1.实现思路：
 *   1.1.原地交换元素
 *   1.2.对于每一次进入循环，先对的最后一个元素之前的元素递归实现全排列，然后运用交换策略使得每一个前置的元素都有机会被放到末尾
 *
 * 2.总之这个算法比较难想，需要记忆
 */

vector<vector<int>> methords::full_permutation_remove_repetition(vector<int>& elements) {
    int size = elements.size();
    if ( size == 0 ) return {};
    ranges::sort ( elements.begin(), elements.end() );
    vector<vector<int> > result ;
    vector<bool> used(size,false);
    vector<int> present;
    methords::permutation_track_back(elements,result,used,present);


}




void methords::permutation_track_back(const vector<int> & elements, vector<vector<int> > &result, vector<bool> &used, vector<int> &now) {
    if ( now.size() == elements.size() ) {
        result.push_back(now);
        return;
    }

    for ( int i=0 ;i<elements.size();i++ ) {
        //最关键的一行
        if (used[i] || i>0 && !used[i-1] && elements[i-1]==elements[i]) continue;
        used[i]=true;
        now.push_back(elements[i]);
        permutation_track_back(elements,result,used,now);

        now.pop_back();
        used[i]=false;
    }

}






