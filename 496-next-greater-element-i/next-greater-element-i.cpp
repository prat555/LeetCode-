class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int n1 : nums1) {
            int nextGreater = -1;

            for (int i = 0; i < nums2.size(); i++) {
                if (nums2[i] == n1) {
                    // check elements to the right
                    for (int j = i + 1; j < nums2.size(); j++) {
                        if (nums2[j] > n1) {
                            nextGreater = nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};