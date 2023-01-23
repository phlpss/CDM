#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#define N 50
#define M 5

int values[16] = {0}; //{ 0,0,2,3,4,5,0,0,8,9,0,11,0,0,0,15 };

int bin_val[4] = {0};

int isPastingPoss = 0, pos = 0;

int IsInValues(int num);

void toBinary(int num);

void AddToClass(int class[N][M]);

void ClassInit(int class0[][M], int class1[][M], int class2[][M], int class3[][M], int class4[][M]);

void Pasting(int class1[][M], int class2[][M], int class3[][M]);

int IsInClass(int class[][M]);

void AddUnused(int class1_1[][M], int class2_1[][M], int class3_1[][M], int class4_1[][M], int class5_1[][M],
               int class1_2[][M], int class2_2[][M], int class3_2[][M], int class4_2[][M], int class5_2[][M]);

void AddUnusedInClass(int class1[][M], int class2[][M]);

void CDNF_Formation(int class0[][M], int class1[][M], int class2[][M], int class3[][M], int class4[][M], char CDNF[]);

void CDNF_Formation_Class(int class[][M], char CDNF[]);

int main(void) // 999,0,2,3,4,5,0,0,8,9,0,11,0,0,0,15
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Enter the value vector (-1 - end):\n");
    int l = 0, val = 0;
    while (1)
    {
        scanf("%d,", &val);
        if (val == -1)
            break;
        values[l] = val;
        l++;
    }
    for (; l < 16; l++)
    {
        values[l] = -1;
    }

    int class0_1[N][M], class1_1[N][M], class2_1[N][M], class3_1[N][M], class4_1[N][M];
    int class0_2[N][M], class1_2[N][M], class2_2[N][M], class3_2[N][M], class4_2[N][M];

    ClassInit(class0_1, class1_1, class2_1, class3_1, class4_1);
    ClassInit(class0_2, class1_2, class2_2, class3_2, class4_2);

    for (int i = 0; i < 16; i++)
    {
        int numbersOf1 = 0;
        if (IsInValues(i) == 1)
        {
            toBinary(i);
            for (int j = 0; j < 4; j++)
            {
                if (bin_val[j] == 1)
                    numbersOf1++;
            }
            switch (numbersOf1)
            {
            case 0:
                AddToClass(class0_1);
                break;
            case 1:
                AddToClass(class1_1);
                break;
            case 2:
                AddToClass(class2_1);
                break;
            case 3:
                AddToClass(class3_1);
                break;
            case 4:
                AddToClass(class4_1);
                break;
            }
        }
    }

    int n = 2;
    do
    {
        isPastingPoss = 0;
        if (n % 2 == 0)
        {
            Pasting(class0_1, class1_1, class0_2);
            Pasting(class1_1, class2_1, class1_2);
            Pasting(class2_1, class3_1, class2_2);
            Pasting(class3_1, class4_1, class3_2);

            AddUnused(class0_1, class1_1, class2_1, class3_1, class4_1,
                      class0_2, class1_2, class2_2, class3_2, class4_2);

            ClassInit(class0_1, class1_1, class2_1, class3_1, class4_1);
        }

        else
        {
            Pasting(class0_2, class1_2, class0_1);
            Pasting(class1_2, class2_2, class1_1);
            Pasting(class2_2, class3_2, class2_1);
            Pasting(class3_2, class4_2, class3_1);

            AddUnused(class0_2, class1_2, class2_2, class3_2, class4_2,
                      class0_1, class1_1, class2_1, class3_1, class4_1);

            ClassInit(class0_2, class1_2, class2_2, class3_2, class4_2);
        }
        n++;
    } while (isPastingPoss);

    char CDNF[100];
    if (n % 2 == 0)
        CDNF_Formation(class0_1, class1_1, class2_1, class3_1, class4_1, CDNF);

    if (n % 2 == 1)
        CDNF_Formation(class0_2, class1_2, class2_2, class3_2, class4_2, CDNF);

    printf("%s", CDNF);

    return 0;
}

void Pasting(int class1[][M], int class2[][M], int class3[][M])
{
    int i = 0;
    while (class1[i][0] != -1)
    {
        int j = 0;
        while (class2[j][0] != -1)
        {
            int difference = 0;
            for (int k = 0; k < 4; k++)
            {
                if ((class1[i][k] == 2 && class2[j][k] != 2) ||
                    (class1[i][k] != 2 && class2[j][k] == 2))
                {
                    difference += 2;
                    break;
                }
                else if (class1[i][k] != class2[j][k])
                {
                    difference += 1;
                    bin_val[k] = 2;
                }
                else if (class1[i][k] == 2 && class2[j][k] == 2)
                    bin_val[k] = 2;
                else if (class1[i][k] == class2[j][k])
                    bin_val[k] = class1[i][k];
            }
            if (difference == 1)
            {
                isPastingPoss = 1;
                int numbersOf1 = 0;
                for (int k = 0; k < 4; k++)
                {
                    if (bin_val[k] == 1)
                        numbersOf1++;
                }

                class1[i][4] = 2;
                class2[j][4] = 2;

                if (IsInClass(class3))
                {
                    j++;
                    continue;
                }

                AddToClass(class3);
            }
            j++;
        }
        i++;
    }
}

void AddUnusedInClass(int class1[][M], int class2[][M])
{
    for (int i = 0; i < N; i++)
    {
        if (class1[i][0] == -1)
            break;
        else if (class1[i][4] == -1)
        {
            for (int j = 0; j < 4; j++)
            {
                bin_val[j] = class1[i][j];
            }
            AddToClass(class2);
        }
    }
}

void AddUnused(int class1_1[][M], int class2_1[][M], int class3_1[][M], int class4_1[][M], int class5_1[][M],
               int class1_2[][M], int class2_2[][M], int class3_2[][M], int class4_2[][M], int class5_2[][M])
{
    AddUnusedInClass(class1_1, class1_2);
    AddUnusedInClass(class2_1, class2_2);
    AddUnusedInClass(class3_1, class3_2);
    AddUnusedInClass(class4_1, class4_2);
    AddUnusedInClass(class5_1, class5_2);
}

void ClassInit(int class0[][M], int class1[][M], int class2[][M], int class3[][M], int class4[][M])
{
    memset(class0, -1, N * M * sizeof(int));
    memset(class1, -1, N * M * sizeof(int));
    memset(class2, -1, N * M * sizeof(int));
    memset(class3, -1, N * M * sizeof(int));
    memset(class4, -1, N * M * sizeof(int));
}

int IsInClass(int class[][M])
{
    int i = 0;
    int res = 0;
    while (class[i][0] != -1)
    {
        int isInClass = 0;
        for (int j = 0; j < 4; j++)
        {
            if (class[i][j] == bin_val[j])
                isInClass++;
        }
        if (isInClass == 4)
            res = 1;
        i++;
    }
    return res;
}

void AddToClass(int class[N][M])
{
    int i = 0;
    while (class[i][0] != -1)
        i++;
    for (int j = 0; j < 4; j++)
    {
        class[i][j] = bin_val[j];
    }
}

int IsInValues(int num)
{
    int res = -1;
    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
    {
        if (values[i] == num)
            res = 1;
    }
    return res;
}

void toBinary(int num)
{
    int r;
    int i = 0;
    while (num >= 2)
    {
        r = num % 2;
        num = num / 2;
        bin_val[3 - i] = r;
        i++;
    }
    bin_val[3 - i] = num;
}

void CDNF_Formation(int class0[][M], int class1[][M], int class2[][M], int class3[][M], int class4[][M], char CDNF[])
{
    CDNF_Formation_Class(class0, CDNF);
    CDNF_Formation_Class(class1, CDNF);
    CDNF_Formation_Class(class2, CDNF);
    CDNF_Formation_Class(class3, CDNF);
    CDNF_Formation_Class(class4, CDNF);
    CDNF[pos - 1] = '\0';
}

void CDNF_Formation_Class(int class[][M], char CDNF[])
{
    int i = 0;
    while (class[i][0] != -1)
    {
        if (class[i][0] == 1)
        {
            CDNF[pos] = 'p';
            pos++;
        }
        else if (class[i][0] == 0)
        {
            CDNF[pos] = '!';
            pos++;
            CDNF[pos] = 'p';
            pos++;
        }
        if (class[i][1] == 1)
        {
            CDNF[pos] = 'q';
            pos++;
        }
        else if (class[i][1] == 0)
        {
            CDNF[pos] = '!';
            pos++;
            CDNF[pos] = 'q';
            pos++;
        }
        if (class[i][2] == 1)
        {
            CDNF[pos] = 'r';
            pos++;
        }
        else if (class[i][2] == 0)
        {
            CDNF[pos] = '!';
            pos++;
            CDNF[pos] = 'r';
            pos++;
        }
        if (class[i][3] == 1)
        {
            CDNF[pos] = 'm';
            pos++;
        }
        else if (class[i][3] == 0)
        {
            CDNF[pos] = '!';
            pos++;
            CDNF[pos] = 'm';
            pos++;
        }
        CDNF[pos] = '|';
        pos++;
        i++;
    }
}
