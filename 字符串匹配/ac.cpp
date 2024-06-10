/*------------------------------------------------------------------------------
 * @file    AC.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/03/29 16:20:40
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _AC_C_

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
#include <cstring>
#include <vector>


#define BASE 26
using namespace std;

typedef struct Node {
    int flag;
    struct Node* next[26];
    struct Node* fail;
    const char* s;
} Node;

Node* getNewNode()
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->flag = 0;
    p->fail = NULL;
    p->s = NULL;
    for(int i=0; i<26; i++)
    {
        p->next[i] = NULL;
    }
    return p;
}

void clear(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    for(int i=0; i<BASE; i++)
    {
        if(root->next[i] == NULL) continue;
        clear(root->next[i]);
    }
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
    p->s = strdup(s);
    return ;
}

void build_ac(Node* root)
{
    queue<Node*> q;
    for(int i=0; i<BASE; i++)
    {
        if(root->next[i] == NULL) continue;
        root->next[i]->fail = root;
        q.push(root->next[i]);
    }
    while(!q.empty())
    {
        Node* cur = q.front(), *p;
        q.pop();
        for(int i=0; i<BASE; i++)
        {
            if(cur->next[i] == NULL) continue;
            p = cur->fail;
            while(p && p->next[i] == NULL) p =p->fail;
            if(p == NULL) p = root;
            else p = p->next[i];
            cur->next[i]->fail = p;
            q.push(cur->next[i]);
        }
    }
    return ;
}

void find_ac(Node* root, const char* s)
{
    Node* p = root, *q;
    for(int i=0; s[i]; i++)
    {
        int ind = s[i] - 'a';
        while(p && p->next[i] == NULL) p = p->fail;
        if(p == NULL) p = root;
        else p = p->next[ind];
        q = p;
        while(q)
        {
            if(q->flag)
            {
                int len = strlen(q->s);
                printf("find [%d, %d] = %s\n", i -len + 1, i, q->s);
            }
            q = q->fail;
        }
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    char s[100];
    Node* root = getNewNode();
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%s", s);
        insert(root, s);
    }
    build_ac(root);
    scanf("%s", s);
    find_ac(root, s);
    return 0;
}
