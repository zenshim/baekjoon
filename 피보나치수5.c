#include <stdio.h>

int rfibo(int n) {
    if (n==0 || n==1)
        return n==0 ? 0 : 1;
    else
        return rfibo(n-2)+rfibo(n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", rfibo(n));

    return 0;
}