class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int size = position.size();
        vector<pair<int,int>> cars;
        vector<double> arrival_time(size);
        int count = size; // start assuming every car is its own fleet

        // pair up position and speed so they stay together after sorting
        for (int i = 0; i < size; i++)
            cars.push_back({position[i], speed[i]});

        // sort by position descending (closest to target first)
        // so we can compare each car against the car directly ahead of it
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());

        // compute arrival time for the leading car (closest to target)
        // cast to double to avoid integer division truncation
        arrival_time[0] = (double)(target - cars[0].first) / cars[0].second;

        for (int i = 1; i < size; i++) {
            arrival_time[i] = (double)(target - cars[i].first) / cars[i].second;

            if (arrival_time[i] <= arrival_time[i - 1]) {
                // this car catches up to the fleet ahead (including equal time = arrives together)
                // adopt the fleet's effective arrival time so subsequent cars compare correctly
                arrival_time[i] = arrival_time[i - 1];
                count--;
            }
        }

        return count;
    }
};