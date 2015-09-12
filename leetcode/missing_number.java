class Solution {
    public int missingNumber(int[] x) {
        int len = x.length;
        int expect = len*(len+1) / 2;
        int sum = 0;
        for (int e : x) {
            sum += e;
        }
        return expect - sum;
    }
}

public class missing_number {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a = {0,1,3};
        System.out.println(s.missingNumber(a));
    }
}
