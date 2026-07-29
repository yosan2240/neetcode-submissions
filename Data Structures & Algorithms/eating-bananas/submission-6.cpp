class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0;
        int k = INT_MAX;

        // search range: 1 to the maximum pile size
        for (int& pile : piles) {
            r = max(r, pile);
        }

        // binary search on eating speed k
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // calculate total hours needed at speed mid
            int time = 0;
            for (int pile : piles) {
                time += (pile + mid - 1) / mid;  // ceiling division
            }

            if (time <= h) {
                k = min(mid, k);  // mid is valid, record it and try smaller
                r = mid - 1;
            } else {
                l = mid + 1;      // mid is too slow, try faster
            }
            //Be careful not to return mid when mid is equal to time
        }

        return k;
    }
};