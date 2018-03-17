#include <iostream>
#include "LongestOnes.h"

using namespace std;

void findLongestOnes(vector <int> input, int *start, int *end, int k)
{
    int s = 0, e = 0, remain_zeros = k, length = 0, next = 0, max_length = 0;

    // Scan to find first 1
    while (input[s++] == 0); s--;

    //iterate the array using next index. 
    next = s + 1;
    length = 1;
    while (next < input.size()) {
        // if next is 1
        if (input[next] == 1) {
            e = next;
            length++;
            next++;
        } else {
            if (remain_zeros > 0) {
                remain_zeros--;
                next++;
            } else {
                if (length > max_length) {
                    max_length = length;
                    *start = s;
                    *end = e;
                }
                while (input[++s] == 1);
                while (input[s] == 0) {
                    remain_zeros++;
                    s++;
                }

            }
        }
    }

    if (length > max_length) {
        max_length = length;
        *start = s;
        *end = e;
    }

    *start = s;
    *end = e;
}