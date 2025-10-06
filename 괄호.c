#include <stdio.h>
#include <string.h>

#define N 51

typedef char element;

typedef struct {
    int top;
    element stack[N];
}stackType;

void init(stackType* s) {
    s->top = -1;
}

int isEmpty(stackType* s) {
    return (s->top == -1);
}

int isFull(stackType* s) {
    return (s->top == N-1);
}

void push(stackType* s, element e) {
    if (isFull(s)) {
        return;
    }
    s->top++;
    s->stack[s->top] = e;
}

element pop(stackType* s) {
    if (isEmpty(s)) {
        return 0;
    }
    element temp = s->stack[s->top];
    s->top--;
    return temp;
}

void check(char str[]) {
    stackType s;
    init(&s);
    char ch_str;

    for (int i=0;i<strlen(str);i++) {
        ch_str=str[i];
        if (ch_str == '(')
            push(&s, '(');
        else if (ch_str == ')') {
            if(isEmpty(&s)) {
                printf("NO\n");
                return;
            }
            pop(&s);
        }
    }
    if (isEmpty(&s))
        printf("YES\n");
    else
        printf("NO\n");
}

int main() {
    int T;
    char str[N];
    scanf("%d", &T);
    getchar();

    for(int i=0;i<T;i++) {
        scanf("%s", str);
        check(str);
    }

    return 0;
}