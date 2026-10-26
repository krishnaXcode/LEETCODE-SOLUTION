class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0; // Points to the last unique element found
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1; // Length of unique elements
    }
};