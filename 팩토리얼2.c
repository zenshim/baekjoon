#include <stdio.h>

long long rfact(int n) {
    if (n==1 || n==0) 
        return 1;
    else
        return n*rfact(n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", rfact(n));

    return 0;
}