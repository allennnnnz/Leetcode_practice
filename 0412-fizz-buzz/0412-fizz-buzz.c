#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    int size = 0;
    int capacity = 1;
    char** res = malloc(sizeof(char*) * capacity);

    for (int i = 1; i <= n; i++) {
        // 擴大空間
        if (size >= capacity) {
            capacity *= 2;
            res = realloc(res, sizeof(char*) * capacity);
        }
        // size現在放在陣列中的第幾格
        char buf[12];
        if (i % 3 == 0 && i % 5 == 0) {
            res[size] = strdup("FizzBuzz");
        } else if (i % 3 == 0) {
            res[size] = strdup("Fizz");
        } else if (i % 5 == 0) {
            res[size] = strdup("Buzz");
        } else {
            sprintf(buf, "%d", i);
            res[size] = strdup(buf);
        }
        size++;
    }

    *returnSize = size;
    return res;
}