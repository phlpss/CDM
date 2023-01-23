/*
Написати програму, яка реалізує знаходження МОД неорієнтованого зваженого
зв'язного графа, заданого ваговою матрицею за алгоритмом Краскала. Етапи
розв'язання задачі виводити на екран.

Крок 1. Упорядкувати множину ребер у порядку зростання ваг: е1, е2,..., ет.

Крок 2. Утворити розбиття множини вершин на одноелементні підмножини: {{v1}, {v2}, …, {vn}}.

Крок 3. Вибирати таке чергове ребро з упорядкованої послідовності ребер, що його кінці містяться
в різних множинах розбиття (це забезпечить відсутність простих циклів). Якщо вибрано ребро
еі={vi, vj}, то множини розбиття об’єднати в одну множину.

Крок 4. Якщо вже вибрано (п-1) ребро (у такому разі всі підмножини розбиття виявляться
об’єднаними в одну), то зупинитися, бо вибрані ребра утворюють мінімальний остов. Інакше
перейти до кроку 3.

 */


#include <stdio.h>
#define M 10
#define N 5
void TakeInput(int matrix[][M], int *size);
void PrintGraph(int matrix[][M], int size);
void MOD(int matrix[][M], int size);

int main(void) {
    // int graph[M][M] = {0}, size = 0;
    // TakeInput(graph, &size)

    int size = 5;
    int graph[M][M] = {{0, 1, 3, 4, 5},
                       {1, 0, 2, 6, 8},
                       {3, 2, 0, 1, 7},
                       {4, 6, 1, 0, 4},
                       {5, 7, 7, 4, 0}};

    PrintGraph(graph, size);
    MOD(graph, size);


return 0;
}

void TakeInput (int matrix[][M], int *size) {
    printf("Enter number of vertixes: ");
    scanf("%d", size);
    printf("Set values of matrix:\n");

    for (int i = 0; i < *size; i++) {
        printf("Column %d:\n", i+1);
        for (int j = 0; j < *size; j++) 
            scanf("%d", &matrix[i][j]);
        printf("\n");
    }
}

void PrintGraph(int array[][M], int size) {
    printf("Graph:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", array[i][j]);
    }
    printf("\n");
}
printf("\n\n");
}

void MOD(int array[][M], int size) {
    int min[M] = {0}, nullCol[M] = {0};

    for (int i = 0; i < size; i++) {
        min[i] = 20;
        for (int j = i + 1; j < size; j++) {
            if (array[i][j] == 0)
                continue;

            if (array[i][j] < min[i]){
                min[i] = array[i][j];
                nullCol[i] = j;
            }
        }
    }

    int k = 0, cost = 0;
    for (int i = 0; i < size; i++) {
        for (int m = 0; m < i; m++) {
            if (i == nullCol[m])  {
                printf("%d ", array[i][m]);
                cost += array[i][m];
            }
            else
                printf("%d ", k);
        }

        for (int j = i; j < size; j++) {
            if(j == nullCol[i])
                printf("%d ", array[i][j]);
            else 
                printf("%d ", k);
        }
        printf("\n");
    }
    printf("\nCost: %d", cost);
}

    // int n = 0;
    // // NullCol(array, size, nullCol);
    // for (int k = 0; k < size - 1; k++) {
    //     if(k = nullCol[i])
    //         array[i+1][k] = 0;
    // }