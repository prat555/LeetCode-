class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size(), ans=0;
        for (int i=0; i<n-1; i++){
            if (colors[i]!=colors[0]) ans=max(ans,i);
            if (colors[i]!=colors[n - 1]) ans=max(ans, n-1-i);
        } return ans;
    }
};