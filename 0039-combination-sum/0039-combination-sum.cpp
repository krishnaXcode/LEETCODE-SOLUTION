class Solution {
private:
    void backtrack(vector<int>& candidates, int target, int idx, vector<int>& curr, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        if (target < 0 || idx == candidates.size()) {
            return;
        }
 
        curr.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, curr, result);
        curr.pop_back();
 
        backtrack(candidates, target, idx + 1, curr, result);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, result);
        return result;
    }
};