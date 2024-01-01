#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
    int data;
    Node* next;
} Ndoe;


typedef struct LinkList
{
    Node head, *tail; 
} LinkList;

LinkList* initLinkList()
{
    LinkList* l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->tail = &(l->head);
    return l;
}

Node* getNewNode(int val)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

void clearLinkList(LinkList *l)
{
    Ndoe *p = l->head.next, *q;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}

int frontList(LinkList *l)
{
    if(l->head.next == NULL) return 0;
    return l->head.next->data;
}

int insertTail(LinkList *l, int val)
{
    Node *node = getNewNode(val);
    l->tail->next = node;
    l->tail = node;
    return 1;
}

int emptyList(LinkList *l)
{
    return l->head.next == NULL;
}

int eraseHead(LinkList* l)
{
    if(emptyList(l)) return 0;
    Node* p = l->head.next;
    l->head.next = l->head.next->next;
    if(p == l->tail) l->tail = &(l->head);
    free(p);
    return 1;
}

typedef struct Queue
{
    /* data */
    LinkList *l;
    int size, count;
} Queue;

Queue *initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->count = 0;
    q->l = initLinkList();
    return q;
}

int empty(Queue *q){
    return q->count == 0;
}

int front(Queue *q)
{
    if(empty(q)) return 0;
    return frontList(q->l);
}
int push(Queue *q, int val)
{
    insertTail(q->l, val);
    q->count += 1;
    return 1;
}
int pop(Queue *q)
{
    eraseHead(q->l);
    q->count -= 1;
    return 1;
}

void clearQueue(Queue *q)
{
    if(q == NULL) return ;
    clearLinkList(q->l);
    free(q);
    return ;
}

void outputQueue(Queue* q)
{
    printf("Queue: ");
    Node* p = q->l->head.next;
    for(int i=0;i<q->count;i++, p=p->next)
    {
        printf("%4d", p->data);
    }
    printf("\n");
    return ;
}

int main()
{
    srand(time(0));
    #define MAX_OP 10
    Queue *q = initQueue();
    for(int i=0;i<MAX_OP;i++)
    {
        int op = rand() % 5, val = rand() % 100; // 0:pop | 1,2,3,4:push
        switch (op)
        {
            case 0:
                printf("front of queue %d\n", front(q));
                pop(q);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                printf("push %d into queue\n", val);
                push(q, val);
                break;
            default:
                break;
        }
        outputQueue(q);
    }
    return 0;
}