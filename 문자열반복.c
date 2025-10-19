#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t, r;
    char* str = (char*)malloc(sizeof(char)*21);
    scanf("%d", &t);
    for (int i=0;i<t;i++) {
        scanf("%d %s", &r, str);
        for (int j=0;j<strlen(str);j++) {
            for (int k=0;k<r;k++) {
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }

    free(str);
    return 0;
}