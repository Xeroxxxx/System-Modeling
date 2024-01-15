#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 10
int check(int arr[], int num) {
for (int i = 0; i < N; i++) {
if (arr[i] == num) {
return 0; // Number found, not unique
}
}
return 1; // Number is unique
}
void generateRN(int a, int x0, int c, int m) {
int x1;
int arr[N];
for (int i = 0; i < N; i++) {
x1 = (a * x0 + c) % m;
x0 = x1;
if (check(arr, x1) == 1) {
arr[i] = x1;
printf("%d\t", x1);
} else {
printf("\nFinish after repeating sequence\n\n");
break;
}
}
printf("\n------\n");
}
int main(void) {
int a, c, m;
int seed = 27;
while (1) {
puts("Menu:\n1. Additive LCG\n2. Multiplicative LCG\n3. Mixed LCG\n4. Quit");
printf("Enter your choice: ");
scanf("%d", &a); // Read choice into 'a' for simplicity
if (a == 4) {
break; // Quit the program
}
printf("Enter values for a, c, and m (separated by spaces): ");
scanf("%d %d %d", &a, &c, &m);
generateRN(a, seed, c, m);
}
return 0;
}