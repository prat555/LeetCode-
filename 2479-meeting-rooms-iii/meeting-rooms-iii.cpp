class Solution {
public:
    int mostBooked(int totalRooms, vector<vector<int>>& schedules) {
        vector<int> usageCount(totalRooms, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> bookedRooms;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int roomNum = 0; roomNum < totalRooms; roomNum++) {
            freeRooms.push(roomNum);
        }
        sort(schedules.begin(), schedules.end());
    
        for (const auto& interval : schedules) {
            int startTime = interval[0], endTime = interval[1];
    
            while (!bookedRooms.empty() && bookedRooms.top().first <= startTime) {
                int availableRoom = bookedRooms.top().second;
                bookedRooms.pop();
                freeRooms.push(availableRoom);
            }
            if (!freeRooms.empty()) {
                int nextRoom = freeRooms.top();
                freeRooms.pop();
                bookedRooms.push({endTime, nextRoom});
                usageCount[nextRoom]++;
            } else {
                auto [nextAvailableTime, activeRoom] = bookedRooms.top();
                bookedRooms.pop();
                bookedRooms.push({nextAvailableTime + endTime - startTime, activeRoom});
                usageCount[activeRoom]++;
            }
        }
    
        int maximumUsage = 0, roomWithMaxUsage = 0;
        for (int roomIdx = 0; roomIdx < totalRooms; roomIdx++) {
            if (usageCount[roomIdx] > maximumUsage) {
                maximumUsage = usageCount[roomIdx];
                roomWithMaxUsage = roomIdx;
            }
        }
        return roomWithMaxUsage;
    }
};