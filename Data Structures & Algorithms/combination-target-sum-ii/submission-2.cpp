class Solution {
public:
    //global vector/var
    vector<vector<int>> res;
    vector<int> subset;
    int t;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        t = target;
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, candidates);
        return res;
    }

    void dfs(int index, int sum, vector<int>& candidates) {
        if (sum > t) return;
        if (sum == t) {
            res.push_back(subset);
            return;
        }
        for (int i=index; i<candidates.size(); i++) {
        if ( i>index && candidates[i] == candidates[i-1]) continue;
            subset.push_back(candidates[i]);
            dfs(i+1, sum+candidates[i], candidates);
            subset.pop_back();
        }
    }
};
