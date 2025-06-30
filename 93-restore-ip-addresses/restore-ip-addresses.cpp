#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> validIPs;
        vector<string> currentIP;
        
        function<void(int)> dfs = [&](int index) {
            if (index == s.size() && currentIP.size() == 4) {
                validIPs.push_back(currentIP[0] + "." + currentIP[1] + "." + currentIP[2] + "." + currentIP[3]);
                return;
            }
            if (index >= s.size() || currentIP.size() >= 4) {
                return;
            }
            
            for (int j = index; j < min((int)s.size(), index + 3); ++j) {
                string segment = s.substr(index, j - index + 1);
                int value = stoi(segment);
                
                if (value > 255 || (segment.size() > 1 && segment[0] == '0')) {
                    break;
                }
                
                currentIP.push_back(segment);
                dfs(j + 1);
                currentIP.pop_back();
            }
        };
        
        dfs(0);
        return validIPs;
    }
};