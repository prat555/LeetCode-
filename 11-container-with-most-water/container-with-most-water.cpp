class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, na=0;
        while (l<r){
            int ca=(r-l)*min(height[r],height[l]);
            na=max(na,ca);
            if (height[l]<height[r]) l++;
            else r--;
        } return na;
    }
};