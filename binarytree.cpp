/*------------------------------------------------------------------------------
 * @file    BINARYTREE.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/01 12:12:12
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
#define _BINARYTREE_C_

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

using namespace std;

typedef struct Node
{
    int key;
    struct Node *lchild, *rchild;
} Node;

Node* getNewNode(int key)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node* insert(Node* root, int key)
{
    if(root == NULL) return getNewNode(key);
    if(rand() % 2) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    return root;
}


void clear(Node* root)
{
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}


#define MAX_NODE 10
Node *que[MAX_NODE + 5]; 
int head, tail;
void bfs(Node* root)
{
    head = tail = 0;
    que[tail++] = root;
    while(head < tail)
    {
        Node* node = que[head];
        printf("\nnode : %d\n", node->key);
        if(node->lchild) {
            que[tail++] = node->lchild;
            printf("\t%d->%d(left)\n", node->key, node->lchild->key);
        }
        if(node->rchild) {
            que[tail++] = node->rchild;
            printf("\t%d->%d(right)\n", node->key, node->rchild->key);
        }
        head++;
    }
    return ;
}

int tot = 0;
void dfs(Node* root)
{
    if(root == NULL) return ;
    int start, end;
    tot += 1;
    start = tot;
    if(root->lchild) dfs(root->lchild);
    if(root->rchild) dfs(root->rchild);
    tot += 1;
    end = tot;
    printf("%d : [%d, %d]\n", root->key, start, end);
    return ;
}

/*----------------------------------------------------------------------------*/
int main()
{
    srand(time(0));
    Node* root = NULL;
    for(int i=0;i<MAX_NODE;i++)
    {
        root = insert(root, rand() % 100);
    }
    bfs(root);
    dfs(root);
    return 0;
}
