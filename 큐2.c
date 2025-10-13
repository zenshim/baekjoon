#include <stdio.h>
#include <string.h>
#define N 2000001

typedef int element;
typedef struct {
    int front, rear;
    element queue[N];
}QueueType;

QueueType q;

void init(QueueType* q) {
    q->front = q->rear = 0;
}

int empty(QueueType* q) {
    return q->front == q->rear;
}

void push(QueueType* q, element e) {
    q->rear++;
    q->queue[q->rear] = e;
}

void pop(QueueType* q) {
    if (empty(q)) {
        printf("-1\n");
    }
    else {
        q->front++;
        printf("%d\n", q->queue[q->front]);
    }
}

void printsize(QueueType* q) {
    printf("%d\n", q->rear - q->front);
}

void printfront(QueueType* q) {
    if (empty(q))
        printf("-1\n");
    else {
        printf("%d\n", q->queue[q->front+1]);
    }
}

void printback(QueueType* q) {
    if (empty(q))
        printf("-1\n");
    else    
        printf("%d\n", q->queue[q->rear]);
}


int main() {
    init(&q);
    int n;
    scanf("%d", &n);
    getchar();

    char str[20];
    char order[6];
    int num;
    for (int i=0;i<n;i++) {
        fgets(str,20,stdin);
        str[strcspn(str, "\n")] = '\0';

        if (sscanf(str, "%s %d", order, &num) == 1) {
            if (strcmp(order, "pop")==0)
                pop(&q);
            if (strcmp(order, "size")==0)
                printsize(&q);
            if (strcmp(order, "empty")==0) 
                printf("%d\n", empty(&q));
            if (strcmp(order, "front")==0)
                printfront(&q);
            if (strcmp(order, "back")==0)
                printback(&q);
        }
        else if (sscanf(str, "%s %d", order, &num) == 2) {
            push(&q, num);
        }
    }

    return 0;
}