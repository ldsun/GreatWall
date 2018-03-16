#include <iostream>
#include <vector>
#include <utility>
#include "KPartitionLines.h"

using namespace std;

vector< pair<double, double> > generate_input()
{

    //Generate input
    vector< pair< double, double > > input_points;
    double arr_x[] = {0, 5, 15};
    double arr_y[] = {0, 2, 40};
    for (int i=0; i<sizeof(arr_x)/sizeof(double); i++) {
        input_points.push_back(make_pair(arr_x[i], arr_y[i]));
    }

    cout << "Generated inputs: " << endl;
    for (int i=0; i<input_points.size(); i++) {
        cout << input_points[i].first << " " << input_points[i].second << endl;
    }

    return input_points;
}

int main()
{
    vector< pair<double, double> > input_points = generate_input();
    int k = 8;
    vector< pair<double, double> > result;

    result = KPartitionLines(input_points, k);

    cout << "Partition points: " << endl;
    for (int i=0; i<result.size(); i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}