class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int sequenceLength = 1 << n;
        
        for (int i = 0; i < sequenceLength; ++i) {
            result.push_back(i ^ (i >> 1));
        }
        
        return result;
    }
};