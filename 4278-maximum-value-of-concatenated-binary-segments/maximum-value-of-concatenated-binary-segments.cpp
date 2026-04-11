class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n=nums1.size();
        vector<int> st;
        for (int i=0; i<n; i++) st.push_back(i); //indexes le liya
        sort(st.begin(),st.end(),[&](int x,int y){
            string sx=string(nums1[x],'1')+string(nums0[x],'0');
            string sy=string(nums1[y],'1')+string(nums0[y],'0');
            return sx+sy>sy+sx;
        });
        long long cnt=0;
        long long mod=1000000007;
        for (int k=0; k<n; k++){
            int i=st[k];
            for (int j=0; j<nums1[i]; j++) cnt=(cnt*2+1)%mod;
            for (int j=0; j<nums0[i]; j++) cnt=(cnt*2)%mod;
        } return cnt;
    }
};