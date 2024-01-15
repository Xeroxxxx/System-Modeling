#include <stdio.h>
#include <math.h>
double calculateChiSquare(int observed[], int expected[], int categories) {
double chiSquare = 0.0;
int i;
for (i = 0; i< categories; i++) {
double observed_i = (double)observed[i];
double expected_i = (double)expected[i];
chiSquare += pow(observed_i - expected_i, 2) / expected_i;
}
return chiSquare;
}
int main() {
int i,categories;
printf("Enter the number of categories: ");
scanf("%d", &categories);
int observed[categories];
int expected[categories];
printf("Enter observed frequencies for each category:\n");
for (i = 0; i< categories; i++) {
printf("Category %d: ", i + 1);
scanf("%d", &observed[i]);
}
printf("Enter expected frequencies for each category:\n");
for (i = 0; i< categories; i++) {
printf("Category %d: ", i + 1);
scanf("%d", &expected[i]);
}
double chiSquare = calculateChiSquare(observed, expected, categories);
printf("\nChi-Square Statistic: %lf\n", chiSquare);
return 0;
}