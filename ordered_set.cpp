#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> ind;
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n-1][0]=1;//even
        dp[n-1][1]=1;//odd
        int ans=1;
        ordered_set os;
        ind[arr[n-1]]=n-1;
        os.insert(arr[n-1]);

        for(int i=n-2;i>=0;i--){
            int nextsmallestGreater=-1;
            int nextgreatestSmaller=-1;

            int a=os.order_of_key(arr[i]);
            if(a!=0){
                int x=*(os.find_by_order(a-1));
                nextgreatestSmaller=ind[x];
            }
            if(a!=os.size()){
                int x=*(os.find_by_order(a));
                nextsmallestGreater=ind[x];
                if(x==arr[i]){
                    nextgreatestSmaller=ind[x];
                }
            }
            if(nextsmallestGreater>0){
                //odd
                dp[i][1]=dp[nextsmallestGreater][0];
            }
            if(nextgreatestSmaller>0){
                dp[i][0]=dp[nextgreatestSmaller][1];
            }
            if(dp[i][1])ans++;         
            os.insert(arr[i]);
            ind[arr[i]]=i;   
        }
        return ans;
    }
};
