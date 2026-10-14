class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum < 0 || sum > 9 * (long) num) {
            return "";
    }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < num; i++) {

            int digit = Math.min(9, sum);
    while (digit >= 0) {
                if (sum - digit <= 9 * (long) (num - 1 - i)) {
                    break;
                }
                digit--;
            }
            sb.append(digit);
            sum -= digit;
        }
        
        return sum == 0 ? sb.toString() : "";
    }

 
}