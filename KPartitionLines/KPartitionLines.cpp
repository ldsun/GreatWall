#include <iostream>
#include <vector>
#include <utility>
#include "KPartitionLines.h"
#include <math.h>

using namespace std;

pair<double, double> GetPartitionPoint(pair<double, double> a, pair<double, double> b, double length, double segment_length)
{
    pair<double, double> result;

    //cout << "Debug: " << length << segment_length << endl;
    if (length == segment_length) {
        result = b;
    } else {
        result.first = a.first + (b.first - a.first) * segment_length / length;
        result.second = a.second + (b.second - a.second) * segment_length / length;
    }
    //cout << "Debug: " << result.first << " " << result.second << endl;

    return result;

}

double get_length(pair<double, double> a, pair<double, double> b)
{
    double result = 0;

    result = sqrt(pow((b.first - a.first), 2) + pow((b.second - a.second), 2));

    return result;
}

vector< pair<double, double> > KPartitionLines(vector< pair<double, double> > &input_points, int k)
{
    double total_length = 0;
    double segment_length = 0;
    vector< pair<double, double> > result;
    int curr_index = 0;
    double remain_length = 0;
    pair <double, double> curr_point;
    pair <double, double> partition_point;
    double local_segment_length = 0;

    // Sanity check
    if (input_points.size() < 2) {
        return vector< pair<double, double> >();
    }

    // Sanity check
    if (k == 0) {
        return vector< pair<double, double> >();
    }

    // Calculate length of segment
    for (int i=0; i<input_points.size()-1; i++) {
        total_length += get_length(input_points[i], input_points[i+1]);
    }
    segment_length = total_length / k;
    cout << "segment_length is: " << segment_length << endl;

    // Traverse the lines to get partition points
    curr_point = input_points[curr_index];
    remain_length = get_length(curr_point, input_points[curr_index + 1]);
    while (curr_index < input_points.size() - 1) {
        if (remain_length >= segment_length) {
            local_segment_length = segment_length;
        } else {
            curr_index += 1;
            curr_point = input_points[curr_index];
            local_segment_length = segment_length - remain_length;
            remain_length = get_length(curr_point, input_points[curr_index + 1]);
        }

        partition_point = GetPartitionPoint(curr_point, input_points[curr_index + 1], remain_length, local_segment_length);
        result.push_back(partition_point);
        curr_point = partition_point;
        remain_length -= local_segment_length;

        cout << "remain length: " << remain_length << endl;

        if ((remain_length - segment_length) < 0.01 ) {
            curr_index += 1;
            curr_point = input_points[curr_index];
            remain_length = get_length(curr_point, input_points[curr_index + 1]);
        }
    }

    return result;
}