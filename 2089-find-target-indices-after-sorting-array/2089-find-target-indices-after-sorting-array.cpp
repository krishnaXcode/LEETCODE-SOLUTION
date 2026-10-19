class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, lessThan = 0;
        
        for (int num : nums) {
            if (num < target) {
                lessThan++;
            } else if (num == target) {
                count++;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < count; i++) {
            result.push_back(lessThan + i);
        }
        
        return result;
    }
};