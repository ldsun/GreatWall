#include <iostream>
#include "LongestOnes.h"

using namespace std;

void findLongestOnes(vector <int> input, int *start, int *end, int k)
{
    int s = 0, e = 0;
    int remain_zeros = k;

    while (e < input.size()) {
        // Update start index
        // When to update start index:
        // 1. Initial state
        // 2. No more 0 to remove
        if (remain_zeros == k) {
            // if e < input.size() and remain_zeros == k, then it's initial state:
            //Initial state: remove leading 0s
            while (input[s++] == 0); s--;
            e = s;
            cout << "Initial start index is: " << s << endl;
        } else if (remain_zeros == 0) {
            while (input[++s] == 1);
            while (input[s] == 0) {
                remain_zeros++;
                s++;
                if (remain_zeros > k) {
                    cout << "Error: remain_zeros > k" << endl;
                }
            }   
        }

        // Update end index
        // When to update end index:
        // 1. remain_zeros > 0
        while (remain_zeros > 0 && e < input.size()) {
            if (input[e+1] == 0) {
                remain_zeros--;
            }
            e++;
        }
        while (e < input.size() && input[++e] == 1);
        if (e < input.size()) {
            e--;
        }

    }

}