/*
Написати програму, яка реалізує побудову дерева за заданим кодом Прюфера. Етапи розв'язання задачі виводити на екран.

Алгоритм побудови дерева за заданим кодом Прюфера (розпакування коду Прюфера дерева):
Вхід: Масив int А[n-1] of 1..n - код Прюфера дерева Т.
Вихід: Дерево Т(V, Е), задане множиною ребер Е, вершини дерева пронумеровані числами 1..n.
E= ; // спочатку множина ребер порожня;
B=1..n; // множина невикористаних номерів вершин;
for (i=1; i<=n-1; i++) {
v=min (k B && j  i : k! A[ j]);
// вибираємо вершину v – невикористану вершину з найменшим номером, який не зустрічається в коді Прюфера
;
E = E + (v, A[i]); // додаємо ребро (v, A[i]);
B = B - v;         // вилучаємо вершину v зі списку невикористаних;
}
*/

#include <stdio.h>
#include <stdlib.h>
#define N 100
void TakeInput(int array[N], int *size);

struct Node {
    int value;
    struct Node *next;
};

void createNodeListFromArr(struct Node *first, int A[], int n);
void createNodeList(struct Node *first, int sizeP);
void ShowList(struct Node *p);
int MinNode(struct Node *first);
void PruferCode(struct Node *firstP, struct Node *firstV, int sizeP, int PArr[]);

int main(void)
{
    // int P[N] = {0};
    // int size1 = 0;
    // TakeInput(P, &size);

    struct Node *P = NULL;
    struct Node *V = NULL;

    int sizeP = 10, sizeV = 0;
    int PArr[N] = {1, 9, 1, 8, 1, 7, 1, 6, 1, 5};
    // createNodeListFromArr(P, PArr, sizeP);
    // createNodeList(V, sizeP);
    PruferCode(P, V, sizeP, PArr);

    return 0;
}

void TakeInput(int array[N], int *size)
{
    printf("Enter number of elements in array: ");
    scanf("%d", size);
    printf("Set values of matrix:\n");

    for (int i = 0; i < *size; i++)
        scanf("%d", &array[i]);
}

void createNodeList(struct Node *first, int sizeP) {
    int n = sizeP + 2;
    struct Node *fnNode, *last;
    int value = 1, i;
    first = (struct Node *)malloc(sizeof(struct Node));

    if(first == NULL) {
        printf(" Memory can not be allocated.");
    }

    else
    {
        first->value = value;      
        first->next = NULL; // links the address field to NULL
        last = first;

// Creating n nodes and adding to linked list
        for(i = 2; i <= n; i++) {
            fnNode = (struct Node *)malloc(sizeof(struct Node));
            if(fnNode == NULL) {
                printf(" Memory can not be allocated.");
                break;
            }
            else {
                value++;

                fnNode->value = value;      // links the value field of fnNode with val
                fnNode->next = NULL; // links the address field of fnNode with NULL
 
                last->next = fnNode; // links previous node i.e. last to the fnNode
                last = last->next; 
            }
        }
    }
    ShowList(first);
}

void createNodeListFromArr(struct Node *first, int A[], int n)
{
    int i;
    struct Node *fnNode, *last;
    first = (struct Node *) malloc(sizeof(struct Node));

    if(first == NULL) {
        printf(" Memory can not be allocated.");
    }

    first -> value = A[0];
    first -> next = NULL;
    last = first;
    for (i = 1; i < n; i++) {
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if(fnNode == NULL) {
                printf(" Memory can not be allocated.");
                break;
            }
        else {
            fnNode->value = A[i];
            fnNode->next = NULL;
            last->next = fnNode;
            last = fnNode;
        }
    }
    ShowList(first);
}

void ShowList(struct Node *first) {
    while (first != NULL) {
        printf("%d ", first -> value);
        first = first -> next;
    }
    printf("\n");
}

int MinNode(struct Node* first) {
    int min = 100;
    while (first != NULL) {
        if (min > first->value)
            min = first->value;
        first = first->next;
    }
    return min;
}

void PruferCode(struct Node *firstP, struct Node *firstV, int sizeP, int PArr[]) {
    // get min value in V --- check if in P there is such an item --> if there is no such an item in P, delete this item from VList
    //                                                            --> if there is an item in P, go to next item

    createNodeListFromArr(firstV, PArr, sizeP);
    createNodeList(firstV, sizeP);

    int num = sizeP + 2, null = 0;
    int minElement = 0, newV[N] = {0};

    while(firstV != NULL) {
        minElement = MinNode(firstV);
        for (int i = 0; i < num; i++) {
            if (minElement == newV[i]) {
                continue;
            }
            else {
                newV[i + 1] = minElement;
            }
        }
            minElement = MinNode(firstV);
    }
        // while(firstP != NULL) {                 // 10 iteration over P
        //     if (minElement != firstP->value) {
        //         newV[i] = minElement;
        //     }
        //     else {
        //         newV[i] = 0;
        //         continue;
        //     }

        // printf("E1 = (%d, %d)", firstP, minElement[i]);
        // newV[i] = minElements[i];
        }   
//         firstP = firstP->next;
// }


