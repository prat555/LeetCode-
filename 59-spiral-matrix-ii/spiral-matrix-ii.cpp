class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int k=1, le=0, ri=n-1, bot=n-1, top=0;
        vector<vector<int>> ans(n,vector<int>(n));
        while (k<=n*n){
            for (int i=le; i<=ri; i++) 
                ans[top][i]=k++;
                top++;
            if (top>bot) break;
            for (int i=top; i<=bot; i++)
                ans[i][ri]=k++;
                ri--;
            if (k>n*n) return ans;
            for (int i=ri; i>=le; i--)
                ans[bot][i]=k++;
                bot--;
            if (k>n*n) return ans;
            for (int i=bot; i>=top; i--)
                ans[i][le]=k++;
                le++;
        } return ans;
    }
};