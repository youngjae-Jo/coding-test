#include <iostream>
#include <queue>
using namespace std;

int N, M;
int maap[101][101];
bool visited[101][101];
int ans[101][101] = { 0, };

int dx[4] = { -1, 1, 0, 0 }; //상하좌우
int dy[4] = { 0,0,-1,1 };

struct pos {
	int x;
	int y;
};

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string row;
		cin >> row;
		for (int j = 1; j <= M; j++) {
			maap[i][j] = row[j - 1] - '0';
		}
	}
	//(1,1)에서 (N, M)으로 가는 최소 칸 수
	ans[1][1] = 1;
	queue<pos>q;
	q.push({ 1,1 });
	visited[1][1] = 1;

	while (!q.empty()) {

		int tmp_x = q.front().x;
		int tmp_y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tmp_x + dx[i];
			int ny = tmp_y + dy[i];
			if (nx <= N && ny <= M && nx >= 1 && ny >= 1 && maap[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				ans[nx][ny] = ans[tmp_x][tmp_y] + 1;
			}
		}
	}

	cout << ans[N][M];

	return 0;
}