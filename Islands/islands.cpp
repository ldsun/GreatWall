#include <iostream>
#include "islands.h"

using namespace std;

void bfs(const vector < vector <int> > &input, vector < vector <bool> > &visited, int i, int j)
{
    if (i < 0 || i >= input.size() || j < 0 || j >= input[0].size()) return;

    if (visited[i][j] == false) {
        visited[i][j] = true;
        if (input[i][j] == 0) return;
        bfs(input, visited, i-1, j);
        bfs(input, visited, i, j-1);
        bfs(input, visited, i+1, j);
        bfs(input, visited, i, j+1);
    }
}

int countIslands(vector < vector<int> > &input) 
{
    int num = 0;
    const int m = input.size();
    if (m == 0) return 0;
    const int n = input[0].size();
    if (n == 0) return 0;
    vector < vector <bool> > visited {input.size(), vector<bool>(input[0].size(), false)};

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (input[i][j] == 0 && visited[i][j] == false) {
                visited[i][j] = true;
                continue;
            } else if (visited[i][j] == false) {
                num++;
                bfs(input, visited, i, j);
            }
        }
    }
    return num;
}