#include <stdio.h>

int main() {
    int nums[9];
    for (int i=0;i<9;i++) {
        scanf("%d", &nums[i]);
    }
    int max = nums[0];
    int index = 0;
    for (int i=0;i<9;i++) {
        if (max<nums[i]) {
            max = nums[i];
            index = i;
        }
    }
    printf("%d\n%d", max, index+1);

    return 0;
}