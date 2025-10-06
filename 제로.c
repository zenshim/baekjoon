#include <stdio.h>
#define N 100000

typedef int element;

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
        printf("Overflow\n");
        return;
    }
    s->top++;
    s->stack[s->top] = e;
}

element pop(stackType* s) {
    if (isEmpty(s)) {
        printf("Underflow\n");
        return -1;
    }
    element temp = s->stack[s->top];
    s->top--;
    return temp;
}


int main() {
    stackType S;
    init(&S);
    int k, num;
    scanf("%d", &k);
    for (int i=0;i<k;i++) {
        scanf("%d", &num);
        if (num == 0)
            pop(&S);
        else 
            push(&S, num);
    }
    int sum=0;
    for (int i=0;i<S.top+1;i++)
        sum+=S.stack[i];
    
    printf("%d", sum);
    return 0;
}