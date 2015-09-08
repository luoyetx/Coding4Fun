class Solution {
    public int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int i=0; i<nums.length; i++) {
            xor ^= nums[i];
        }
        int mask = 1;
        while ((xor&mask) == 0) mask <<= 1;
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        int leftRealLen, rightRealLen;
        leftRealLen = rightRealLen = 0;
        for (int i=0; i<nums.length; i++) {
            if ((nums[i]&mask) == 0) {
                left[leftRealLen] = nums[i];
                leftRealLen++;
            } else {
                right[rightRealLen] = nums[i];
                rightRealLen++;
            }
        }
        int[] result = new int[2];
        for (int i=0; i<leftRealLen; i++) {
            result[0] ^= left[i];
        }
        for (int i=0; i<rightRealLen; i++) {
            result[1] ^= right[i];
        }
        return result;
    }
}

public class single_number_iii {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {1,1,2,2,3,4};
        int[] b = s.singleNumber(a);
        System.out.format("%d %d\n", b[0], b[1]);
    }
}
