bool isHappy(int n) {
    if (n < 10) {
        if (n == 1 || n == 7) return true;
        else return false;
    }
    int m = 0;
    while (n > 0) {
        int r = n % 10;
        m += r * r;
        n /= 10;
    }
    return isHappy(m);
}
