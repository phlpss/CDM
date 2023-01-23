/////////////////////////////////////////////////////////////////////// Task 1 ///////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdbool.h>
//
// int main()
// {
//     // інізіалізую та задаю булеві значення заданним змінним
//     // створюю пустий масив, якому присвоюватиму значення результату
//     bool p[8] = {0, 0, 0, 0, 1, 1, 1, 1};
//     bool q[8] = {0, 0, 1, 1, 0, 0, 1, 1};
//     bool r[8] = {0, 1, 0, 1, 0, 1, 0, 1};
//     bool C[8];
//     printf("p\tq\tr\tresult\t\n\n");
//
//     // за допомогою ітерації виводжу таблицю у 8 рядків
//     // кожен з результатів знаходжу за спрощеною формулою
//     for (int i = 0; i < 8; i++) {
//         C[i] = !p || ((!q || p) && r);
//         printf("%d  |\t%d   |\t%d   |\t%d   |\n", p[i], q[i], r[i], C[i]);
//     }
//
//     return 0;
// }

/////////////////////////////////////////////////////////////////////// Task 2 ///////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdbool.h>
//
// int main()
// {
//     // інізіалізую та задаю булеві значення змінним
//     bool p[8] = {1, 1, 1, 1, 0, 0, 0, 0};
//     bool q[8] = {1, 1, 0, 0, 1, 1, 0, 0};
//     bool r[8] = {1, 0, 1, 0, 1, 0, 1, 0};
//     bool C[8] = {0, 0, 0, 0, 0, 0, 0, 0};
//     printf("p\tq\tr\tresult\t\n\n");
//
//     for (int i = 0; i < 8; i++){
//         C[i] = (p && !q) || (!p || q || r);
//         printf("%d  |\t%d   |\t%d   |\t%d   |\n", p[i], q[i], r[i], C[i]);
//     }
//
//     if (C[0] == 1 && C[1] == 1 && C[2] == 1 && C[3] == 1 && C[4] == 1 && C[5] == 1 && C[6] == 1 && C[7] == 1)
//         printf("\nВисловлювання є тавтологією");
//     else
//         printf("\nВисловлювання не є тавтологією");
//
//     return 0;
// }

/////////////////////////////////////////////////////////////////////// Task 3 ///////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <stdbool.h>
//
// int main()
// {
//     bool fValue;
//     bool Q[] = {1, 0, 0, 1};
//     fValue = (Q[1] && Q[3]);
//     if (fValue == 0)
//         printf("Формула хибна");
//     else
//         printf("Формула істинна");
//
//     return 0;
// }

/////////////////////////////////////////////////////////////////////// Task 4 ///////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <math.h>
// #include <vector>
//
// using namespace std;
//
// int main()
// {
//     int U[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int A[] = {1, 2, 0, 4, 5, 6, 7, 0, 0, 0};
//     int B[] = {0, 0, 0, 4, 5, 6, 7, 8, 9, 10};
//     int C[] = {0, 2, 0, 4, 0, 6, 0, 8, 0, 10};
//     int arr1[10];
//     int arr2[10];
//     int arr3[10];
//     int dif[10];
//     int cardinal = 0;
//
//     ///////////////////////////////////////////////////////////////// arr1
//     // B U (C \ A)
//     // знайти множини, задані за допомогою операцій
//     // перебрати кожен елемент масиву С і якщо він не належить множині А, внести його в множину dif(різниця)
//     // перебрати кожен елемент масивів В і dif, якщо хоча б один з елементів != 0, то внести це значення в arr1
//    
//     for (int j = 0; j < 10; j++)
//     {
//         if (C[j] != A[j])
//             dif[j] = C[j];
//         else
//             dif[j] = 0;
//     }
//
//     printf("Set 1: ");
//     for (int i = 0; i < 10; i++)
//     {
//         if ((B[i] == U[i]) || (dif[i] == U[i]))
//             arr1[i] = U[i];
//         else
//             arr1[i] = 0;
//         printf("%d ", arr1[i]);
//     }
//
//     ///////////////////////////////////////////////////////////////// arr2
//     // спрощую формулу
//     // (!B \ !C) U (!C \ !B)
//     // створюю масиви для перетину !В і С, для !С і В, для arr2
//
//     int notB[10];
//     int notC[10];
//     int CnotB[10];
//     int BnotC[10];
//
//     for (int i = 0; i < 10; i++)
//     {
//         if (B[i] == 0)
//             notB[i] = U[i];
//         else
//             notB[i] = 0;
//     }
//
//     for (int i = 0; i < 10; i++)
//     {
//         if (notB[i] && C[i] == U[i])
//             CnotB[i] = U[i];
//         else
//             CnotB[i] = 0;
//     }
//
//     for (int i = 0; i < 10; i++)
//     {
//         if (C[i] == 0)
//             notC[i] = U[i];
//         else
//             notC[i] = 0;
//     }
//
//     for (int i = 0; i < 10; i++)
//     {
//         if (notC[i] && B[i] != 0)
//             BnotC[i] = U[i];
//         else
//             BnotC[i] = 0;
//     }
//
//     // arr2 formula
//     printf("\n\nSet 2: ");
//     for (int n = 0; n < 10; n++)
//     {
//         if (CnotB[n] || BnotC[n] == U[n])
//             arr2[n] = U[n];
//         else
//             arr2[n] = 0;
//         printf("%d ", arr2[n]);
//     }
//
//     ///////////////////////////////////////////////////////////////// arr3
//     // A ^ B \ C
//     int intersection[10];
//
//     for (int i = 0; i < 10; i++)
//     {
//         if (A[i] && B[i] != 0)
//             intersection[i] = U[i];
//         else
//             intersection[i] = 0;
//         // printf("%d ", intersection[i]);
//     }
//
//     // printf("\n");
//     printf("\n\nSet 3: ");
//     for (int i = 0; i < 10; i++)
//     {
//         if (intersection[i] != 0 && intersection[i] != C[i])
//             arr3[i] = U[i];
//         else
//             arr3[i] = 0;
//         printf("%d ", arr3[i]);
//     }
//
//     vector<int> powerSet;
//     printf("\n\nArr3 without 0: ");
//     for (int i = 0; i < 10; i++)
//     {
//         if (arr3[i] != 0)
//         {
//             printf("%d ", arr3[i]);
//             powerSet.push_back(arr3[i]);
//         }
//         else
//             continue;
//         ;
//     }
//
//     // // потужінсть arr3
//     printf("\n\nCardinal of set 3: %d\n\n", powerSet.size());
//     printf("Power set:\n");
//
//     unsigned int powSetSize = pow(2, powerSet.size()); // розмір булеану arr3
//
//     vector<vector<int>> arrays;
//     vector<int> empty;
//     arrays.push_back(empty);
//
//     for (int i = 0; i < powerSet.size(); i++)
//     {
//         int size = arrays.size();
//         for (int j = 0; j < size; j++)
//         {
//             vector<int> vect = arrays.at(j);
//             vect.push_back(powerSet.at(i));
//             arrays.push_back(vect);
//         }
//     }
//
//     for (int i = 0; i < arrays.size(); i++)
//     {
//         vector<int> vect = arrays.at(i);
//         printf("{");
//         for (int j = 0; j < vect.size(); j++)
//         {
//             printf(" %d ", vect.at(j));
//         }
//         printf("}\n\n");
//     }
//
//     return 0;
// }

/////////////////////////////////////////////////////////////////////// Task 6 ///////////////////////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
//
// int main() {
//     int a = 56, b = 19, c = 30, d = 40, e = 10, f = 15, g = 15;
//     int all, AUB, BUC, AUC, onlyText, onlyGraphic, onlySymbol;
//
//     all = a - (b + c + d - e - f - g);
//     if (all > 0 && all < a && all < b && all < c && all < d && all < e && all < f && all < g){
//         printf("Кількість мікропроцесорів, які одночасно обробляють графічну, текстову та символьну інформацію: %d\n\n", all);
//       
//         AUB = b + c - e;
//         BUC = c + d - g;
//         AUC = b + d - f;
//         printf("|A U B| = %d\n", AUB);
//         printf("|B U C| = %d\n", BUC);
//         printf("|A U C| = %d\n", AUC);
//
//         onlyText = a - BUC;
//         onlyGraphic = a - AUC;
//         onlySymbol = a - AUB;
//         printf("Обробляють лише текстову інформацію: %d\n", onlyText);
//         printf("Обробляють лише графічну інформацію: %d\n", onlyGraphic);
//         printf("Обробляють лише символьну інформацію: %d\n", onlySymbol);
//     }
//
//     else
//         printf("Така реалізація EOM неможлива");
//
//     return 0;
// }