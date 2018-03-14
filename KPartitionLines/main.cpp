#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    //Generate input
    vector< pair< int, int > > input_points;
    int arr_x[] = {0, 5, 10, 25};
    int arr_y[] = {0, 8, 9, 18};
    for (int i=0; i<sizeof(arr_x)/sizeof(int); i++) {
        input_points.push_back(make_pair(arr_x[i], arr_y[i]));
    }

    
    for (int i=0; i<input_points.size(); i++) {
        cout << input_points[i].first << " " << input_points[i].second << endl;
    }

    return 0;
}