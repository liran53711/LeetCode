#include <iostream>

using namespace std;
class Solution {
public:

    //中心扩展法
    string longestPalindrome(string s) {
        int n=s.length();
        int center_left = 0 ;
        int center_right = 0 ;
        string palindrome = "";
        string pre = "";
        while ( center_right < n ) {
            for (int i=0 ; i<min( center_left  + 1 , n-center_right ) ;i++) {
                    if ( s.at(center_left -i) == s.at(center_right + i)) {
                        pre = s.substr(center_left-i,center_right + i - center_left  + i + 1);
                    }else break;
                }

            if ( pre.length() > palindrome.length() ) {
                palindrome = pre;
            }

            if ( center_left == center_right )center_right ++;
            else center_left ++;

            pre = "";

        }

        return palindrome;
    }
//动态规划
    string dynamic(string s) {


        vector<vector<bool>> dp(s.size(),vector<bool>(s.length(),false));

        int left_pointer,right_pointer;
        int max_len = 0 ;
        for ( int i= 0 ;i<s.length();i++) {//i represents the right pointer;
            for ( int j= 0 ; j<=i ;j++) {//j represents the left pointer;
                if ( i==j )dp[i][j]=true;
                else if (i == j+1 )dp[i][j]= s.at(i)==s.at(j);
                else dp[i][j]=dp[i-1][j+1] && s.at(i)==s.at(j);

                if ( dp[i][j] && i-j+1 > max_len) {
                    max_len = i-j+1;
                    left_pointer = j ;
                    right_pointer = i ;
                }


            }
        }

        return s.substr(left_pointer,right_pointer-left_pointer+1);
    }

};


int main() {

    string s1 = "aa";
    string re1 = "aa";

    string s2 = "asdfghjklkjybrvcexw";
    string re2 = "jklkj";

    string s3 = "asdfghjkllkjybrvcexw";
    string re3 = "jkllkj";

    string s4 = s3.substr(2,3);

    string s[] = {s1,s2,s3};
    string re[] = {re1,re2,re3};

    string str = Solution().dynamic(s2);
    string str1  = Solution().dynamic(s1);
    string str2  = Solution().dynamic(s2);
    string str3  = Solution().dynamic(s3);


    for (int i= 0 ;i<sizeof(s)/sizeof(string);i++) {
        cout << (Solution().longestPalindrome(s[i]) == re[i])<< endl;
    }

    return 0;
}