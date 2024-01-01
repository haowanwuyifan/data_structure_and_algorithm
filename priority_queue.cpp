/*------------------------------------------------------------------------------
 * @file    PRIORITY_QUEUE.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/15 12:15:59
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------
 * @attention 
 
 * THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE 
 * CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE 
 * TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH 
 * HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN 
 * CONNECTION WITH PRODUCTS MADE BY CUSTOMERS. 
 * 
 * <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2> 
------------------------------------------------------------------------------*/

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _PRIORITY_QUEUE_C_

/* Files includes  -----------------------------------------------------------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <time.h>

#define ROOT 1
#define cmp >
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)
#define swap(a, b) { \
    __typeof(a) __c = (a); \
    (a) = (b); \
    (b) = __c; \
}

using namespace std;

typedef struct PriorityQueue
{
    int *data, *__data;
    int size, n;
} PriorityQueue;

PriorityQueue *initPQ(int size)
{
    PriorityQueue *p = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    p->__data = (int*)malloc(sizeof(int) * size);
    p->data = p->__data - ROOT;
    p->size = size;
    p->n = 0;
    return p;
}

int empty(PriorityQueue *p)
{
    return p->n == 0;
}

int full(PriorityQueue *p)
{
    return p->n == p->size;
}

int top(PriorityQueue *p)
{
    return p->data[1];
}

void up_update(int *data, int i)
{
    while(i > ROOT && data[i] cmp data[FATHER(i)])
    {
        swap(data[i], data[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

void down_update(int* data, int i, int n)
{
    while(LEFT(i) <= n)
    {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if(data[l] cmp data[ind]) ind = l;
        if(r <= n && data[r] cmp data[ind]) ind = r;
        if(ind == i) break;
        swap(data[i], data[ind]);
        i = ind;   
    }
    return ;
}

int push(PriorityQueue *p, int val)
{
    if(full(p)) return 0;
    p->n += 1;
    p->data[p->n] = val;
    up_update(p->data, p->n);
    return 1;
}

int pop(PriorityQueue *p)
{
    if(empty(p)) return 0;
    p->data[ROOT] = p->data[p->n];
    p->n -= 1;
    down_update(p->data, ROOT, p->n);
    return 1;
}

void clearPQ(PriorityQueue *p)
{
    if(p == NULL) return ;
    free(p->__data);
    free(p);
    return ;
}

void output(PriorityQueue *p)
{
    printf("PQ(%d) : ", p->n);
    for(int i=1; i<=p->n; i++)
    {
        printf("%d ", p->data[i]);
    }
    return ;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int op, x;
    #define MAX_OP 100
    PriorityQueue *p = initPQ(MAX_OP);

    while(~scanf("%d", &op))
    {
        if(op == 1)
        {
            scanf("%d", &x);
            printf("insert %d to priority_queue : \n", x);
            push(p, x);
            output(p);
        }
        else
        {
            printf("pop : %d\n", top(p));
            pop(p);
            output(p);
        }
    }
    clearPQ(p);
    return 0;
}
