#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		// view the image in this repository for better understanding
		int cnt = 0;
		vector<vector<char>> a(n, vector<char>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				cnt += (a[i][j] == 'W'); // count white cells
			}
		}
		// check if no operations are needed or if all cells are white
		if (a[r - 1][c - 1] == 'B') {
			cout << 0 << '\n';
			continue;
		} else if (cnt == n * m) {
			cout << -1 << '\n';
			continue;
		}
		bool checker = false;
		// if a black cell is present where the row or column of the target cell
		// is located, then only 1 operation is needed, otherwise 2 operations
		// check current row:
		for (int col = 0; col < m; col++) {
			checker |= (a[r - 1][col] == 'B');
		}
		// check current column:
		for (int row = 0; row < n; row++) {
			checker |= (a[row][c - 1] == 'B');
		}
		cout << (checker ? 1 : 2) << '\n';
	}
	return 0;
}
