/*------------------------------------------------------------------------------
 * @file    BINARY_SEARCH.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/12/03 12:35:12
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _BINARY_SEARCH_C_

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

void output(int* arr, int n, int ind = -1)
{
    int len = 0;
    for(int i=0; i<n; i++)
    {
        len += printf("%4d", i);
    }
    printf("\n");
    for(int i=0; i<len; i++) printf("-");
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(i == ind) printf("\033[1;32m");
        printf("%4d", arr[i]);
        if(i == ind) printf("\033[0m");
    }
    printf("\n");
    return ;
}

int binary_search(int *arr, int n, int x)
{
    int head = 0, tail = n - 1, mid;
    while(head <= tail)
    {
        mid = (head + tail) / 2;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

#define EXP 1e-4
#define min(a, b) ((a) < (b) ? (a) : (b))

double f(double x)
{
    double temp = x;
    if(temp >= 0) x -= min(x, 3000) * 0.03;
    if(temp > 3000) x-= (min(x, 12000) - 3000) * 0.1; 
    if(temp > 12000) x-= (min(x, 25000) - 12000) * 0.2; 
    if(temp > 25000) x-= (min(x, 35000) - 25000) * 0.25; 
    if(temp > 35000) x-= (min(x, 55000) - 35000) * 0.3; 
    if(temp > 55000) x-= (min(x, 80000) - 55000) * 0.35; 
    if(temp > 80000) x-= (x - 80000) * 0.45; 
    return x;
}

double binary_algorithm(double y)
{
    double head = 0, tail = 1000000, mid;
    while(tail - head >= EXP)
    {
        mid = (head + tail) / 2.0;
        if(f(mid) < y) head = mid;
        else tail = mid;
    }
    return head;
}

void test_binary_search(int n)
{
    int *arr = (int*)malloc(sizeof(int) * n);
    arr[0] = rand() % 10;
    for(int i=1; i<n; i++) arr[i] = arr[i-1] + rand() % 10;
    output(arr, n);
    int x;
    while(~scanf("%d", &x))
    {
        if(x == -1) break;
        int ind = binary_search(arr, n, x);
        output(arr, n, ind);
    }
}

void test_binary_algorithm()
{
    double y;
    while(~scanf("%lf", &y))
    {
        if(y<0) break;
        double x = binary_algorithm(y);
        printf("f(%.2lf) = %.2lf\n", x, y);
    }
    return ;
}


/*----------------------------------------------------------------------------*/
int main()
{
    #define MAX_N 10
    test_binary_search(MAX_N);

    system("pause");
    return 0;
}
