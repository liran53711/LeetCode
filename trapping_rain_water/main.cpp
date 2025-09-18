#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {

        int max_trap =0 ;
        stack<pair<int,int>> volume;//height,pointer
        for(int i=0;i<height.size();i++) {
            while ( volume.size() > 0 && height[i] > volume.top().first ) {
                int bottom = volume.top().first;
                while (!volume.empty() && volume.top().first == bottom) {
                    volume.pop();
                }
                if ( !volume.empty() ){
                    int top = min(volume.top().first,height[i]);
                    int length = i - volume.top().second-1;
                    max_trap += (top-bottom)*length;
                }

            }
            volume.push(make_pair(height[i],i));
        }
        return max_trap;
    }
};
int main() {
    vector<int>height1 ={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int>height2 ={4,2,0,3,2,5};
    Solution s;
    printf("%d %d",s.trap(height1),s.trap(height2));
}