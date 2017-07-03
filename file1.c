#define _GNU_SOURCE
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <math.h>
#include <fenv.h>

#define MAX 100000

static void fesetup(void);
double sum1(double a, double d, int n);
double sum2(double a, double d, int n);

int main(int argc, char *argv[]) {
    double a, d, e, s1, s2, r;
    int    n, p;

    fesetup();

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <a> <d> <e>\n", argv[0]);
        return -1;
    } 

    p = 0;
    sscanf(argv[1], "%lf%n", &a, &p);
    if(!p || argv[1][p]) {
        fprintf(stderr, "Can't read a ...\n");
        return -1;
    }

    p = 0;
    sscanf(argv[2], "%lf%n", &d, &p);
    if(!p || argv[2][p]) {
        fprintf(stderr, "Can't read d ...\n");
        return -1;
    }

    p = 0;
    sscanf(argv[3], "%lf%n", &e, &p);
    if(!p || argv[3][p]) {
        fprintf(stderr, "Can't read e ...\n");
        return -1;
    }

    for(n = 1; n <= MAX; n ++) {
        s1 = sum1(a, d, n);
        s2 = sum2(a, d, n);
        r  = fabs(s1 - s2);

        if(r > e) {
            printf("Find n: %d\n", n);
            break;
        }
        else
            fprintf(stderr, "n: %5d s1: %20.9lf s2: %20.9lf r: %.12lf\n", n, s1, s2, r);
    }

    return 0;
}

static void handler(int sig);

static void fesetup(void) {
    if(feenableexcept(FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW) == -1) {
        fprintf(stderr, "Can't setup traps for the floating-point exceptions ...\n");
        exit(-1);
    }

    if(signal(SIGFPE, handler) == SIG_ERR) {
        fprintf(stderr, "Can't setup the floating-point exception signal handler ...\n");
        exit(-1);
    }

}

static void handler(int sig) {
    fprintf(stderr, "Caught signal %d\n", sig);
    exit(-1);
}

