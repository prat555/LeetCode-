class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans= 0;
        for (const vector<int>& a: points){
            for (const vector<int>& b: points){
                for (const vector<int>& c: points){
                    ans = max(ans, 0.5 * abs((b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1])));
                }
            }
        } return ans;
    }
};