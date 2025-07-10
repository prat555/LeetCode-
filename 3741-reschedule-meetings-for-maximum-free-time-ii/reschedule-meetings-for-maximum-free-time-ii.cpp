class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int maxFreeTime = 0;

        vector<int> leftGaps(n, 0);
        leftGaps[0] = startTime[0];
        for (int i = 1; i < n; ++i) {
            leftGaps[i] = max(leftGaps[i - 1], startTime[i] - endTime[i - 1]);
        }

        vector<int> rightGaps(n, 0);
        rightGaps[n - 1] = eventTime - endTime[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightGaps[i] = max(rightGaps[i + 1], startTime[i + 1] - endTime[i]);
        }

        for (int i = 0; i < n; ++i) {
            int leftGap = (i == 0) ? leftGaps[i] : startTime[i] - endTime[i - 1];
            int rightGap = (i == n - 1) ? rightGaps[i] : startTime[i + 1] - endTime[i];

            int interval = 0;
            if ((i != 0 && leftGaps[i - 1] >= (endTime[i] - startTime[i]))
                || (i != n - 1 && rightGaps[i + 1] >= (endTime[i] - startTime[i]))) {
                interval = endTime[i] - startTime[i];
            }

            maxFreeTime = max(maxFreeTime, leftGap + interval + rightGap);
        }

        return maxFreeTime;
    }
};