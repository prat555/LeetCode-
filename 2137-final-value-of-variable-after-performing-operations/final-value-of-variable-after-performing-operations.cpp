class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for (string y: operations){
            if (y[0]=='+' || y[2]=='+') x+=1;
            else x-=1;
        } return x;
    }
};