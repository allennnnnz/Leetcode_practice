#include <stdio.h>
#include <string.h>

typedef struct {
    char key[2];     // 一個羅馬字母 + '\0'
    int value;       // 對應的整數
} rome_to_int;

#define SIZE 7
rome_to_int dict[SIZE] = {
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000},
};

int getValue(char c) {
    for (int i = 0; i < SIZE; i++) {
        if (dict[i].key[0] == c) {
            return dict[i].value;
        }
    }
    return 0; // 找不到就傳 0
}

int romanToInt(char* s) {
    int total = 0;
    int i = 0;

    while (s[i] != '\0') {
        int curr = getValue(s[i]);
        int next = getValue(s[i+1]);

        if (curr < next) {
            total += (next - curr);
            i += 2;
        } else {
            total += curr;
            i += 1;
        }
    }
    return total;
}