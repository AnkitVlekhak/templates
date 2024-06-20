int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=0,high=position.back();
        while(low<=high){
            int mid=low+(high-low)/2;
            int dis=0,k=1;
            for(int i=1;i<n;i++){
                dis+=position[i]-position[i-1];
                if(dis>=mid){
                    dis=0;
                    k++;
                }
            }
            if(k<m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return high;
    }
