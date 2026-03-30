class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //每小時能挑一串香蕉，吃k根，共有h小時可以吃
        //若那一串<k個，那妳可以吃完整串，但剩下的時間不能去吃別串
        int k = 1;
        while (true) {
            long long time = 0; // 1 <= piles[i] <= 1,000,000,000
            for (int num : piles) {
                if (num <= k) {
                    time++;
                } else {
                    if (num % k == 0) time += num/k;
                    else time += (num/k)+1;
                }
            }
            if (time <= h) return k;
            k++;
        }
    }
};
