#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int fibonacci1(int termno, long long int *m) // using memorization technique (Top Down Approach)
{
    if (termno <= 1)
        return termno;

    if (m[termno] != -1)
        return m[termno];

    m[termno] = fibonacci1(termno - 1, m) + fibonacci1(termno - 2, m);
    return m[termno];
}

long long int fibonacci2(int termno)
{
    if (termno <= 1)
        return termno;

    long long int *dp = (long long int *)malloc((termno + 1) * sizeof(long long int));
    dp[0] = 0;
    dp[1] = 1;
    int i;
    for (i = 2; i <= termno; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[termno];
}

int main()
{
    int range, val;
    long long int fibo1, fibo2;
    clock_t start, end;
    double time1, time2;
    printf("Enter maximum range of terms : ");
    scanf("%d", &range);

    long long int *mem = (long long int *)malloc((range + 1) * sizeof(long long int));
    int i;
    for (i = 0; i < range + 1; i++)
        mem[i] = -1;

    for (i = 0; i < 4; i++)
    {
        printf("Enter Term no : ");
        scanf("%d", &val);

        start = clock();
        fibo1 = fibonacci1(val - 1, mem);
        end = clock();
        time1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        start = clock();
        fibo2 = fibonacci2(val - 1);
        end = clock();
        time2 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Fibonacci number using func 1 for %d is %lld\n", val, fibo1);
        printf("Fibonacci number using func 2 for %d is %lld\n", val, fibo2);
        printf("Time required for func 1 is %lf s and func 2 is %lf s\n", time1, time2);
    }

    return 0;
}