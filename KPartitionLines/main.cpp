#include <iostream>
#include <vector>
#include <utility>
#include "KPartitionLines.h"

using namespace std;

int main()
{
    vector< pair<int, int> > input_points = generate_input();

    KPartitionLines(input_points, 5);

    return 0;
}