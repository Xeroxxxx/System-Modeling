#include <stdio.h>
#include <stdlib.h>
unsigned int seed; // Initial seed for the random number generator
unsigned int midSquareRandom() {
    seed = seed * seed;
    seed /= 100;
    return seed % 10000;
}
    int main() {
    printf("Enter the initial seed: ");
    scanf("%u", &seed);
    int numRandomNumbers;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numRandomNumbers);
    printf("Random numbers generated using mid-square method:\n");
    for (int i = 0; i < numRandomNumbers; ++i) {
    unsigned int randomNumber = midSquareRandom();
    printf("%u\n", randomNumber);
}
return 0;
}