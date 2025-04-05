#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **dp;
int size = -1;

int binomialcoeficient(int n, int k)
{
    // top down approach
    int i, j;
    if (size == -1)
    {
        dp = (int **)malloc((n + 1) * sizeof(int *));
        for (i = 0; i <= n; i++)
        {
            dp[i] = (int *)malloc((k + 1) * sizeof(int));
            for (j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        size = n + 1;
    }
    else if (n > size)
    {
        dp = (int **)realloc(dp, (n + 1) * sizeof(int *));
        for (i = size + 1; i <= n; i++)
        {
            dp[i] = (int *)malloc((k + 1) * sizeof(int));
            for (j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        size = n + 1;
    }

    if (dp[n][k] == -1)
    {
        if (n == k || k == 0)
        {
            dp[n][k] = 1;
        }
        else
        {
            dp[n][k] = binomialcoeficient(n - 1, k - 1) + binomialcoeficient(n - 1, k);
        }
    }
    return dp[n][k];
}

int binomialcoeficient2(int n, int k)
{
    // bottom up approach
    int i, j;
    if (size == -1)
    {
        dp = (int **)malloc((n + 1) * sizeof(int *));
        for (i = 0; i <= n; i++)
        {
            dp[i] = (int *)malloc((k + 1) * sizeof(int));
            for (j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        size = n + 1;
    }
    else if (n > size)
    {
        dp = (int **)realloc(dp, (n + 1) * sizeof(int *));
        for (i = size + 1; i <= n; i++)
        {
            dp[i] = (int *)malloc((k + 1) * sizeof(int));
            for (j = 0; j <= k; j++)
            {
                dp[i][j] = -1;
            }
        }
        size = n + 1;
    }


    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int n, k, i, item,ans;
    clock_t start, end;
    double time_taken;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter k : ");
    scanf("%d", &k);
    printf("Using top down approach : ");
    start = clock();
    ans = binomialcoeficient(n, k);
    end = clock();
    printf("%dC%d = %d\n", n, k, ans);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to run the algorithm: %f seconds\n", time_taken);
    printf("Using bottom up approach : ");
    start = clock();
    ans = binomialcoeficient(n, k);
    end = clock();
    printf("%dC%d = %d\n", n, k, ans);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to run the algorithm: %f seconds\n", time_taken);
    return 0;
}