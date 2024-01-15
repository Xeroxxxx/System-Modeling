#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int x = 0, y = 0;
void forward() {
y = y + 1;
printf("Forward Move:\t(%d, %d)\n", x, y);
}
void backward() {
y = y - 1;
printf("Backward Move:\t(%d, %d)\n", x, y);
}
void left() {
x = x - 1;
printf("Left Move:\t(%d, %d)\n", x, y);
}
void right() {
x = x + 1;
printf("Right Move:\t(%d, %d)\n", x, y);
}
int main() {
int i, upper = 99, lower = 0;
srand(time(0)); // Define 'srand' before calling 'rand'
for (i = 0; i < 20; i++) {
int random = rand() % (upper - lower + 1) + lower;
if (random >= 0 && random < 25)
forward();
else if (random >= 25 && random < 50)
backward();
else if (random >= 50 && random < 75)
left();
else if (random >= 75 && random < 100)
right();
}
return 0;
}