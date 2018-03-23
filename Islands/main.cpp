#include <iostream>
#include <vector>
#include "islands.h"

using namespace std;

int main()
{
    //Generate input
    vector < vector< int > > input {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };

    //Visualize input
    for (int i=0; i<input.size(); i++) {
        for (int j=0; j<input[i].size(); j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }

    //call the program
    int n = countIslands(input);

    cout << "output is: " << n << endl;

    //Visualize output
    return 0;
}