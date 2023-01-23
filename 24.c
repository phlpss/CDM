#include <stdio.h>
#define N 15
void TakeInput(int matrix[][N], int *size);
void PrintGraph(int matrix[][N], int size);
void Multiple(int matrix[][N], int matrix2[][N], int mul[][N], int size);
void ReachabilityMatrix(int mat1[][N], int mat2[][N], int mat3[][N], int mat4[][N], int mat5[][N], int mat6[][N], int reach[][N], int size);
void Warshal(int matrix[][N], int size);
int sizeOfG = 6;

int main(void) {
    int m2[N][N], m3[N][N], m4[N][N], m5[N][N], m6[N][N], M[N][N], matrixR[N][N], warshal[N][N];

    int graph[N][N] = {{0, 1, 0, 1, 0, 0},
                       {0, 0, 1, 0, 0, 0},
                       {0, 0, 0, 0, 0, 1},
                       {0, 1, 0, 0, 1, 0},
                       {0, 1, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0}};

    int sizeOfG = 6;

    // int graph[N][N], sizeOfG = 0;
    // TakeInput(graph, &sizeOfG);

    PrintGraph(graph, sizeOfG);

    // знаходження різних степенів матриці суміжності
    printf("Multiple graph ^2:\n");
    Multiple(graph, graph, m2, sizeOfG);
    printf("Multiple graph ^3:\n");
    Multiple(graph, m2, m3, sizeOfG);
    printf("Multiple graph ^4:\n");
    Multiple(graph, m3, m4, sizeOfG);
    printf("Multiple graph ^5:\n");
    Multiple(graph, m4, m5, sizeOfG);
    printf("Multiple graph ^6:\n");
    Multiple(graph, m5, m6, sizeOfG);

    printf("Matrix of reach using multiplication: \n");
    ReachabilityMatrix(graph, m2, m3, m4, m5, m6, matrixR, sizeOfG);
    printf("Matrix of reach using Warshal algorithm :\n");
    Warshal(graph, sizeOfG);
}

void TakeInput (int matrix[][N], int *size) {
    printf("Enter number of vertixes: ");
    scanf("%d", size);
    printf("Set values of matrix(only 0 and 1):\n");

    for (int i = 0; i < *size; i++) {
        printf("Column %d:\n", i+1);
        for (int j = 0; j < *size; j++)
            scanf("%d", &matrix[i][j]);
        printf("\n");
    }
}

void PrintGraph(int matrix[][N], int size)
{
    printf("Graph:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("-------------------->\n\n");
}

void Multiple(int matrix1[][N], int matrix2[][N], int mul[][N], int size) {
    for (int i = 0; i < sizeOfG; i++) {
        for (int j = 0; j < sizeOfG; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < sizeOfG; k++) {
                mul[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
    printf("-------------------->\n\n");
}

void ReachabilityMatrix(int mat1[][N], int mat2[][N], int mat3[][N], int mat4[][N], int mat5[][N], int mat6[][N], int reach[][N], int size) {
    for (int i = 0; i < sizeOfG; i++) {
        for (int j = 0; j<sizeOfG; j++) {
            if ((mat1[i][j] || mat2[i][j] || mat3[i][j] || mat4[i][j] || mat5[i][j] || mat6[i][j]) == 1)
                reach[i][j] = 1;
            else
                reach[i][j] = 0;
            printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
    printf("-------------------->\n\n");
}

void Warshal(int matrix[][N], int size) {
    
    int warshal[N][N], temp[N][N];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            warshal[i][j] = matrix[i][j];
            temp[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (warshal[j][i] == 1) {
                for (int k = 0; k < size; k++) {
                    if (warshal[j][k] == 0 && temp[i][k] == 1)
                        warshal[j][k] = 1;
                }
            }
        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[i][j] = warshal[i][j];
    }
}

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", warshal[i][j]);
        }
        printf("\n");
    }

}
