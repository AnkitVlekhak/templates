class Solution {
public:
    vector<int> lpsfill(int m,vector<int> &p){
        vector<int> lps(m);
        lps[0]=0;
        for(int i=1;i<m;i++){
            int j=lps[i-1];
            while(j>0 && p[j]!=p[i]){
                j=lps[j-1];
            }
            if(p[j]==p[i]){
                j++;
            }
            lps[i]=j;
        }
        return lps;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int n=nums.size(),m=p.size();
        if(m==0)return 0;
        vector<int> lps=lpsfill(m,p);
        int i=0,j=0,ans=0;
        while(i<n){
            int s=nums[i];
            if(s==p[j]){
                i++;j++;
            }else{
                if(j==0)i++;
                else j=lps[j-1];
            }
            if(j==m){
                ans++;
                j=lps[j-1];
            }
        }
        return ans;
    }
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        for(int i=0;i<k-1;i++){
            c.push_back(c[i]);
        }
        string s1="";
        int ans=0;
        for(auto i:c){
            s1+=char(i+48);
        }
        vector<int> k1(k),k2(k);
        int z=0;
        for(int i=0;i<k;i++){
            k1[i]=z;
            k2[i]=!(z);
            z=!z;
        }
        ans=countMatchingSubarrays(c,k1)+countMatchingSubarrays(c,k2);
        return ans;
    }
};
