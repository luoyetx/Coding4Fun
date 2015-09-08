class Solution {
    public int compareVersion(String version1, String version2) {
        String[] ver1 = version1.split("\\.");
        String[] ver2 = version2.split("\\.");
        int len1 = ver1.length;
        int len2 = ver2.length;
        int iter = (len1 < len2) ? len1 : len2;
        for (int i=0; i<iter; i++) {
            int x = Integer.parseInt(ver1[i]);
            int y = Integer.parseInt(ver2[i]);
            if (x < y) return -1;
            if (y < x) return 1;
        }
        if (len1 == len2) return 0;
        if (len1 < len2) {
            for (int i=len1; i<len2; i++) {
                int x = Integer.parseInt(ver2[i]);
                if (x > 0) return -1;
            }
        } else {
            for (int i=len2; i<len1; i++) {
                int x = Integer.parseInt(ver1[i]);
                if (x > 0) return 1;
            }
        }
        return 0;
    }
}

public class compare_version_numbers {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.compareVersion("1.0", "1"));
    }
}