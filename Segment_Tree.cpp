class NumArray {
public:
    int seg[4*30001];
    void update(int node,int low,int high,int pos,int val){
        if(low==high){
            seg[node]=val;
        }
        else{
            int mid=(low+high)/2;
            if(pos>=low && pos<=mid){
                update(2*node+1,low,mid,pos,val);
            }else{
                update(2*node+2,mid+1,high,pos,val);
            }
            seg[node]=seg[2*node+1]+seg[2*node+2];
        }
    }
    void build(vector<int> &nums,int node,int low,int high){
        if(low==high){
            seg[node]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(nums,2*node+1,low,mid);
        build(nums,2*node+2,mid+1,high);
        seg[node]=seg[2*node+1]+seg[2*node+2];
    }
    int query(int node,int low,int high,int l,int r){
        if(r<low|| high<l){
            return 0;
        }
        else if(low>=l && high<=r){
            return seg[node];
        }
        else{
            int mid=(low+high)/2;
            int left=query(2*node+1,low,mid,l,r);
            int right=query(2*node+2,mid+1,high,l,r);
            return left+right;
        }
    }
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        memset(seg,0,sizeof(seg));
        build(nums,0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
