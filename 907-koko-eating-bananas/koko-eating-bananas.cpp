class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high=*max_element(piles.begin(),piles.end()), ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (itna(piles,mid)<=h){
                ans=mid;
                high=mid-1;
            } else low=mid+1;
        } return ans;
    }
private:
    long long itna(vector<int>& piles, int i){
        long long ghanta=0;
        for (int x:piles) ghanta+=(x+i-1)/i;
        return ghanta;
    }
};