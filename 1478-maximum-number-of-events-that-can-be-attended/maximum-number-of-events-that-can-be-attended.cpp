class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> eventsByStartDay;
        int minDay = INT_MAX;
        int maxDay = 0;

        for (auto& event : events) {
            int startDay = event[0];
            int endDay = event[1];
            eventsByStartDay[startDay].push_back(endDay);
            minDay = min(minDay, startDay);
            maxDay = max(maxDay, endDay);
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int maxEventsAttended = 0;

        for (int day = minDay; day <= maxDay; ++day) {
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            for (int endDay : eventsByStartDay[day]) {
                minHeap.push(endDay);
            }
            if (!minHeap.empty()) {
                maxEventsAttended++;
                minHeap.pop();
            }
        }

        return maxEventsAttended;
    }
};