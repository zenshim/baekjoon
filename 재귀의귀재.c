#include <stdio.h>
#include <string.h>

typedef struct {
    int count;
    int ispal;
}Palindrome;

void init(Palindrome* p) {
    p->count = 0;
    p->ispal = -1;
}

int recursion(const char *s, int l, int r, Palindrome* p) {
    p->count++;
    if (l>=r)
        return 1;
    else if(s[l]!=s[r])
        return 0;
    else
        recursion(s, l+1, r-1, p);
}

void isPalindrome(const char *s, Palindrome* p) {
    p->ispal = recursion(s, 0, strlen(s)-1, p);
}

int main() {
    int n;
    scanf("%d", &n);
    char str[1000];
    Palindrome p;
    for (int i=0;i<n;i++) {
        scanf("%s", str);
        init(&p);
        isPalindrome(str, &p);
        printf("%d %d\n", p.ispal, p.count);
    }
}