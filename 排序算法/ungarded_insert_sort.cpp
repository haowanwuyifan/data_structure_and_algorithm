/*------------------------------------------------------------------------------
 * @file    UNGARDED_INSERT_SORT.CPP
 * @author  FIRMWARE TEAM 
 * @date    2023/11/26 12:20:08
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _UNGARDED_INSERT_SORT_C_

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
#include "test.h"

using namespace std;

void ungarded_insert_sort(int *arr, int l, int r)
{
    int ind = l;
    for(int i=l+1; i<r; i++)
    {
        if(arr[i] < arr[ind]) ind = i;
    }
    while(ind > l)
    {
        swap(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    for(int i=l+1; i<r; i++)
    {
        int j = i;
        while(arr[j] < arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            j -= 1;
        }
    }
    return ;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int *arr = getRandData(SMALL_DATA_N);
    TEST(ungarded_insert_sort, arr, SMALL_DATA_N);
    free(arr);
    return 0;
}
