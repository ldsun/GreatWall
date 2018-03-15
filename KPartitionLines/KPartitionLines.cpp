#include <iostream>
#include <vector>
#include <utility>
#include "KPartitionLines.h"
#include <math.h>

using namespace std;

vector< pair<int, int> > generate_input()
{

	//Generate input
    vector< pair< int, int > > input_points;
    int arr_x[] = {0, 5, 10, 25};
    int arr_y[] = {0, 8, 9, 18};
    for (int i=0; i<sizeof(arr_x)/sizeof(int); i++) {
        input_points.push_back(make_pair(arr_x[i], arr_y[i]));
    }

    cout << "Generated inputs: " << endl;
    for (int i=0; i<input_points.size(); i++) {
        cout << input_points[i].first << " " << input_points[i].second << endl;
    }

    return input_points;
}

vector< pair<int, int> > KPartitionLines(vector< pair<int, int> > &input_points, int k)
{
	if (input_points.size() < 2) {
		return vector< pair<int, int> >();
	}

	if (k == 0) {
		return vector< pair<int, int> >();
	}

	int total_length = 0;
    for (int i=1; i<input_points.size(); i++) {
        total_length += get_length(input_points[i], input_points[i-1]);
    }
    cout << "total length: " << total_length << endl;

    int segment_length = total_length / k;

    return vector< pair<int, int> >();

}


pair<int, int> GetPartitionPoint(pair<int, int> a, pair<int, int> b, int segment_length)
{
	int length = get_length(b, a);
	if (length < segment_length) {
		return pair<int, int>();
	}

}


int get_length(pair<int, int> a, pair<int, int> b)
{
	int result = 0;

	result = sqrt(pow((b.first - a.first), 2) + pow((b.second - a.second), 2));

	return result;
}