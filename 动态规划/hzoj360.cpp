/*------------------------------------------------------------------------------
 * @file    HZOJ360.CPP
 * @author  FIRMWARE TEAM 
 * @date    2024/01/25 10:31:48
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------

/* Define to prevent recursive inclusion  ------------------------------------*/
#define _HZOJ360_C_

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
#include <ctype.h>
#include <vector>

using namespace std;

int val[10][10] = {0};
int dp[20][10][10][10][10] = {0};

int VAL(int i, int j, int k, int l)
{
    return val[k][l] - val[k][j-1] - val[i-1][l] + val[i-1][j-1];
}

int S(int x)
{
    return x * x;
}

/*----------------------------------------------------------------------------*/
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            scanf("%d", &val[i][j]);
            val[i][j] += val[i-1][j] + val[i][j-1] - val[i-1][j-1];
        }
    }
    for(int i=1; i<=8; i++)
    {
        for(int j=1; j<=8; j++)
        {
            for(int k=i; k<=8; k++)
            {
                for(int l=j; l<=8; l++)
                {
                    dp[1][i][j][k][l] = S(VAL(i, j , k, l));
                }
            }
        }
    }
    for(int t=2; t<=n; t++)
    {
        for(int i=1; i<=8; i++)
        {
            for(int j=1; j<=8; j++)
            {
                for(int k=i; k<=8; k++)
                {
                    for(int l=j; l<=8; l++)
                    {
                        int ans = INT32_MAX;
                        for(int c=j; c<l; c++)
                        {
                            int val1 = dp[1][i][j][k][c] + dp[t-1][i][c+1][k][l];
                            int val2 = dp[t-1][i][j][k][c] + dp[1][i][c+1][k][l];
                            ans = min(ans, min(val1, val2));
                        }
                        for(int c=i; c<k; c++)
                        {
                            int val1 = dp[1][i][j][c][l] + dp[t-1][c+1][j][k][l];
                            int val2 = dp[t-1][i][j][c][l] + dp[1][c+1][j][k][l];
                            ans = min(ans, min(val1, val2));
                        }
                        dp[t][i][j][k][l] = ans;
                    }
                }
            }
        }
    }
    printf("%d\n", dp[1][1][8][8]);
    return 0;
}
