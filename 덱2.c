#include <stdio.h>
#include <string.h>

#define N 10000000
typedef int element;

typedef struct {
    int front, rear;
    int size;
    element deque[N];
}DequeType;
DequeType D;

void init(DequeType* d) {
    d->front = d->rear = 1000000;
    d->size = 0;
}

int isEmpty(DequeType* d) {
    return d->size==0;
}

void addFront(DequeType* d, element e) {
    d->size++;
    d->deque[d->front] = e;
    d->front--;
}

void addRear(DequeType* d, element e) {
    d->size++;
    d->rear++;
    d->deque[d->rear] = e;
}

void delFront(DequeType* d) {
    if (isEmpty(d))
        printf("-1\n");
    else {
        d->size--;
        d->front++;
        printf("%d\n", d->deque[d->front]);
    }
}

void delRear(DequeType* d) {
    if (isEmpty(d))
        printf("-1\n");
    else {
        d->size--;
        element temp = d->deque[d->rear];
        d->rear--;
        printf("%d\n", temp);
    }
}

void printSize(DequeType* d) {
    printf("%d\n", d->size);
}

void peekFront(DequeType* d) {
    if (isEmpty(d))
        printf("-1\n");
    else    
        printf("%d\n", d->deque[d->front+1]);
}

void peekRear(DequeType* d) {
    if (isEmpty(d))
        printf("-1\n");
    else
        printf("%d\n", d->deque[d->rear]);
}

int main() {
    init(&D);
    int n, order;
    element e;
    scanf("%d", &n);
    getchar();
    for (int i=0;i<n;i++) {
        scanf("%d", &order);
        switch(order) {
            case 1:
                scanf("%d", &e);
                addFront(&D, e); break;
            case 2:
                scanf("%d", &e);
                addRear(&D, e); break;
            case 3:
                delFront(&D); break;
            case 4:
                delRear(&D); break;
            case 5:
                printSize(&D); break;
            case 6:
                printf("%d\n", isEmpty(&D)); break;
            case 7:
                peekFront(&D); break;
            case 8:
                peekRear(&D); break;
        } 
    }
    
    return 0;
}