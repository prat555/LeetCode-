class Solution {
public:
    int dg(int k){
        int s=0;
        while (k>0){
            s+=k%10;
            k/=10;
        } return s;
    }
    int minElement(vector<int>& nums) {
        int p=INT_MAX;
        for (int x:nums) p=min(p,dg(x));
        return p;
    }
};