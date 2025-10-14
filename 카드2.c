#include <stdio.h>
#define N 1000010

typedef int element;

typedef struct {
    int front, rear;
    element queue[N];
}QueueType;

QueueType q;

void init(QueueType* q) {
    q->front = q->rear = -1;
}

void enqueue(QueueType* q, element e) {
    q->rear++;
    q->queue[q->rear] = e;
}

element dequeue(QueueType* q) {
    q->front++;
    return q->queue[q->front];
}

int main() {
    init(&q);
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) {
        enqueue(&q, i);
    }

    if (n == 1) {
        printf("1");
    }
    else {
        while (1) {
        dequeue(&q);
        if (q.front == q.rear -1)
            break;
        else {
            element temp = dequeue(&q);
            enqueue(&q, temp);
        }
    }

    printf("%d", dequeue(&q));
    }

    return 0;
}
