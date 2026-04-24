class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int k=arr[n-1],b;
        for (int i=n-2; i>=0; i--){
            k=max(k,b);
            b=arr[i];
            arr[i]=k;
        } arr[n-1]=-1;
        return arr;
    }
};