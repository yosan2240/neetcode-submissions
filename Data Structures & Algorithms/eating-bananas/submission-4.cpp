class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int l = 1, r = 0;
        int mid;
        int k = INT_MAX;

        /* We will find the minimum k in the range 1 to the maximum pile size */
        for(int& pile : piles) {
            r = max(r, pile);
        }

        /* Binary search */
        while(l <= r) {
            mid = l + (r - l) / 2;
            int time  = 0;
            for(int pile : piles) {
                time += (pile + mid - 1) / mid;
            }

            if(time <= h)
                r = mid - 1;
            else if(time > h)
                l = mid + 1;
            
            if(time <= h)
                k = min(mid, k);
            time = 0;
        }

        return k;
    }
};
