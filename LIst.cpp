#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_OP 20

typedef struct vector
{
    /* data */
    int count, size;
    int* data;
} vector;

vector* getNewVector(int n)
{
    vector* p = (vector*)malloc(sizeof(vector));
    p->size = n;
    p->count = 0;
    p->data = (int*)malloc(sizeof(int) * n);
    return p;
}

void clear(vector* p)
{
    if(p == NULL)
        return;
    free(p->data);
    free(p);
    return ;
}

int insert(vector* p, int position, int val)
{
    if(position<0 || position>=p->count) return 0;
    if(p->size == p->count && !expand(p)) return 0;
    for(int i=p->count - 1;i>=position;i--)
    {
        p->data[i+1] = p->data[i];
    }
    p->data[position] = val;
    p->count++;
    return 1;
}

int erase(vector* v, int position)
{
    if(position<0 || position>=v->count) return 0;
    for(int i=position+1;i<v->count;i++)
    {
        v->data[i-1] = v->data[i];
    }
    v->count--;
    return 1;
}

void output_vector(vector* v)
{
    
    int len = 0;
    for(int i=0;i<v->count;i++)
    {
        len += printf("%3d", i);
    }
    printf("\n");
    for(int i=0;i<v->count;i++)
    {
        printf("%3d", v->data[i]);
    }
    printf("\n");
    printf("\n\n");
    return ;
}

int expand(vector* v)
{
    if(v == NULL) return 0;
    printf("expand vector from %d to %d", v->size, 2*v->size);
    int* p = (int*)realloc(v->data, sizeof(int)*2*v->size);
    if(p == NULL) return 0;
    v->data = p;
    v->size *= 2;
    return 1;
}

int main()
{
    srand(time(0));
    vector* v = getNewVector(MAX_OP);
    for(int i=0;i<MAX_OP;i++)
    {
        int op = rand() % 4, pos, val, ret;
        switch (op)
        {
            case 0:
            /* code */
            case 1:
            case 2:
                pos = rand() % (v->count + 2);
                val = rand() % 100;
                ret = insert(v, pos, val);
                printf("insert %d at %d to vector = %d\n", val, pos, ret);
                break;
            case 3:
                pos = rand() % (v->count + 2);
                ret = erase(v, pos);
                printf("erase item at %d in vector = %d\n", pos, ret);
                break;
        
        default:
            break;
        }
    }
    output_vector(v);
    free(v);
    return 0;
}