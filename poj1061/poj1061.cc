#include <stdio.h>
#include <stdint.h>

int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if ( 0 == b ) {
        x = 1;
        y = 0;
        return a;
    }

    int64_t d = exgcd(b, a % b, x, y);
    int64_t temp = x; 
    x = y;
    y = temp - a/b*y;
    return d;
}

int main(int argc, const char *argv[])
{
    int64_t x,y,m,n,l,d;
    int64_t aa, bb, xx, yy, dd;
    while(scanf("%ld %ld %ld %ld %ld", &x, &y, &m, &n, &l) != EOF) {
        aa = m - n;
        bb = l;
        d  = y - x;
        if (aa < 0) {
            aa = -aa;
            d = -d;
        }

        dd = exgcd( aa, bb, xx, yy);

        if (d % dd != 0) {
            printf("Impossible\n");
        }
        else {
            xx = xx * d / dd;
            yy = yy * d / dd;
            l = l / dd;
            if (xx > 0) {
                xx = xx % l;
            }
            else {
                xx = xx % l + l;
            }
            printf("%ld\n", xx);
        }
        
    }
    return 0;
}

