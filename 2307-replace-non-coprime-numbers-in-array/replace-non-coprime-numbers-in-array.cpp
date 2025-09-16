class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for (int currentNum : nums) {
            stack.push_back(currentNum);
            while (stack.size() > 1) {
                int topElement = stack.back();
                int secondElement = stack[stack.size() - 2];
                int gcd = __gcd(topElement, secondElement);
                if (gcd == 1) {
                    break;
                }
                stack.pop_back();
                stack.back() = 1LL * topElement * secondElement / gcd;
            }
        }
        return stack;
    }
};
