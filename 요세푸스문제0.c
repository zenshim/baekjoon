#include <stdio.h>
#define N 1000001
typedef int element;

typedef struct {
    int front, rear;
    element queue[N];
}QueueType;

QueueType q;

void init(QueueType* q) {
    q->front = q->rear = -1;
}

int isEmpty(QueueType* q) {
    return q->front == q->rear;
}

void enqueue(QueueType* q, element e) {
    q->rear++;
    q->queue[q->rear] = e;
}

element dequeue(QueueType* q) {
    q->front++;
    return q->queue[q->front];
}

void josephus(int n, int k) {
    init(&q);
    element e;
    int result[n];
    int j=0;
    for (int i=1;i<=n;i++) {
        enqueue(&q, i);
    }
    while (q.front != q.rear -1) {
        for (int i=0;i<k-1;i++) {
            e = dequeue(&q);
            enqueue(&q, e);
        }
        result[j++] = dequeue(&q);
    }
    result[j++] = dequeue(&q);

    printf("<");
    for (int i=0;i<n-1;i++)
        printf("%d, ", result[i]);
    printf("%d>", result[n-1]);
}


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    josephus(n, k);
    return 0;
}