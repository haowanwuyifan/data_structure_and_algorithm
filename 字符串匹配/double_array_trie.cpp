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
#define MAX_N 100000

typedef struct Node {
    Node *next[BASE];
    int flag;
} Node;

typedef struct DANode {
    int base, check;
} DANode;

DANode trie[MAX_N + 5];
int da_trie_root = 1;

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

int find(DANode* trie, const char* s)
{
    int p = da_trie_root;
    for(int i=0; s[i]; i++)
    {
        int ind = trie[p].base + s[i] - 'a';
        if(abs(trie[ind].check) != p) return 0;
        p = ind;
    }
    return trie[p].check < 0;
}

int get_base(Node* root, int ind, DANode* trie)
{
    int base = 2;
    do{
        int flag = 1;
        for(int i=0; i<BASE; i++)
        {
            if(root->next == NULL) continue;
            if(trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
        if(flag == 1) break;
        base += 1;
    }while(1);
    return base;
}

void convert_to_double_array_trie(Node* root, int ind, DANode* trie)
{
    trie[ind].base = get_base(root, ind, trie);
    for(int i=0; i<BASE; i++)
    {
        if(root->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = (root->next[i]->flag ? -ind : ind);

    }
    for(int i=0; i<BASE; i++)
    {
        if(root->next[i] == NULL) continue;
        convert_to_double_array_trie(root->next[i], trie[ind].base + i, trie);
    }
    return ;
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
    int n; 
    char s[100];
    cin >> n;
    Node *root = getNewNode();
    for(int i=0; i<n; i++)
    {
        scanf("%s", s);
        insert(root, s);
    }
    convert_to_double_array_trie(root, da_trie_root, trie);
    char buf[100];
    while(scanf("%s", s) != EOF)
    {
        printf("find %s from double array trie : %d\n", s, find(trie, s));
    }
    output(root, 0, buf);
    clear(root);
    return 0;
}
