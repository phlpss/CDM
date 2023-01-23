#include <stdio.h>
#define M 15
void PrintGraph(int[][M], int size);
void NotGraph(int[][M], int size);
void Intersection(int[][M], int[][M], int size);
void Comb(int[][M], int[][M], int size);
void TakeInput(int[][M], int *size);

int graph[M][M], graphH[M][M], notGraph[M][M], intersection[M][M], comb[M][M];
int sizeOfG = 6, sizeOfH = 8;
// int sizeOfG = 0, sizeOfH = 0;

int main(void)
{

    int graph[M][M] = {{0, 1, 0, 0, 0, 0},
                       {1, 0, 1, 1, 1, 1},
                       {0, 1, 0, 1, 1, 1},
                       {0, 1, 1, 0, 1, 1},
                       {0, 1, 1, 1, 0, 1},
                       {0, 1, 1, 1, 1, 0}};

    int graphH[M][M] = {{0, 1, 0, 1, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 1, 0, 1},
                        {1, 0, 0, 0, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0, 0, 1},
                        {0, 0, 1, 0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 0, 1, 0, 1},
                        {0, 0, 1, 0, 1, 0, 1, 0}};

    // fill in the matrixes
    // TakeInput(graph, &sizeOfG);
    // TakeInput(graphH, &sizeOfH);

    PrintGraph(graph, sizeOfG);
    PrintGraph(graphH, sizeOfH);
    NotGraph(graph, sizeOfG);
    Intersection(graph, graphH, sizeOfG);
    Comb(graph, graphH, sizeOfH);
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
    printf("\nNumber of edges: %d\n", edges / 2);
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
    printf("\nNumber of edges: %d\n", edges / 2);
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
    printf("\nNumber of edges: %d\n", edges / 2);
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
    printf("\nNumber of edges: %d\n", edges / 2);
    printf("Number of vertices: %d\n", size);
    printf("----------------------------->\n\n");
}
