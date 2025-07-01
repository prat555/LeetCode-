#include <string>

class Solution {
public:
    int possibleStringCount(std::string word) {
        int frequency = 1; 
        for (int i = 1; i < word.size(); ++i) {
            frequency += (word[i] == word[i - 1]);
        }
        return frequency;
    }
};