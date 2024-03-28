/*------------------------------------------------------------------------------
 * @file    TRIE.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/03/17 11:58:13
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _TRIE_C_

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

using namespace std;

#define BASE 26

typedef struct Node {
    Node *next[BASE];
    int flag;
} Node;

Node* getNewNode()
{
    Node* p = (Node*)malloc(sizeof(Node));
    for(int i=0; i<BASE; i++) p->next[i] = NULL;
    p->flag = 0;
    return p;
}

void clear(Node* root)
{
    if(root == NULL) return ;
    for(int i=0; i<BASE; i++) clear(root->next[i]);
    free(root);
    return ;
}

void insert(Node* root, const char* s)
{
    Node* p = root;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        if(p->next[ind] == NULL) p->next[ind] = getNewNode();
        p = p->next[ind];
    }
    p->flag = 1;
    return ;
}

int find(Node* root, const char* s)
{
    Node* p = root;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        p = p->next[ind];
        if(p == NULL) return 0;
    }
    return p->flag;
}

void output(Node* root, int k, char* buf)
{
    buf[k] = 0;
    if(root->flag)
    {
        printf("find : %s\n", buf);
    }
    for(int i=0; i<BASE; i++)
    {
        if(root->next[i] == NULL) continue;
        buf[k] = i + 'a';
        output(root->next[i], k+1, buf);
    }
    return ;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int op;    
    char s[100];
    cin >> op;
    Node *root = getNewNode();
    do
    {
        cin >> op;
        if(op == 3) break;
        cin >> s;
        switch(op)
        {
            case 1:
            {
                printf("insert %s to trie\n", s);
                insert(root, s);
            } break;
            case 2:
            {
                printf("find %s from trie : %d\n", s, find(root, s));
            } break;
        }
    } while (1);
    char buf[100];
    output(root, 0, buf);
    return 0;
}
