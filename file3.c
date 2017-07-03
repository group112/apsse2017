double sum1(double b, double q, int n);
double sum2(double b, double q, int n);

double sum1(double b, double q, int n) {
    double sum, cur;
    int    i;

     
    for(i = 2, sum = b, cur = b; i <= n; i ++) {
        cur *= q;
        sum += cur; 
    } 

    return sum;
}

double sum2(double b, double q, int n) {
    double qn;
    int    i;

    for(i = 1, qn = 1.; i <= n; i ++)
        qn *= q; 

    return b * (1. - qn) / (1 - q);
}

