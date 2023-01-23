#include <stdio.h>
#include <stdlib.h>
#define N 100
void TakeInput(int array[N], int *size);
int i = 0;

struct Node {
    int value;
    struct Node *next;
};

void CreateNodeListFromArr(struct Node **first, int A[], int n);
void CreateNodeList(struct Node **first, int sizeP);

void ShowList(struct Node *p);
int MinNode(struct Node *first);
void PruferCode(struct Node *firstP, struct Node *firstV, int sizeP, int PArr[]);
void DeleteNode(struct Node **head_ref, int key);
void RemoveFirstNode(struct Node **head);
int GetSizeOfList(struct Node *head);

int main(void)
{
    struct Node *P = NULL;
    struct Node *V = NULL;

    int sizeP = 10, sizeV = 0;
    int PArr[N] = {1, 9, 1, 8, 1, 7, 1, 6, 1, 5};
    PruferCode(P, V, sizeP, PArr);

    return 0;
}

void TakeInput(int array[N], int *size) {
    printf("Enter number of elements in array: ");
    scanf("%d", size);
    printf("Set values of matrix:\n");

    for (int i = 0; i < *size; i++)
        scanf("%d", &array[i]);
}

void CreateNodeList(struct Node **first, int sizeP) {
    int n = sizeP + 2;
    struct Node *fnNode, *last;
    int value = 1, i;
    *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *first;

    if (temp == NULL) {
        printf(" Memory can not be allocated.");
    }

    else {
        temp->value = value;
        (*first)->next = NULL; 
        last = temp;

        // Creating n nodes and adding to linked list
        for (i = 2; i <= n; i++) {
            fnNode = (struct Node *)malloc(sizeof(struct Node));
            if (fnNode == NULL) {
                printf(" Memory can not be allocated.");
                break;
            }
            else {
                value++;
                fnNode->value = value; 
                fnNode->next = NULL;   
                last->next = fnNode; 
                last = last->next;
            }
        }
    }
    ShowList(temp);
}

void CreateNodeListFromArr(struct Node **first, int A[], int sizeP) {
    int i;
    *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fnNode = NULL;
    struct Node *last = *first;
    struct Node *temp = *first;

    if (temp == NULL) {
        printf("Memory can not be allocated.");
    }

    temp->value = A[0];
    (*first)->next = NULL;

    for (i = 1; i < sizeP; i++) {
        fnNode = (struct Node *)malloc(sizeof(struct Node));
        if (fnNode == NULL) {
            printf("Memory can not be allocated.");
            break;
        }
        else {
            fnNode->value = A[i];
            fnNode->next = NULL;
            last->next = fnNode;
            last = fnNode;
        }
    }
    ShowList(temp);
}

void ShowList(struct Node *first)
{
    while (first != NULL)
    {
        printf("%d ", first->value);
        first = first->next;
    }
    printf("\n");
}

int MinNode(struct Node *first)
{
    int min = 100;
    while (first != NULL)
    {
        if (min > first->value)
            min = first->value;
        first = first->next;
    }
    return min;
}

void PruferCode(struct Node *firstP, struct Node *firstV, int sizeP, int PArr[]) {
    CreateNodeListFromArr(&firstP, PArr, sizeP);
    CreateNodeList(&firstV, sizeP);

    int num = sizeP + 2, null = 0, k = 0, i = 0;
    int minElement = 0, pruferArr[N][2];
    struct Node *tempP = firstP;
    struct Node *tempV = firstV;
    struct Node *newTempV = tempV;
    int numOfNodes = GetSizeOfList(tempV) - 2;

    minElement = MinNode(tempV);
    while(tempP != NULL) {     // 12 iteration
        k = 0;
        while (tempP != NULL) {
            if (minElement == tempP->value)
                k++;
            tempP = tempP->next;
        }
        tempP = firstP;

        if (k != 0) {
            newTempV = newTempV->next;
            minElement = newTempV->value;
            continue;
        }
        else {       
            pruferArr[i][1] = minElement;
            DeleteNode(&tempV, minElement);

            pruferArr[i][0] = tempP->value;
            RemoveFirstNode(&tempP);
            firstP = tempP;
            i++;
            minElement = MinNode(tempV);
            newTempV = tempV;
        }

    }

    pruferArr[numOfNodes][0] = tempV->value;
    pruferArr[numOfNodes][1] = tempV->next->value;
    for (int i = 0; i <= numOfNodes; i++) {
        printf("(%d - %d)\n", pruferArr[i][0], pruferArr[i][1]);
    }


}

void RemoveFirstNode(struct Node **head) {
  struct Node *tmp;
  if(head == NULL || *head == NULL) return;
  tmp = *head;

  *head = (*head)->next;
  free(tmp);
}

int GetSizeOfList(struct Node *head) {
    int k = 0;
    while (head) {
        k++;
        head = head->next;
    }
    return k;
}

void DeleteNode(struct Node** first, int value)
{
    struct Node *temp = *first, *prev;
 
    // If value == first element of head
    if (temp && temp->value == value) {
        *first = temp->next; 
        free(temp);
        return;
    }
 
    while (temp && temp->value != value) {
            prev = temp;
            temp = temp->next;
    }
 
    // If key was not present in linked list
    if (!temp)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}



