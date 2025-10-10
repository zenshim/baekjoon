#include <stdio.h>
#include <math.h>

void Hanoi(int n, char from, char temp, char to) {
    if (n==1) 
        printf("%d %d\n", from, to);
    else {
        Hanoi(n-1, from, to, temp);
        printf("%d %d\n", from, to);
        Hanoi(n-1, temp, from, to);
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    k = pow(2,n)-1;
    printf("%d\n", k);
    Hanoi(n, 1, 2, 3);

    return 0;
}