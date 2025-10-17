/*이번에는 원형연결리스트 이용하여 풀이*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node{
    element data;
    struct Node* next;
}Node;

typedef struct {
    Node* tail;
    int size;
}ListType;

void init(ListType* L) {
    L->tail = NULL;
    L->size = 0;
}

Node* makeNode(element e) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->data = e;
    return node;
}

int isEmpty(ListType* L) {
    return L->size == 0;
}

void insertLast(ListType* L, element e) {
    Node* node = makeNode(e);
    if (isEmpty(L)) {
        L->tail = node;
        node->next = node;
    }
    else {
        node->next = L->tail->next;
        L->tail->next = node;
        L->tail = node;
    }
    L->size++;
}

element delFirst(ListType* L) {
    Node* p = L->tail;
    Node* q = p->next;
    element e = q->data;
    if (p == q) {
        L->tail = NULL;
    }
    else {
        p->next = q->next;
    }
    free(q);
    L->size--;
    return e;
}

int main() {
    ListType L;
    init(&L);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i=1;i<=n;i++) 
        insertLast(&L, i);
    printf("<");
    while (L.size>1) {
        for (int i=1;i<k;i++)
            insertLast(&L, delFirst(&L));
        printf("%d, ", delFirst(&L));
    }
    printf("%d>", delFirst(&L));

    return 0;
}