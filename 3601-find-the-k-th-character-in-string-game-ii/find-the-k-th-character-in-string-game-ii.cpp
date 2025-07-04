class Solution {
    #define ll long long
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int count_ops=0;
        ll val = k;
        while(val>1){
            int jumps = ceil(log2(val));
            val -= pow(2,jumps-1);
            count_ops += operations[jumps-1];
        }
        return char('a'+(count_ops%26));
    }
};