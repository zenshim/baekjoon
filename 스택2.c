#include <stdio.h>

#define N 100

typedef int element;

typedef struct {
    int top;
    element stack[N];
} stackType;

void init(stackType* s) {
    s->top = -1;
}

int isEmpty(stackType* s) {
    return s->top == -1;
}

int isFull(stackType* s) {
    return s->top == N-1;
}

void push(stackType* s, element e) {
    if (isFull(s))
        printf("Overflow\n");
    else {
        s->top++;
        s->stack[s->top] = e;
    }
}

element pop(stackType* s) {
    if (isEmpty(s))
        return -1;
    else {
        element temp = s->stack[s->top];
        s->top--;
        return temp;
    }
}

element peek(stackType* s) {
    if (isEmpty(s))
        return -1;
    else
        return s->stack[s->top];
}

int main() {
    stackType s;
    init(&s);
    int tasks, n;
    scanf("%d", &tasks);
    for (int i=0;i<tasks;i++) {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            int a;
            scanf("%d", &a);
            push(&s, a);
            break;
        case 2:
            printf("%d\n", pop(&s));
            break;
        case 3:
            printf("%d\n", s.top+1);
            break;
        case 4:
            printf("%d\n", isEmpty(&s));
            break;
        case 5:
            printf("%d\n", peek(&s));
        }
    }
    return 0;
}