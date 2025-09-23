#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void print_matrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> matrix_of_special_order;
        int top = 0 ,bottom =matrix.size()-1,left=0,right = matrix[0].size()-1;//use 4 numbers to represent the size change with the printing process
        while (top <=bottom && left <=right) {//circle once, print the outer 4 edges
            for ( int i=left;i<=right;i++) {
                matrix_of_special_order.push_back(matrix[top][i]);
            }
            top++;
            for (int i=top;i<=bottom;i++) {
                matrix_of_special_order.push_back(matrix[i][right]);
            }
            right--;
            for (int i=right;i>=left&&top <=bottom;i--) {
                matrix_of_special_order.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i=bottom;i>=top&&left <=right;i--) {
                matrix_of_special_order.push_back(matrix[i][left]);
            }
            left++;

        }
        return matrix_of_special_order;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix = vector<vector<int>>(n,vector<int>(n));
        int top = 0,bottom =  matrix.size()-1,left = 0,right = matrix[0].size()-1;

        for ( int i = 1 ;i <= n*n;) {
            for ( int j= left ;  j <= right && top <=bottom; j++) {
                matrix[top][j] = i++;
            }
            top++;
            for ( int j= top;j <= bottom && left <=right; j++) {
                matrix[j][right] = i++;
            }
            right--;
            for ( int j=right;j>=left&&top<=bottom;j--) {
                matrix[bottom][j] = i++;
            }
            bottom--;
            for ( int j = bottom;j>=top && left <=right ; j--) {
                matrix[j][left] = i++;
            }
            left++;
        }

        return matrix;
    }

    void rotate(vector<vector<int>>& matrix) {//顺时针旋转90度的操作可以通过转置加上对应列交换来实现，同理180度270度。

        for ( int i=0 ;i<matrix.size();i++) {
            for ( int j=i+1;j<matrix[i].size();j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i=0 ;i<matrix[0].size()/2;i++) {
            for ( int j=0;j<matrix.size();j++) {
                swap(matrix[j][i],matrix[j][matrix.size()-1-i]);
            }
        }
    }



        bool searchMatrix(vector<vector<int>>& matrix, int target) {//具有严格单调的性质，所以直接作为一个整体使用二分法
            if (matrix.empty() || matrix[0].empty()) return false;

            int m = matrix.size();
            int n = matrix[0].size();
            int left = 0;
            int right = m * n - 1;  // 修正：索引从0到m*n-1

            while (left <= right) {
                int mid = left + (right - left) / 2;
                int row = mid / n;  // 修正：直接计算行
                int col = mid % n;  // 修正：直接计算列

                if (matrix[row][col] == target) {
                    return true;
                } else if (matrix[row][col] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            return false;  // 修正：直接返回false，不需要额外检查
        }




/*1.先插入排序然后再二分查找，时间复杂度是mnlog2（mn)
 *2.先筛选合适的行然后再在行内二分查找，2mlog2n
 *3.最好的办法，z字形查找，从右上角开始，如果目标大，说明当前的行不行，就下移一行，如果目标小了，说明当前的列不行，左移一列*/

    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() || matrix[0].empty()) return false;
        int row = 0, rows = matrix.size();
        int col = matrix[0].size()-1;
        while ( row <rows || col >= 0 ) {
            if ( matrix[row][col]==target)
                return true;
            else if ( matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }


    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        int right_min,down_min;
        vector<vector<int>> dp(row + 1 ,vector<int>(col+1));
        for ( int i= col ; i >=0 ;i--) {
            for ( int  j = row ; j >=0 ;j--) {//从右下角向上，结束一列之后向左一列
                if (j==row &&  i==col) {
                    dp[j][i] = grid[j][i];
                    continue;
                }
                if ( j== row)down_min = INT32_MAX;
                else down_min = dp[j+1][i] ;
                if ( i== col)right_min = INT32_MAX;
                else right_min = dp[j][i+1];
                dp[j][i] = min(down_min,right_min) + grid[j][i];
            }
        }
        return dp[0][0];
    }
    };

int main() {


    Solution solution;
    vector<vector<int>> matrix =solution.generateMatrix(5);
    vector<int> result = solution.spiralOrder(matrix);

    solution.print_matrix(matrix);

    solution.rotate(matrix);
    solution.print_matrix(matrix);

    vector<vector<int>> empty_matrix  = {{1}};
    bool exist = solution.searchMatrix(empty_matrix,1);
    vector<vector<int>> matrix2 = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    exist = solution.searchMatrix2(matrix2,6);
    cout << solution.minPathSum(matrix2) << endl;
    cout << exist << '\n'<<'\n';

    for(auto x : result) {
        cout << x << " ";
    }

}