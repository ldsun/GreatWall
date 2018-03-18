#include <iostream>
#include <vector>
#include "LongestOnes.h"

using namespace std;

int main()
{
    // Generate input
    vector <int> input {0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1};
    int k = 5;

    int start = 0, end = 0;
    findLongestOnes(input, &start, &end, k);
    cout << "Result is: start = " << start << " end =" << end << endl;

    return 0;
}