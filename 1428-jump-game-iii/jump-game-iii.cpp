class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // Base case 1: out of bounds
        if (start < 0 || start >= arr.size() || arr[start] < 0)
            return false;

        // Base case 2: we found an index with value 0
        if (arr[start] == 0)
            return true;

        // Mark this index as visited by making the value negative
        arr[start] = -arr[start];

        // Try both jumps: forward and backward
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};
