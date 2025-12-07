class Solution {
public:
    int countOdds(int low, int high) {
        int k=0;
        for (int i=low; i<high+1; i++){
            if (i%2!=0) k++;
        } return k;
    }
};