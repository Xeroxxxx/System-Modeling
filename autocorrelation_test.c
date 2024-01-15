#include <stdio.h>
#include <math.h>
double auto_correlation_test(int* data, int n, int lag)
{
int i;
double mean = 0.0;
double var = 0.0;
double autocorrelation = 0.0;
double z_value, p_value;
for (i = 0; i< n; i++)
{
mean += data[i];
}
mean /= (double) n;
for (i = 0; i< n; i++)
{
var += (data[i] - mean) * (data[i] - mean);
}
var /= (double) (n - 1);
for (i = 0; i< n - lag; i++)
{
autocorrelation += (data[i] - mean) * (data[i + lag] - mean);
}
autocorrelation /= (double) (n - lag);
autocorrelation /= var;
z_value = autocorrelation * sqrt((double) (n - lag) / (1 - autocorrelation * autocorrelation));
p_value = 0.5 * erfc(-z_value / sqrt(2));
return p_value;
}
int main(void)
{
int data[] = {100, 20, 34, 43, 534, 64, 75, 86, 79, 109};
int n = sizeof(data) / sizeof(data[0]);
int lag = 1;
double p_value = auto_correlation_test(data, n, lag);
printf("Auto Correlation Test p-value at lag %d: %f\n", lag, p_value);
return 0;
}