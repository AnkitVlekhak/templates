class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> flip(nums.size(),0);
        int ans=0,flips=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>=n-k+1){
                if((nums[i]==1 && flips%2==0 ) || (nums[i]==0 && flips%2==1 )){
                    flips-=flip[i];
                }else{
                    return -1;
                }
                continue;
            }
            if((nums[i]==1 && flips%2==1 ) || ( nums[i]==0 && flips%2==0 ) ){
                ans++;
                flips++;
                flip[i+k-1]++;
            }
            flips-=flip[i];
        }
        return ans;
    }
};
