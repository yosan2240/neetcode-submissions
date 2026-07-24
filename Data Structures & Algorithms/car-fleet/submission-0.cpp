class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> cars;
        vector<double> arrival_time(size);
        int count = size;
        for (int i = 0; i < size; i++)
            cars.push_back({position[i], speed[i]});
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        arrival_time[0] = (target - cars[0].first) / cars[0].second;
        for(int i = 1; i < size; i++) {
            arrival_time[i] = (double)(target - cars[i].first) / cars[i].second;
            if(arrival_time[i] <= arrival_time[i - 1]) {
                arrival_time[i] = arrival_time[i - 1];
                count--;
            }
        }

        return count;
    }
};
