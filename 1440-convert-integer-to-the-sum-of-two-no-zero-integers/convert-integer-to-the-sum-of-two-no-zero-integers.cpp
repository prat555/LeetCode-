class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int firstNum = 1; ; ++firstNum) {
            int secondNum = n - firstNum;
            string combinedStr = to_string(firstNum) + to_string(secondNum);

            if (combinedStr.find('0') == string::npos) {
                return {firstNum, secondNum};
            }
        }
    }
};