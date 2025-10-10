#include <stdio.h>

/*이진수 변환*/

void rBinary(long long n) {
    if (n/2 == 0) 
        printf("%lld", n);
    else {
        rBinary(n/2);
        printf("%lld", n%2);
    }
}

int main() {
    long long n;
    scanf("%lld", &n);
    rBinary(n);

    return 0;
}