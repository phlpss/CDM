/*Написати програму, яка реалізує
визначення властивостей бінарного відношення R1, заданого переліком елементів на множині
А={1,2,3,4}, R1 є A^2
Вказати, чи є дане відношення відношенням еквівалентності, толерантності, порядку.


***************************************************************************************************
Рефлексивне - на головній діагоналі 1
Іррефлексивне - на головній діагоналі нулі
Не рефлексивне - ні Рефлексивне, ні Іррефлексивне

Симетричне = неорієнтований граф
Антисиметричне = кожен [i][j] != [j][k]
Асиметричне = антисиметрична і рефлексивна матриця
Не симетрична - ні симетричні, ні антисиметрична

Транзитивна - якщо з 1 рядка можна потрапити в 3, а з 3 в 2, то і з 1 можна потрапити в 2(приклад)
Щоб перевірити на транзитивність, то помножити матрицю саму на себе, і якщо не з'являється додаткових одиниць,
то відношення транзитивне
Антитранзитивне - якщо хоча б десь з'являється нова 1 і 1 міняються на 0
***************************************************************************************************

Відношення еквівалентним, коли воно є рефлексивним, симетричним і транзитивним
Відношення порядку -- транзитивність і антисиметричність
Відношення толерантності, коли воно є рефлексивним, симетричним і антитранзитивним

R = {(2,2),(2,3),(2,4),(3,2),(3,3),(3,4)}

*/

#include <stdio.h>
#define M 10
void TakeInput(int matrix[][M], int *size);
void PrintGraph(int matrix[][M], int size);
int IsReflective(int matrix[][M], int size);
int IsSymmetrical(int matrix[][M], int size);
int IsTransitive(int matrix[][M], int size);

int main(void)
{
    int sizeOfMatrix = 4;
    int relation[M][M] = {{0, 0, 0, 0},
                          {0, 1, 1, 1},
                          {0, 1, 1, 1},
                          {0, 0, 0, 0}};


    PrintGraph(relation, sizeOfMatrix);
    int isReflective = IsReflective(relation, sizeOfMatrix);
    int isSymmetrical = IsSymmetrical(relation, sizeOfMatrix);
    int isTransitive = IsTransitive(relation, sizeOfMatrix);

    switch (isReflective)
    {
    case 1:
        printf("Relation is Reflective.\n");
        break;
    case -1:
        printf("Relation is Irreflective.\n");
        break;
    case 0:
        printf("Relation isn`t Reflective.\n");
        break;
    default:
        printf("You are an Idiot. How did you do that!?");
        break;
    }

    switch (isSymmetrical)
    {
    case 1:
        printf("Relation is Symmetrical.\n");
        break;
    case -1:
        printf("Relation is Antisymmetrical.\n");
        break;
    case 2:
        printf("Relation is Asymmetrical.\n");
        break;
    case 0:
        printf("Relation isn't Symmetrical.\n");
        break;
    default:
        printf("You are an Idiot. How did you do that!?");
        break;
    }

    switch (isTransitive)
    {
    case 1:
        printf("Relation is Transitive.\n");
        break;
    case -1:
        printf("Relation is Antitransitive.\n");
        break;
    case 0:
        printf("Relation isn't Transitive.\n");
        break;
    default:
        printf("You are an Idiot. How did you do that!?");
        break;
    }

    if (isReflective == 1 && isSymmetrical == 1 && isTransitive == 1) 
        printf("This is Equivalence relation.\n");
    
    else if (isTransitive == 1 && (isSymmetrical == -1 || isSymmetrical == 2))
        printf("This is Order relation.\n");

    else if (isReflective == 1 && isSymmetrical == 1 && isTransitive == -1)
        printf("This is Tolerance relation.\n");

    else
        printf("This isn't Equivalence, Order or Tolerance relation.");

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

}

int IsReflective(int matrix[][M], int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if(matrix[i][i] == 1)
            k++;
    }
    if ( k == size)
        return 1;
    else if (k == 0)
        return -1;
    else
        return 0;
}

int IsSymmetrical(int matrix[][M], int size) {
    int k = ((size*size) - size)/2;
    int k2 = k;

    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (matrix[i][j] == matrix[j][i]) {
                k--;
            }
        }
    }
    
    if (k == 0) 
        return 1;
    else if (IsReflective(matrix, size) == 1 && k == k2)
        return 2;
    else if (k == k2)
        return -1;
    else
        return 0;
}

int IsTransitive(int matrix[][M], int size) {
    int multiplied[M][M] = {0}, n = 0, m = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(matrix[i][j] == 1)
                m++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            multiplied[i][j] = 0;
            for (int k = 0; k < size; k++)
            {
                multiplied[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 0 && multiplied[i][j] == 1)
                    n = 1;
            if (matrix[i][j] == 1 && multiplied[i][j] == 0)
                m--;
        }
    }

    if(n == 0)
        return 1;
    else if (m == 0)
        return -1;
    else
        return 0;
}