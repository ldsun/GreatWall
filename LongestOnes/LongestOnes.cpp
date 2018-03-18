#include <iostream>
#include "LongestOnes.h"

using namespace std;

void findLongestOnes(vector <int> input, int *start, int *end, int k)
{
    int s = 0, e = 0;
    int remain_zeros = k;
    int local_length = 0, longest_length = 0, result_s = 0, result_e = 0;

    while (e < input.size()) {
        cout << "s: " << s << " e: " << e << " remaining zeros: " << remain_zeros << endl;
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
            cout << "size of input: " << input.size() << endl;
        } else if (remain_zeros == 0) {
            while (input[++s] == 1);
            while (input[s] == 0) {
                cout << "adding a zero" << endl;
                remain_zeros++;
                s++;
                if (remain_zeros > k) {
                    cout << "Error: remain_zeros > k" << endl;
                }
                if (s > e) {
                    cout << "Error: s is greater than e" << endl;
                }
            }   
        }

        // Update end index
        // When to update end index:
        // 1. remain_zeros > 0
        while (remain_zeros > 0) {
            if (e + 1 < input.size()) {
                if (input[e + 1] == 0) {
                    cout << "removing a zero" << endl;
                    remain_zeros--;
                }
                e++;
            } else {
                break;
            }
        }
        if (remain_zeros == 0) {
            while (e + 1 < input.size()) {
                if (input[e+1] == 1) {
                    e++;
                } else {
                    break;
                }
            }
        }

        // Update result
        if (e == input.size()) e--;
        local_length = e - s + 1 - (k - remain_zeros);
        if (local_length > longest_length) {
            longest_length = local_length;
            result_s = s;
            result_e = e;
        }

        if (e == input.size() - 1) break;
    }

    // Update result
    if (e == input.size()) e--;
    local_length = e - s + 1 - (k - remain_zeros);
    if (local_length > longest_length) {
        longest_length = local_length;
        result_s = s;
        result_e = e;
    }

    *start = result_s;
    *end = result_e;
}