class Solution {
    public int reverse(int x) {
        int[] num = new int[20];
        int len = 0;
        boolean flag = true;
        if (x < 0) {
            flag = false;
            x = -x;
        }
        while (x > 0) {
            num[len] = x % 10;
            len++;
            x /= 10;
        }
        int result = 0;
        for (int i=0; i<len; i++) {
            result = result*10 + num[i];
            if (result%10 != num[i]) return 0;
        }
        if (!flag) result = -result;
        return result;
    }
}

public class reverse_integer {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.reverse(1534236469));
    }
}