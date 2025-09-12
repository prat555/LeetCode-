class Solution {
public:
    bool doesAliceWin(string s) {
        const string vow= "aeiou";
        for (char c:s){
            if (vow.find(c)!= string::npos) return true;
        } return false;
    }
};