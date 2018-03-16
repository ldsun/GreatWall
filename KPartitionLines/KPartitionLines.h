#pragma once

using namespace std;

vector< pair<double, double> > KPartitionLines(vector< pair<double, double> > &input_points, int k);

double get_length(pair<double, double> a, pair<double, double> b);

pair<double, double> GetPartitionPoint(pair<double, double> a, pair<double, double> b, double length, double segment_length);