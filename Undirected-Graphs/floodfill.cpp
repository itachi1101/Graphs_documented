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