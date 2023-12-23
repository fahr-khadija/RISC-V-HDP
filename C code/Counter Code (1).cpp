#include <stdio.h>
#include <unistd.h>  // for usleep

void delay(int n) {
    usleep(n);  // sleep for n microseconds
}

void display(int count) {
    printf("Count value is: %d\n", count);
}

int main() {
    printf("Start counter\n");
    int count = 0x00000000;
    
    while (1) {
        display(count);
        count++;

        if (count == 16) {
            count = 0;
        }

        delay(800000);  // delay by 0.8 seconds using usleep
    }

    return 0;
}
