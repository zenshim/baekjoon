#include <stdio.h>
#include <string.h>

#define N 101

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
    char ch_str, ch_stack;
    stackType s;
    init(&s);
    for (int i=0;i<strlen(str);i++) {
        ch_str = str[i];
        if (ch_str == '.')
            break;
        if (ch_str=='('||ch_str=='[')
            push(&s, ch_str);
        else if (ch_str==')'||ch_str==']'){
            if (isEmpty(&s)) {
                printf("no\n");
                return;
            }
            ch_stack = pop(&s);
            if (ch_stack=='('&&ch_str!=')'||
                ch_stack=='['&&ch_str!=']') {
                    printf("no\n");
                    return;
            }
        }
    }
    
    if (isEmpty(&s))
        printf("yes\n");
    else
        printf("no\n");
}

int main() {
    char str[N];
    while(1) {
        scanf("%[^\n]s", str);
        getchar();

        if (strcmp(str, ".") == 0)
            break;
        check(str);
    } 
    return 0;
}