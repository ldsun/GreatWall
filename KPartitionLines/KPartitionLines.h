#pragma once

using namespace std;

vector< pair< int, int > > generate_input();

vector< pair<int, int> > KPartitionLines(vector< pair<int, int> > &input_points, int k);

int get_length(pair<int, int> a, pair<int, int> b);