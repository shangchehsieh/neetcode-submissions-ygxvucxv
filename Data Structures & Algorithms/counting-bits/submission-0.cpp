class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i=0; i<=n; i++) {
            int cnt=0;
            for (int j=0; j<=10; j++) {
                if (i&(1<<j)) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
