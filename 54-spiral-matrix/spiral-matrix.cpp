class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int le=0, ri=matrix[0].size()-1, top=0, bot=matrix.size()-1;
        vector<int> ans;
        while (top<=bot && le<=ri){
            for (int i=le; i<=ri; i++) ans.push_back(matrix[top][i]);
            top++;
            for (int i=top; i<=bot; i++) ans.push_back(matrix[i][ri]);
            ri--;
            if (top<=bot)
                for (int i=ri; i>=le; i--) ans.push_back(matrix[bot][i]);
            bot--;
            if (le<=ri)
                for (int i=bot; i>=top; i--) ans.push_back(matrix[i][le]);
            le++; 
        } return ans;
    }
};