/*------------------------------------------------------------------------------
 * @file    HAFFMAN.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/10 10:53:56
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
#define _HAFFMAN_C_

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
#include <string.h>

#define swap(a, b) { \
    typeof(a) __c = a; \
    a = b, b = __c; \
}

using namespace std;

typedef struct Node
{
    char ch;
    int freq;
    Node* lchild, *rchild;
} Node;

typedef struct Heap
{
    Node** __data, **data;
    int n, size;
} Heap;

Heap *getNewHeap(int size)
{
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->__data = (Node**)malloc(sizeof(Node*));
    h->data = h->__data - 1;
    h->n = 0;
    h->size = size;
    return h;
}

void clearHeap(Heap *h)
{
    if(h == NULL) return ;
    free(h->__data);
    free(h);
    return ;
}

int fullHeap(Heap *h)
{
    return h->size == h->n;
}


int emptyHeap(Heap* h)
{
    return h->n == 0;
}

Node *top(Heap *h)
{
    if(emptyHeap(h)) return NULL;
    return h->data[1];
}

int cmpHeap(Heap *h, int i, int j)
{
    return h->data[i]->freq < h->data[i/2]->freq;
}

void up_maintain(Heap* h, int i)
{
    while(i>1 && cmpHeap(h, i, i / 2))
    {
        swap(h->data[i], h->data[i/2]);
        i = i / 2;
    }
    return ;
}

void down_maintain(Heap* h, int i)
{
    while(i*2 <= h->n)
    {
        int ind = i, l = 2 * i, r = 2 * i + 1;
        if(cmpHeap(h, l, ind)) ind = l;
        if(r<=h->n && cmpHeap(h, r, ind)) ind = r;
        if(ind == i) return ;
        swap(h->data[i], h->data[ind]);
        i = ind;
    }
    return ;
}

int pushHeap(Heap* h, Node* n)
{
    if(fullHeap(h)) return 0;
    h->n += 1;
    h->data[h->n] = n;
    up_maintain(h, h->n);
    return 1;
}




int popHeap(Heap *h)
{
    if(emptyHeap(h)) return 0;
    h->data[1] = h->data[h->n];
    h->n -= 1;
    down_maintain(h, 1);
    return 1;
}

Node* getNewNode(int freq, char ch)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->ch = ch;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;
}

void swap_node(Node** node_arr, int i, int j)
{
    Node *temp = node_arr[i];
    node_arr[i] = node_arr[j];
    node_arr[j] = temp;
    return ;
}

int find_min_node(Node** node_arr, int n)
{
    int ind = 0;
    for(int j = 1;j<=n;j++)
    {
        if(node_arr[ind]->freq > node_arr[j]->freq) ind = j;
    }   
    return ind;
}

Node* BuildHaffmanTree(Node** node_arr, int n)
{
    Heap *h = getNewHeap(n);
    for(int i=0; i<n; i++) pushHeap(h, node_arr[i]);

    for(int i=1;i<n;i++)
    {
        // int ind1 = find_min_node(node_arr, n - i);
        // swap_node(node_arr, ind1, n-i);
        // int ind2 = find_min_node(node_arr, n - i -1);
        // swap_node(node_arr, ind2, n - 1 - i);
        // int freq = node_arr[n-i]->freq + node_arr[n-i-1]->freq;
        // Node *node = getNewNode(freq, 0);
        // node->lchild = node_arr[n-i-1];
        // node->rchild = node_arr[n-i];
        // node_arr[n-i-1] = node;
        Node *node1 = top(h);
        popHeap(h);
        Node *node2 = top(h);
        popHeap(h);
        Node *node3 = getNewNode(node1->freq+node2->freq, 0);
        node3->lchild = node1;
        node3->rchild = node2;
        pushHeap(h, node3);
    }
    Node *ret = top(h);
    clearHeap(h);
    // return node_arr[0];
    return ret;
}

void clear(Node* root)
{
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

#define MAX_CHAR_NUM 128
char *char_code[MAX_CHAR_NUM] = {0};

void extractHaffmanCode(Node* root, char buff[], int k)
{
    buff[k] = 0;
    if(root->lchild == NULL && root->rchild == NULL)
    {
        char_code[root->ch] = strdup(buff);
        printf("%c: %s\n", root->ch, buff);
        return ;
    }
    buff[k] = '0';
    extractHaffmanCode(root->lchild, buff, k + 1);
    buff[k] = '1';
    extractHaffmanCode(root->rchild, buff, k + 1);
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    char s[10];
    int n, freq;
    scanf("%d", &n);
    Node **Node_arr = (Node**)malloc(sizeof(Node*) * n);
    for(int i = 0;i<n;i++)
    {
        scanf("%s%d", s, &freq);
        Node_arr[i] = getNewNode(freq, s[0]);
    }
    Node* root = BuildHaffmanTree(Node_arr, n);
    char buff[1000];
    extractHaffmanCode(root, buff, 0);
    for(int i=0;i<MAX_CHAR_NUM;i++)
    {
        if(char_code[i] == NULL) continue;
        printf("%c: %s\n", i, char_code[i]);
    }
    clear(root);
    return 0;
}
