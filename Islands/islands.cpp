#include <iostream>
#include "islands.h"

using namespace std;

void bfs(const vector < vector <int> > &input, vector < vector <int> > &visited, int i, int j, int num)
{
    if (i < 0 || i >= input.size() || j < 0 || j >= input[0].size()) return;

    if (visited[i][j] == -1) {
        
        if (input[i][j] == 0) {
            visited[i][j] = 0;
            return;
        }
        visited[i][j] = num;
        bfs(input, visited, i-1, j, num);
        bfs(input, visited, i, j-1, num);
        bfs(input, visited, i+1, j, num);
        bfs(input, visited, i, j+1, num);
    }
}

int countIslands(vector < vector<int> > &input) 
{
    int num = 0;
    const int m = input.size();
    if (m == 0) return 0;
    const int n = input[0].size();
    if (n == 0) return 0;
    vector < vector <int> > visited {input.size(), vector<int>(input[0].size(), -1)};

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (input[i][j] == 0 && visited[i][j] == -1) {
                visited[i][j] = 0;
                continue;
            } else if (visited[i][j] == -1) {
                num++;
                bfs(input, visited, i, j, num);
            }
        }
    }

    cout << "Island marker: " << endl;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    return num;
}