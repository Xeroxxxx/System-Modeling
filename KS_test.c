#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBERS 20
struct KS {
int n;
float numbers[MAX_NUMBERS];
float D, tabulatedD;
float Dplusmax, Dminusmax;
float Dplus[MAX_NUMBERS], Dminus[MAX_NUMBERS];
float ratio[MAX_NUMBERS], ratiominus[MAX_NUMBERS];
};
void getdata(struct KS *ks) {
printf("How many numbers?:\n");
scanf("%d", &ks->n);
if (ks->n > MAX_NUMBERS || ks->n <= 0) {
printf("Invalid number of inputs. Exiting.\n");
exit(1);
}
printf("Enter %d numbers:\n", ks->n);
for (int i = 0; i < ks->n; i++) {
printf("Enter number %d:\n", i + 1);
scanf("%f", &ks->numbers[i]);
}
}
void BubbleSort(struct KS *ks) {
for (int i = 0; i < ks->n - 1; i++) {
for (int j = 0; j < ks->n - i - 1; j++) {
if (ks->numbers[j] > ks->numbers[j + 1]) {
float temp = ks->numbers[j];
ks->numbers[j] = ks->numbers[j + 1];
ks->numbers[j + 1] = temp;
}
}
}
printf("The numbers in ascending order are:\n");
for (int i = 0; i < ks->n; i++) {
printf("%.2f ", ks->numbers[i]);
}
printf("\n");
}
void calculate(struct KS *ks) {
for (int i = 0; i < ks->n; i++) {
int j = i + 1;
ks->ratio[i] = (float)j / ks->n;
ks->ratiominus[i] = (float)i / ks->n;
ks->Dplus[i] = ks->ratio[i] - ks->numbers[i];
ks->Dminus[i] = ks->numbers[i] - ks->ratiominus[i];
}
}
void display(struct KS *ks) {
printf("\n\n");
printf("%10s", "i");
for (int i = 1; i <= ks->n; i++) {
printf("%10d", i);
}
printf("\n");
printf("%10s", "R(i)");
for (int i = 0; i < ks->n; i++) {
printf("%10.2f", ks->numbers[i]);
}
printf("\n");
printf("%10s", "i/n");
for (int i = 0; i < ks->n; i++) {
printf("%10.2f", ks->ratio[i]);
}
printf("\n");
printf("%10s", "D+");
for (int i = 0; i < ks->n; i++) {
printf("%10.2f", ks->Dplus[i]);
}
printf("\n");
printf("%10s", "D-");
for (int i = 0; i < ks->n; i++) {
printf("%10.2f", ks->Dminus[i]);
}
printf("\n");
ks->Dplusmax = ks->Dplus[0];
ks->Dminusmax = ks->Dminus[0];
for (int i = 1; i < ks->n; i++) {
if (ks->Dplus[i] > ks->Dplusmax) {
ks->Dplusmax = ks->Dplus[i];
}
if (ks->Dminus[i] > ks->Dminusmax) {
ks->Dminusmax = ks->Dminus[i];
}
}
printf("D+ max: %.2f\n", ks->Dplusmax);
printf("D- max: %.2f\n", ks->Dminusmax);
printf("D = max(%.2f, %.2f) =", ks->Dplusmax, ks->Dminusmax);
ks->D = (ks->Dplusmax > ks->Dminusmax) ? ks->Dplusmax : ks->Dminusmax;
printf(" %.2f\n", ks->D);
}
void conclusion(struct KS *ks) {
printf("Enter the tabulated value:\n");
scanf("%f", &ks->tabulatedD);
if (ks->D < ks->tabulatedD) {
printf("The test is accepted.\n");
} else {
printf("The test is rejected.\n");
}
}
int main() {
struct KS ks1;
getdata(&ks1);
BubbleSort(&ks1);
calculate(&ks1);
display(&ks1);
conclusion(&ks1);
return 0;
}