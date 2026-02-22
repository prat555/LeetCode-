class Solution {
public:
    int binaryGap(int n) {
        int maxi=0, curr=0, prev=100;
        while (n!=0){
            if (n & 1){
                maxi=max(maxi, curr-prev);
                prev=curr;
            } ++curr;
            n>>=1;
        } return maxi;
    }
};