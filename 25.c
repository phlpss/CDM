//////////////////////////////////////////////////////////////////////////////////////////////// TASK 5 ///////////////////////////////////////////////////////////////////////////////////////////////////

// Написати програму, яка реалізує обчислення матриць суміжності орграфа - доповнення,
// орграфа - перетину G∩H та орграфа - об’єднаня GUH, ваги дуг не брати до уваги, орграф H – варіант k + 1).

// Програма має передбачати такі можливості :
//  реалізацію введення структури орграфа за рахунок побудови матриці суміжності;
//  реалізацію обчислення та виведення матриць суміжності орграфа - доповнення, орграф-перетину та орграфа - об’єднання;
//  виведення кількості вузлів та дуг вказаних графів;
//  перевірку на некоректне введення даних.

#include <stdio.h>
#define M 15
void TakeInput(int matrix[][M], int *size);
void PrintGraph(int matrix[][M], int size);
void NotGraph(int matrix[][M], int size);
void Intersection(int matrix[][M], int matrixH[][M], int size);
void Comb(int matrix[][M], int matrixH[][M], int size);
int notG[M][M], sizeOfG = 6, intersection[M][M], comb[M][M];
int G[M][M], H[M][M];

int main(void)
{
    int G[M][M] = {{0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 0, 1},
                   {0, 1, 0, 0, 1, 0},
                   {0, 1, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0, 0}};

    int H[M][M] = {{0, 1, 0, 1, 0, 1},
                   {0, 0, 1, 0, 1, 0},
                   {0, 0, 0, 0, 0, 1},
                   {0, 0, 1, 0, 1, 0},
                   {0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0, 0}};

    // TakeInput(G, &sizeOfG);
    // TakeInput(H, &sizeOfG);
    PrintGraph(G, sizeOfG);
    PrintGraph(H, sizeOfG);

    NotGraph(G, sizeOfG);
    Intersection(G, H, sizeOfG);
    Comb(G, H, sizeOfG);
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
    int edges = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
            if (matrix[i][j] == 1)
                edges++;
        }
        printf("\n");
    }
    printf("\nNumber of edges: %d\n", edges);
    printf("Number of vertices: %d\n", size);
    printf("----------------------------->\n\n");
}

void NotGraph(int matrix[][M], int size)
{
    printf("Graph-addition of G:\n");
    int notGraph[M][M];
    int edges = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                notGraph[i][j] = 0;
                printf("%d ", notGraph[i][j]);
                continue;
            }
            if (matrix[i][j] == 1)
                notGraph[i][j] = 0;
            else
            {
                notGraph[i][j] = 1;
                edges++;
            }
            printf("%d ", notGraph[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of edges: %d\n", edges);
    printf("Number of vertices: %d\n", size);
    printf("----------------------------->\n\n");
}

void Intersection(int matrix[][M], int matrixH[][M], int size)
{
    printf("Graph-intersection of G and H:\n");
    int intersection[M][M];
    int edges = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1 && matrixH[i][j] == 1)
            {
                intersection[i][j] = 1;
                edges++;
            }
            else
                intersection[i][j] = 0;
            printf("%d ", intersection[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of edges: %d\n", edges);
    printf("Number of vertices: %d\n", size);
    printf("----------------------------->\n\n");
}

void Comb(int matrix[][M], int matrixH[][M], int size)
{
    printf("Graph-combination of G and H:\n");
    int edges = 0, comb[M][M];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                comb[i][j] = 0;
                printf("%d ", comb[i][j]);
                continue;
            }
            if (matrix[i][j] == 1 || matrixH[i][j] == 1)
            {
                comb[i][j] = 1;
                edges++;
            }

            else
                comb[i][j] = 0;
            printf("%d ", comb[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of edges: %d\n", edges);
    printf("Number of vertices: %d\n", size);
    printf("----------------------------->\n\n");
}
