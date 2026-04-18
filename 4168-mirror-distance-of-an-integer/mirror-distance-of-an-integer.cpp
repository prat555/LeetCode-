class Solution {
public:
    int mirrorDistance(int n) {
        int k=0, t=n;
        while (t!=0){
            int r=t%10;
            k=k*10+r;
            t/=10;
        }
        return abs(n-k);
    }
};