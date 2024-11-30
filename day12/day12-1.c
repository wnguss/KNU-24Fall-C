#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int left[10001] = { 0 }, right[10001] = { 0 };
    int type1 = 0, type2 = 0;
    int i = 0;

    while (i < topping_len) {
        if (left[topping[i]] == 0) {
            type1++;
        }
        left[topping[i]] += 1;
        i++;
    }
 
    i = 0;

    while (i < topping_len) {
        if (right[topping[i]] == 0) {
            type2++;
        }
        right[topping[i]] += 1;

        left[topping[i]] -= 1;
        if (left[topping[i]] == 0) {
            type1--;
        }
        
        if (type1 == type2) {
            answer++;
        }
        i++;
    }

    return answer;
}