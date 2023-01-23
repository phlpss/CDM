#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define M 15
void TakeInput(int matrix[][M], int *size);
void PrintGraph(int matrix[][M], int size);

int sizeOfG = 8, cost = 0;
int completed[M] = {0};

// int graph[M][M];
// int sizeOfG = 0, cost = 0;

int main()
{

    int graph[M][M] = {{0, 1, 2, 3, 5, 4, 2, 3},
                       {1, 0, 6, 5, 4, 6, 5, 4},
                       {2, 6, 0, 3, 3, 5, 2, 2},
                       {3, 5, 3, 0, 1, 6, 1, 5},
                       {5, 4, 3, 1, 0, 2, 4, 5},
                       {4, 6, 5, 6, 2, 0, 6, 2},
                       {2, 5, 2, 1, 4, 6, 0, 7},
                       {3, 4, 2, 5, 5, 2, 7, 0}};

    // TakeInput(graph, &sizeOfG);
    PrintGraph(graph, sizeOfG);
    printf("\n\nThe Path is:\n");

    int minInd = 0;
    int complited[M] = {0};

    for (int i = 0; i < sizeOfG - 1; i++)
    {
        int tempInd = 0;
        int min = M;
        for (int j = 0; j < sizeOfG; j++)
        {
            int counter = 0;
            for (int k = 0; k < sizeOfG; k++)
            {
                if (complited[k] == j)
                {
                    counter = 1;
                    break;
                }
            }
            if (graph[minInd][j] < min && counter != 1)
            {
                min = graph[minInd][j];
                tempInd = j;
            }
        }
        if (min == M)
            min = 0;
        cost += min;
        minInd = tempInd;
        complited[i + 1] = minInd;
    }
    cost += graph[minInd][0];
    for (int i = 0; i < sizeOfG; i++)
    {
        printf("%d--->", complited[i] + 1);
    }
    printf("%d", complited[0] + 1);
    printf("\n\nMinimum cost is %d\n ", cost);

    return 0;
}

void TakeInput(int matrix[][M], int *size)
{
    printf("Enter number of vertixes: ");
    scanf("%d", size);
    printf("Set values of matrix(only 0 and 1):\n");

    for (int i = 0; i < *size; i++)
    {
        printf("Column %d:\n", i + 1);
        for (int j = 0; j < *size; j++)
            scanf("%d", &matrix[i][j]);
        printf("\n");
    }
}

void PrintGraph(int matrix[][M], int size)
{
    printf("Graph:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
