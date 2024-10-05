#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int maap[101][101];
bool visited[101][101];
int n;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int maxi = -1;
int mini = 201;

bool bfs(int target) {
	queue < pair<int, int>> q;
	for (int val = mini; val <= maxi; val++) {
		memset(visited, true, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (maap[i][j] >= val && maap[i][j] <= val + target)
					visited[i][j] = false;
			}
		}
		q.push(make_pair(1, 1));
		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			if (visited[r][c])
				continue;
			visited[r][c] = true;
			if (r == n && c == n)
				return true;

			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];
				if (nr >= 1 && nr <= n && nc >= 1 && nc <= n)
					q.push({ nr,nc });
			}

		}

	}



	return false;
}



int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maap[i][j];
			if (maap[i][j] > maxi)
				maxi = maap[i][j];
			if (maap[i][j] < mini)
				mini = maap[i][j];
		}
	}
	//거쳐간 수들 중 최대 최소 차이 가장 적은!	
	int S = 0;
	int E = maxi - mini;
	int mid = 0;
	while (S <= E) {
		mid = (S + E) / 2;
		if (bfs(mid))
			E = mid - 1;
		else
			S = mid + 1;
	}
	cout << E + 1;
	return 0;
}

