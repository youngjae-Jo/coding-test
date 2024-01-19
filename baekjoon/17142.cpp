#include <bits/stdc++.h>
using namespace std;

int n, m, arr[51][51], ans = INT_MAX, total_zero;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool buf[50][50];

bool visited[11];
vector<pair<int, int>> virus;

queue<pair<int, int>> Q;

void BFS() {
	
	int time = 0;
	int count_zero = 0;

	for (int i = 0; i < virus.size(); i++) {
		if (visited[i] == 1) {
			Q.push({virus[i].first, virus[i].second});
			buf[virus[i].first][virus[i].second] = 1;
		}
	}

	while (!Q.empty()) {
		int cur_size = Q.size();
		if (total_zero == count_zero) {
			ans = min(time, ans);
			while (!Q.empty()) Q.pop();
			break;
		}

		for (int j = 0; j < cur_size; j++) {
			int x = Q.front().first;
			int y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (arr[nx][ny] == 1) continue; //벽이면 continue
				if (buf[nx][ny] == 0) { //비활성화된 바이러스, 0인 영역 모두 방문
					buf[nx][ny] = 1;
					Q.push({ nx, ny });
					if (arr[nx][ny] == 0) count_zero++; //0인 영역을 방문한 거라면 0인 영역에 바이러스 퍼진 갯수 세줌
				}
			}
		}
		time++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			buf[i][j] = 0;
		}
	}
}

void DFS(int cur, int d) {
	if (d == m)
		BFS();
	else {
		for (int i = cur; i < virus.size(); i++) {
			visited[i] = 1;
			DFS(i + 1, d + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; //0 빈칸 1 벽 2 비활성 바이러스
			if (arr[i][j] == 2) virus.push_back({ i, j });
			else if (arr[i][j] == 0) total_zero++;
		}
	}
	
	DFS(0, 0);

	if (ans == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
}