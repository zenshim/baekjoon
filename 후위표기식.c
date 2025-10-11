#include <stdio.h>
#include <string.h>

#define N 100

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

element peek(stackType *s) {
    if (isEmpty(s))
        return 0;
    return s->stack[s->top];
}

int prec(char op) {
    switch (op) {
        case '(': case ')':
    }
}

void postFix(char str[]) {
    stackType s;
    init(&s);
    char postfix[N];
    char ch_str, op_stack;
    int n = strlen(str);
    int j = 0;
    for (int i=0;i<n;i++) {
        ch_str = str[i];
        if (ch_str>='A' && ch_str<='Z') 
            postfix[j++] = ch_str;
        else if (ch_str == '(')
            push(&s, ch_str);
        else if (ch_str == ')') {
            op_stack = pop(&s);
            while (!isEmpty(&s) && op_stack!='(') {
                postfix[j++] = pop(&s);
                op_stack = pop(&s);
            }
        }
        else if (ch_str=='+'||ch_str=='-'||ch_str=='*'||ch_str=='/') {
            
        }
    }
}