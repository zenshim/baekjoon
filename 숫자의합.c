#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    char nums[n];
    scanf("%s", nums);
    int result = 0;
    for (int i=0;i<n;i++) {
        result+=nums[i]-'0';
    }
    printf("%d", result);
}