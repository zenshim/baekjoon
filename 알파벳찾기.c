#include <stdio.h>
#include <string.h>

int main() {
    char str[101];
    scanf("%s", str);
    int index[26];
    for (int i=0;i<26;i++)
        index[i] = -1;
    for (int i=0;i<strlen(str);i++) {
        int ch_str = str[i]-'a';
        if (index[ch_str]==-1) {
            index[ch_str] = i;
        } 
    }
    for (int i=0;i<26;i++)
        printf("%d ", index[i]);
}