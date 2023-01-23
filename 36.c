/*Написати програму (на будь-якій відомій студентові мові програмування), яка реалізує обчислення
матриць перетину, об’єднання, різниці, симетричної різниці, доповнення, обернених, композицій
1 2 2 1 R R R R   , двох бінарних відношень, заданих на множині А = {a, b, c} (таблиця 3.6). У випадку
подання відношень переліком елементів спочатку записати їх матрицями.


R1={(a,b), (b,c), (c,b), (c,c)},
R2={(a,a), (a,b), (a,c), (b,b), (c,c)}

*/

#include <stdio.h>
#define M 10

void PrintGraph(int[][M], int size);
void NotGraph(int[][M], int size);
void Intersection(int[][M], int[][M], int size);
void Union(int[][M], int[][M], int size);
void TakeInput(int[][M], int *size);
void Difference(int matrix1[][M], int matrix2[][M], int size);
void SymmetricalDiff(int matrix1[][M], int matrix2[][M], int size);
void Transposition(int matrix[][M], int size);
void Composition(int matrix1[][M], int matrix2[][M], int size);

int main(void)
{

    int sizeOfMatrix = 3;
    int relation1[M][M] ={{0, 1, 0},
                          {0, 0, 1},
                          {0, 1, 1}};

    int relation2[M][M] = {{1, 1, 1},
                           {0, 1, 0},
                           {0, 0, 1}};

    printf("R1:\n");
    PrintGraph(relation1, sizeOfMatrix);
    printf("R2:\n");
    PrintGraph(relation2, sizeOfMatrix);

    printf("Graph-intersection of R1 and R2:\n");
    Intersection(relation1, relation2, sizeOfMatrix);

    printf("Graph-union of R1 and R2:\n");
    Union(relation2, relation1, sizeOfMatrix);

    printf("Graph-difference of R1 and R2:\n");
    Difference(relation1, relation2, sizeOfMatrix);

    printf("Graph-difference of R2 and R1:\n");
    Difference(relation2, relation1, sizeOfMatrix);

    printf("Graph Symmetrical difference of R1 and R2:\n");
    SymmetricalDiff(relation1, relation2, sizeOfMatrix);

    printf("Not Graph of R1:\n");
    NotGraph(relation1, sizeOfMatrix);

    printf("Not Graph of R2:\n");
    NotGraph(relation2, sizeOfMatrix);

    printf("Transposition of R1:\n");
    Transposition(relation1, sizeOfMatrix);

    printf("Transposition of R2:\n");
    Transposition(relation2, sizeOfMatrix);

    
    printf("Composition of R1 and R2:\n");
    Composition(relation2, relation1, sizeOfMatrix);

    printf("Composition of R2 and R1:\n");
    Composition(relation1, relation2, sizeOfMatrix);

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
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------->\n\n");
}

void NotGraph(int matrix[][M], int size)
{
    int notGraph[M][M];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
                notGraph[i][j] = 0;
            else
            {
                notGraph[i][j] = 1;
            }
            printf("%d ", notGraph[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------->\n\n");
}

void Intersection(int matrix[][M], int matrixH[][M], int size)
{
    int intersection[M][M];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1 && matrixH[i][j] == 1)
            {
                intersection[i][j] = 1;
            }
            else
                intersection[i][j] = 0;
            printf("%d ", intersection[i][j]);
        }
    printf("\n");
    }
    printf("----------------------------->\n\n");
}

void Union(int matrix[][M], int matrixH[][M], int size)
{
    int comb[M][M];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1 || matrixH[i][j] == 1)
            {
                comb[i][j] = 1;
            }

            else
                comb[i][j] = 0;
            printf("%d ", comb[i][j]);
        }
    printf("\n");
    }
    printf("----------------------------->\n\n");
}

void Difference(int matrix1[][M], int matrix2[][M], int size)
{
    int difference[M][M] = {0};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            difference[i][j] = matrix1[i][j];
            if (difference[i][j] == 1 && matrix2[i][j] == 1)
            {
                difference[i][j] = 0;
            }
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------->\n\n");
}

void SymmetricalDiff(int matrix1[][M], int matrix2[][M], int size) {
    int difference1[M][M] = {0}, difference2[M][M] = {0};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            difference1[i][j] = matrix1[i][j];
            if (difference1[i][j] == 1 && matrix2[i][j] == 1)
            {
                difference1[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            difference2[i][j] = matrix1[i][j];
            if (difference2[i][j] == 1 && matrix2[i][j] == 1)
            {
                difference2[i][j] = 0;
            }
        }
    }

    Union(difference1, difference2, size);
}

void Transposition(int matrix[][M], int size) {
    int matrix2[M][M] = {0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix2[i][j] = matrix[j][i];
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------->\n\n");
}

void Composition(int matrix1[][M], int matrix2[][M], int size) {
    int mul[M][M] = {0};
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < size; k++) {
                if(matrix2[k][j] == 1 && matrix1[i][k] == 1)
                    mul[i][j] = 1;
            }
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
    printf("-------------------->\n\n");
}