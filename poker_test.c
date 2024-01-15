#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
double poker_test(int* data, int n) {
int i;
int digits[10] = {0};
int runs = 0;
double p_value, chi_square;
for (i = 0; i< n; i++) {
digits[data[i]]++;
}
for (i = 0; i< 10; i++) {
if (digits[i] >= 2) {
runs += (digits[i] * (digits[i] - 1)) / 2;
}
}
chi_square = (double) (4 * n - runs) / (double) n;
p_value = 1 - exp(-chi_square);
return p_value;
}
int main(void) {
// Seed the random number generator with the current time
srand(time(NULL));
// Generate random data
int i,n = 10; // Change this to the desired size of the dataset
int* data = (int*)malloc(n * sizeof(int));
printf("Generated Data: ");
for (i = 0; i< n; i++) {
data[i] = rand() % 10; // Random number between 0 and 9
printf("%d ", data[i]);
}
printf("\n");
double p_value = poker_test(data, n);
printf("Poker test p-value: %f\n", p_value);
free(data);
return 0;
}