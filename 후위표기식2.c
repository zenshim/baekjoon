#include <stdio.h>
#include <string.h>

#define N 100

typedef double element;

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

double evaluate(char str[], double nums[]) {
    stackType s;
    init(&s);
    char c;
    int n = strlen(str);
    double op1, op2, num;

    for (int i=0;i<n;i++) {
        c = str[i];
        if (c<='Z' && c>='A') {
            num = nums[c-'A'];
            push(&s, num);
        }
        else if (c=='+'||c=='-'||c=='*'||c=='/') {
            op2 = pop(&s);
            op1 = pop(&s);
            switch (c) {
                case '+': push(&s, op1+op2); break;
                case '-': push(&s, op1-op2); break;
                case '*': push(&s, op1*op2); break;
                case '/': push(&s, op1/op2); break;
            }
        }
    }

    return pop(&s);
}

int main() {
    int n;
    scanf("%d", &n);
    char str[N];
    double nums[N];
    scanf("%s", str);
    for (int i=0;i<n;i++)
        scanf("%lf", &nums[i]);

    printf("%.2f", evaluate(str, nums));

    return 0;
}