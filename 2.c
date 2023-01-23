#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int binary[16][4], numbers1[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int numbers2[16] = {999, 0, 2, 3, 4, 5, 0, 0, 8, 9, 0, 11, 0, 0, 0, 15};
    int amount_of_numbers;
    int p[16], q[16], r[16], w[16], res[16];

    for (int i = 0; i < 16; i++)
    {
        if (numbers2[i] == numbers1[i])
            res[i] = 1;
        else
            res[i] = 0;
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 3; j >= 0; j--)
        {
            binary[i][j] = numbers1[i] % 2;
            numbers1[i] /= 2;
        }
    }
    for (int i = 0; i < 16; i++)
    {
        p[i] = binary[i][0];
        q[i] = binary[i][1];
        r[i] = binary[i][2];
        w[i] = binary[i][3];
    }
    // Таблиця істинності
    printf("The truth table:\n");
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", binary[i][j]);
        }
        printf("|%d\n", res[i]);
    }
    // ДДНФ
    printf("Perfect Disjunctive normal form:\n");
    for (int i = 0; i < 16; i++)
    {
        if (res[i])
        {
            if (p[i] != 1)
            {
                printf("(!p ");
            }
            else
            {
                printf("(p ");
            }
            printf("* ");
            if (q[i] != 1)
            {
                printf("!q ");
            }
            else
            {
                printf("q ");
            }
            printf("* ");
            if (r[i] != 1)
            {
                printf("!r ");
            }
            else
            {
                printf("r ");
            }
            printf("* ");
            if (w[i] != 1)
            {
                printf("!w) ");
            }
            else
            {
                printf("w) ");
            }
            if (i != 15)
            {
                printf("| ");
            }
        }
    }
    printf("\n");
    // ДКНФ
    printf("Perfect Conjunctive normal form:\n");
    for (int i = 0; i < 16; i++)
    {
        if (res[i] != 1)
        {
            if (p[i] == 1)
            {
                printf("(!p ");
            }
            else
            {
                printf("(p ");
            }
            printf("* ");
            if (q[i] == 1)
            {
                printf("!q ");
            }
            else
            {
                printf("q ");
            }
            printf("* ");
            if (r[i] == 1)
            {
                printf("!r ");
            }
            else
            {
                printf("r ");
            }
            printf("* ");
            if (w[i] == 1)
            {
                printf("!w) ");
            }
            else
            {
                printf("w) ");
            }
            if (i != 15)
            {
                printf("& ");
            }
        }
    }
}
