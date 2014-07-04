//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//using namespace std;

//#define ll long long
typedef __int64 ll;

int main(int argc, const char *argv[])
{
    ll gcd, lcm;
    //while(cin >> gcd >> lcm) {
    while (scanf("%I64d %I64d", &gdc, &lcm)) {
        ll ab = lcm/gcd;
        ll i = (ll) sqrt(ab);
        while (i > 0) {
            if ( ab % i == 0) {
                break;
            }
            i--;
        }
        printf("%I64d %I64d\n", gcd*i, ab/i*gcd);
        //cout << gcd*i << " " << ab/i*gcd << endl;
    }
    
    return 0;
}
