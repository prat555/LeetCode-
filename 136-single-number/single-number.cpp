class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=0;
        for (int x: nums) n^=x;
        return n;
    }
};