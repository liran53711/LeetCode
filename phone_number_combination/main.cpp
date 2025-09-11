#include <vector>
#include<iostream>
using namespace std;
class Solution {
public :vector<string> letterCombinations(string digits) {
    vector < string > result  = {""};
    if ( digits.length() == 0 )return {};
    unordered_map < char , string > mapper  = {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"nmo"},{'7',"pqrs"},
    {'8',"tuv"},{'9',"wxyz"}};

    vector<string> prev;
    for ( char num :digits ) {
        string store = mapper[num];
        for ( string need_lengthen : result ) {
            for ( char to_add : store ) {
                string now = need_lengthen+to_add;
                prev.push_back(now);
            }
        }
        result = prev;
        prev.clear();
    }


return result;
}
};

int main() {
    string digits = "23";
    Solution solution;
    vector<string> result = solution.letterCombinations(digits);
    for ( string str : result ) {
        cout << str + " ";
    }
}