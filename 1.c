#include <stdio.h>
#include <Windows.h>
#define size 5

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int function[size][2] = {{1, 5}, {2, 2}, {3, 1}, {4, 3}, {5, 3}};
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5] = {1, 2, 3, 4, 5};
    int arr4[5] = {1, 2, 3, 4, 5};
    int flag1, flag2 = 0;
    int a, b = 0;

    // printf("Enter pair lists\n");
    /* for (int i = 0; i < size; i++)
         for (int j = 0; j < 2; j++)
             scanf_s("%d", &function[i][j]);*/

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (function[i][0] == arr1[j])
                arr1[j] = 0;
            if (function[i][1] == arr2[j])
                arr2[j] = 0;
            else if (function[i][1] != arr2[j])
                arr3[j] = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != 0)
        {
            flag1 = 1;
        }
        if (arr3[i] == 1)
        {
            flag1 = 1;
            a = i;
        }
        if (arr2[i] != 0)
        {
            flag2 = 1;
            b = i;
        }
    }
    if (flag1 == 1)
        printf("\nThe function isn't an injection\nA pair that breaks the inaccuracy - (%d,%d)\nFixed pair - (%d,%d)\n", a + 1, function[a][1], a + 1, arr4[b]);
    if (flag2 == 1)
    {
        printf("\nFunction Surjective\n");

        for (int i = 0; i < size; i++)
            arr1[i] = arr4[i];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (function[i][1] == arr4[j])
                    arr4[j] = 0;
        printf("Function will be Surjective on a set {");
        for (int i = 0; i < size; i++)
        {
            if (arr4[i] != arr1[i])
                arr4[i] = arr1[i];
            else if (arr4[i] == arr1[i])
                arr4[i] = 0;
            if (arr4[i] != 0)
                printf("%d ", arr4[i]);
        }
        printf("}\n");
    }
    if (flag1 == 0 && flag2 == 0)
        printf("Function isn`t bijection");
}
