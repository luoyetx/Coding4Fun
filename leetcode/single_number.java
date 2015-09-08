class Solution {
    public int singleNumber(int[] nums) {
        int single = 0;
        for (int i=0; i<nums.length; i++) {
            single ^= nums[i];
        }
        return single;
    }
}

public class single_number {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {1,2,3,4,3,2,1};
        System.out.println(s.singleNumber(a));
    }
}