#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n = -1;
int *dp;

int factorial(int val)
{
    int prevn = n;
    if (n == -1)
    {
        dp = (int *)malloc((val + 1) * sizeof(int));
        n = val;
    }
    else if (val > n)
    {
        dp = (int *)realloc(dp, (val + 1) * sizeof(int));
        n = val;
    }

    int i;
    for (i = prevn + 1; i <= n; i++)
    {
        if (i == 0)
            dp[0] = 1;
        else
        {
            dp[i] = i * dp[i - 1];
        }
    }

    return dp[val];
}

int main()
{
    int turns;
    printf("Enter number of turns : ");
    scanf("%d", &turns);

    int i, val, ans;
    for (i = 0; i < turns; i++)
    {
        printf("Enter Value : ");
        scanf("%d", &val);

        clock_t start = clock();
        ans = factorial(val);
        clock_t end = clock();

        double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Ans = %d\n", ans);

        printf("CPU time : %lf s\n", timetaken);
    }

    return 0;
}