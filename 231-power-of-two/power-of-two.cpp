class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n>1 && n%2==0){
            n/=2;
        }
        if (n==1){
            return true;
        } else{
            return false;
        }
    }
};