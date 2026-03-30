class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int k = l + (r-l)/2;

            long long time = 0;
            for (int p : piles) {
                if (p%k==0) time += p/k;
                else time += (p/k)+1;
            }
            if (time <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};
