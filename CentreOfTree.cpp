class Solution {
public:
    pair<int,int> centre(vector<vector<int>>&g,vector<int>&indg){
        queue<int> q;
        int n=g.size();
        for(int i=0;i<n;i++){
            if(indg[i]==1){
                q.push(i);
            }
        }
        int nf=n;
        vector<int> ans_ARR;
        int ans=0;
        while(nf>2){
            int cn=q.size();
            nf-=cn;
            ans++;
            while(cn--){
                int ind=q.front();
                q.pop();
                for(auto child: g[ind]){
                    indg[child]--;
                    if(indg[child]==1){
                        q.push(child);
                    }
                }
            }    
        }
        int o=(nf>1?1:0);
        return {ans+o,2*ans+o};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> g1(edges1.size()+1),g2(edges2.size()+1);
        vector<int> in1(edges1.size()+1),in2(edges2.size()+1);
        for(auto c:edges1){
            g1[c[0]].push_back(c[1]);
            g1[c[1]].push_back(c[0]);
            in1[c[0]]++;
            in1[c[1]]++;
        }
        for(auto c:edges2){
            g2[c[0]].push_back(c[1]);
            g2[c[1]].push_back(c[0]);
            in2[c[0]]++;
            in2[c[1]]++;
        }
        auto [d1,h1]= centre(g1,in1);
        auto [d2,h2]= centre(g2,in2);

        return max(d1+d2+1,max(h1,h2));
    }
};
