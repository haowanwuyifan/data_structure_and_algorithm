/*------------------------------------------------------------------------------
 * @file    SERIALIZE_DESERIALIZE.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/07 11:58:45
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
#define _SERIALIZE_DESERIALIZE_C_
#define MAX_NODE 10
#define KEY(n) (n ? n->key : -1)

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
#include <string.h>


using namespace std;

typedef struct Node
{
    int key;
    Node* lchild, *rchild;
}Node;

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



Node* getRandomBinaryTree(int n)
{
    Node *root = NULL;
    for(int i=0;i<n;i++)
    {
        root = insert(root, rand() % 100);
    }
    return root;
}



void clear(Node* root)
{
    if(root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    return ;
}

int len = 0;
char buff[1000];

void __serialize(Node* root)
{
    if(root == NULL) return ;
    len += snprintf(buff + len, 100, "%d", root->key);
    if(root->lchild == NULL && root->rchild == NULL) return ;
    len += snprintf(buff + len, 100, "(");
    __serialize(root->lchild);
    if(root->rchild)
    {
        len += snprintf(buff + len, 100, ",");
        __serialize(root->rchild);
    }
    len += snprintf(buff + len, 100, ")");
    return ;
}

void serialize(Node* root)
{
    memset(buff, 0, sizeof(buff));
    len = 0;
    __serialize(root);
    return ;
}

void print(Node* node)
{
    printf("%d(%d, %d)\n", KEY(node), KEY(node->lchild), KEY(node->rchild));
    return ;
}

void output(Node* root)
{
    if(root == NULL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

Node* deserialize(char* buff, int n)
{
    Node **s = (Node**)malloc(sizeof(Node*) * MAX_NODE);
    int top = -1, flag = 0, scode = 0, num = 0;
    Node* p = NULL, *root = NULL;
    for(int i=0; buff[i]; i++)
    {
        switch (scode)
        {
            case 0:
            {
                if(buff[i] >= '0' && buff[i] <= '9') scode = 1;
                else if(buff[i] == '(') scode = 2;
                else if(buff[i] == ',') scode = 3;
                else scode = 4;
                i -= 1;
            }
            break;
            case 1:
            {
                int key = 0;
                while(buff[i] >= '0' && buff[i] <= '9')
                {
                    key = key * 10 + (buff[i] - '0');
                    i += 1;
                }
                p = getNewNode(key);
                if(top >= 0 && flag == 0) s[top]->lchild = p;
                if(top >= 0 && flag == 1) s[top]->rchild = p;
                i -= 1;
                scode = 0;
            }
            break;
            case 2:
            {
                s[++top] = p;
                flag = 0;
                scode = 0;
            }
            break;
            case 3:
            {
                flag = 1;
                scode = 0;
            }
            break;
            case 4:
            {
                root = s[top];
                top -= 1;
                scode = 0;
            }
            break;
            default:
                break;
        }
    }
    return root;
}

/*----------------------------------------------------------------------------*/
int main()
{
    srand(time(0));
    Node* root = getRandomBinaryTree(MAX_NODE);
    serialize(root);
    output(root);
    printf("Buff[]: %s\n", buff);
    Node* new_root = deserialize(buff, len);
    output(new_root);
    return 0;
}
