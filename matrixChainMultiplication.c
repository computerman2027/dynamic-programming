#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void matrixchainmultiplication(int *arr, int n, int **m, int **s)
{
    int i, j, l, k, q;

    for (i = 0; i < n; i++)
    {
        m[i] = (int *)calloc(n, sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        s[i] = (int *)calloc(n, sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++)
    { 
        for (i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + (arr[i] * arr[k + 1] * arr[j + 1]);

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalOutput(int **s, int i, int j)
{
    if (i == j)
    {
        printf("A%d", i + 1);
    }
    else
    {
        printf("( ");
        printOptimalOutput(s, i, s[i][j]);
        printf(" * ");
        printOptimalOutput(s, s[i][j] + 1, j);
        printf(" )");
    }
}

int main()
{
    int n;
    printf("Enter no of Matrices: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    int i, row, col;

    for (i = 0; i < n; i++)
    {
        printf("Enter Row of matrix %d: ", (i + 1));
        scanf("%d", &row);
        printf("Enter Col of matrix %d: ", (i + 1));
        scanf("%d", &col);

        if (i == 0)
        {
            arr[0] = row;
            arr[1] = col;
        }
        else
        {
            if (arr[i] != row)
            {
                printf("Invalid input. Matrix dimensions do not match.\n");
                free(arr);
                return 0;
            }
            arr[i + 1] = col;
        }
    }

    int **m = (int **)malloc(n * sizeof(int *));
    int **s = (int **)malloc(n * sizeof(int *));

    matrixchainmultiplication(arr, n, m, s);

    printf("ANS : ");
    printOptimalOutput(s, 0, n - 1);
    printf("\n");

    return 0;
}
