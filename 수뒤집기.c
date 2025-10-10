#include <stdio.h>

int reverse(int n) {
    int reversed = 0;
    while (n!=0) {
        reversed = reversed*10 + n%10;
        n = n/10;
    }
    return reversed;
}

void test(int added) {
    int reversed = reverse(added);

    if (added == reversed) 
        printf("YES\n");
    else    
        printf("NO\n");
}

int main() {
    int t, n, rn;
    scanf("%d", &t);
    for (int i=0;i<t;i++) {
        scanf("%d", &n);
        rn = reverse(n);
        test(n+rn);
    }

    return 0;
}