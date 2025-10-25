class Solution {
public:
    int totalMoney(int n) {
        int k=0, j=0;
        for (int i=1; i<=n; i++){
            j+=1;
            if (i%7==1) j=(i-1)/7+1;
            k+=j;
        } return k;
    }
};