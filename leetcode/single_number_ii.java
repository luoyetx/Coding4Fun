class Solution {
    public int singleNumber(int[] nums) {
        int[] bit = new int[32];
        for (int i=0; i<nums.length; i++) {
            for (int j=0; j<bit.length; j++) {
                bit[j] += (nums[i]>>j) & 1;
            }
        }
        int result = 0;
        for (int i=0; i<bit.length; i++) {
            if (bit[i]%3 != 0) {
                result += 1 << i;
            }
        }
        return result;
    }
}

public class single_number_ii {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {1,1,2,1,2,2,3};
        System.out.println(s.singleNumber(a));
    }
}
