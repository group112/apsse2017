double sum1(double a, double d, int n);
double sum2(double a, double d, int n);

double sum1(double a, double d, int n) {
    double sum, cur;
    int    i;

    for(i = 1, sum = 0., cur = a; i <= n; i ++, cur += d)
        sum += cur; 

    return sum;
}

double sum2(double a, double d, int n) {
    return (2 * a + (n - 1) * d) * n / 2;
}

