class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101]={0};
        for (int num:nums){
            ++freq[num];
        }
        int totco=0;
        int maxfreq=-1;
        for (int fr:freq){
            if (maxfreq<fr){
                maxfreq=fr;
                totco=fr;
            } else if (maxfreq==fr) totco+=fr;
        } return totco;
    }
};