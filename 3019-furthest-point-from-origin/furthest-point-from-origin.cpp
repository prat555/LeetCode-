class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt=0, cnt2=0;
        for (char i:moves){
            if (i=='R') cnt++;
            else if (i=='L') cnt--;
            else cnt2++;
        } return abs(cnt)+cnt2;
    }
};