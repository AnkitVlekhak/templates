class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> m1,m2;
        for(auto c:nums1){
            m1.insert(c);
        }
        for(auto c:nums2){
            m2.insert(c);
        }
        vector<int>v;
        std::set_intersection(m1.begin(),m1.end(),m2.begin(),m2.end(),std::inserter(v,v.begin()));
        return v;
    }
};
