import java.util.Arrays;

class Solution {
    public int minMoves(int[] nums) {
        int max_val = Arrays.stream(nums).max().getAsInt();
        int total_moves = 0;
        for (int x : nums) {
            total_moves += (max_val - x);
        }
        return total_moves;
    }
}