#include <stdio.h>
#include <string.h>
#define N 1001
typedef int element;

typedef struct {
    int top;
    element stack[N];
}stackType;

void init(stackType* s) {
    s->top = -1;
}

int isEmpty(stackType* s) {
    return s->top == -1;
}

void push(stackType* s, element e) {
    s->top++;
    s->stack[s->top] = e;
}

element pop(stackType* s) {
    if (isEmpty(s))
        return 0;
    else {
        element temp = s->stack[s->top];
        s->top--;
        return temp;
    }
}

element peek(stackType* s) {
    if (isEmpty(s))
        return 0;
    else {
        return s->stack[s->top];
    }
}

void check(int n, int order[]) {
    stackType s;
    init(&s);
    int e, min=1;

    for (int i=0;i<n;i++) {
        e = order[i];
        push(&s, e);

        while (!isEmpty(&s) && peek(&s) == min) {
            pop(&s);
            min++;
        }
    }

    if (isEmpty(&s)) {
        printf("Nice");
    }
    else {
        printf("Sad"); 
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int order[n];
    for (int i=0;i<n;i++) {
        scanf("%d", &order[i]);
    }

    check(n, order);
    return 0;
}