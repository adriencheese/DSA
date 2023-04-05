#include <stdio.h>

int main() {
    int val = 1;
    int* first_ptr = &val;
    int* a = first_ptr;
    int* b = first_ptr;

    if (a == b) {
        printf("here");
    } else {
        printf("can't");
    }

}