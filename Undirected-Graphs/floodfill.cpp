// Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

// Example:

// {{1, 1, 1, 1, 1, 1, 1, 1},
// {1, 1, 1, 1, 1, 1, 0, 0},
// {1, 0, 0, 1, 1, 0, 1, 1},
// {1, 2, 2, 2, 2, 0, 1, 0},
// {1, 1, 1, 2, 2, 0, 1, 0},
// {1, 1, 1, 2, 2, 2, 2, 0},
// {1, 1, 1, 1, 1, 2, 1, 1},
// {1, 1, 1, 1, 1, 2, 2, 1},
//  };

//  x=4, y=4, color=3

// {{1, 1, 1, 1, 1, 1, 1, 1},
// {1, 1, 1, 1, 1, 1, 0, 0},
// {1, 0, 0, 1, 1, 0, 1, 1},
// {1, 3, 3, 3, 3, 0, 1, 0},
// {1, 1, 1, 3, 3, 0, 1, 0},
// {1, 1, 1, 3, 3, 3, 3, 0},
// {1, 1, 1, 1, 1, 3, 1, 1},
// {1, 1, 1, 1, 1, 3, 3, 1}, };

// Note: Use zero based indexing.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

// Output:
// For each test case print the space separated values of the new matrix.

// Constraints:
// 1 <= T <= 100
// 1 <= M[][] <= 100

// Example:
// Input:
// 3
// 3 4
// 0 1 1 0 1 1 1 1 0 1 2 3
// 0 1 5
// 2 2
// 1 1 1 1
// 0 1 8
// 4 4
// 1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
// 0 2 9

// Output:
// 0 5 5 0 5 5 5 5 0 5 2 3
// 8 8 8 8
// 1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4






#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void floodfill(int a[100][100], int x, int y, int k, int row, int col, int r) {
    if (x < 0 || x >= row || y < 0 || y >= col)return ;
    if (a[x][y] == k)return ;

    if (a[x][y] == r)
    {   a[x][y] = k;
        for (int i = 0; i < 4; i++) {
            floodfill(a, x + dx[i], y + dy[i], k, row, col, r);

        }
    }

}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, x, y;
        cin >> n >> m;
        int a[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        cin >> x >> y;
        int k;
        cin >> k;
        int r = a[x][y];
        floodfill(a, x, y, k, n, m, r);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
        }

        cout << endl;
    }
    return 0;
}