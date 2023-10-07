#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int map[500][500] = { 0, };
int N = 0, M = 0;
int maxVal = 0;
pair<int, int> idx[4] = { {-1, -1}, };

//어느 칸인지 골라야 함, 다음 칸은 이전에 선택하지 않았어야 하고
//이번칸과 행렬 중 하나만 다른 인덱스를 가져야 함
void tetro_max(int map[][500], int row, int col, int cnt, int crrSum) {
	//0상1하2좌3우
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	idx[cnt].first = row;
	idx[cnt].second = col;

	if (cnt == 3) {
		if (crrSum > maxVal)
			maxVal = crrSum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (row + dx[i] < N && row + dx[i] >= 0 && col + dy[i] < M && col + dy[i] >= 0) {
			if (row + dx[i] == idx[0].first && col + dy[i] == idx[0].second) continue;

			if (row + dx[i] == idx[1].first && col + dy[i] == idx[1].second) {

				if (cnt == 2 && idx[0].first != idx[2].first && idx[0].second + 1 == idx[2].second) {

					if (idx[1].first == idx[0].first && idx[1].first - idx[2].first == 1) {
						if (idx[1].first + dx[3] < N && idx[1].first + dx[3] >= 0 && idx[1].second + dy[3] < M && idx[1].second + dy[3] >= 0)
							tetro_max(map, idx[1].first + dx[3], idx[1].second + dy[3], cnt + 1, crrSum + map[idx[1].first + dx[3]][idx[1].second + dy[3]]);

						if (idx[1].first + dx[1] < N && idx[1].first + dx[1] >= 0 && idx[1].second + dy[1] < M && idx[1].second + dy[1] >= 0)
							tetro_max(map, idx[1].first + dx[1], idx[1].second + dy[1], cnt + 1, crrSum + map[idx[1].first + dx[1]][idx[1].second + dy[1]]);
					}

					if (idx[1].first == idx[0].first && idx[1].first - idx[2].first == -1) {
						if (idx[1].first + dx[3] < N && idx[1].first + dx[3] >= 0 && idx[1].second + dy[3] < M && idx[1].second + dy[3] >= 0)
							tetro_max(map, idx[1].first + dx[3], idx[1].second + dy[3], cnt + 1, crrSum + map[idx[1].first + dx[3]][idx[1].second + dy[3]]);

						if (idx[1].first + dx[0] < N && idx[1].first + dx[0] >= 0 && idx[1].second + dy[0] < M && idx[1].second + dy[0] >= 0)
							tetro_max(map, idx[1].first + dx[0], idx[1].second + dy[0], cnt + 1, crrSum + map[idx[1].first + dx[0]][idx[1].second + dy[0]]);
					}

				}

				if (idx[0].second == idx[1].second && idx[1].second != idx[2].second && idx[0].first < idx[2].first) {
					if (idx[1].first + dx[1] < N && idx[1].first + dx[1] >= 0 && idx[1].second + dy[1] < M && idx[1].second + dy[1] >= 0) {
						tetro_max(map, idx[1].first + dx[1], idx[1].second + dy[1], cnt + 1, crrSum + map[idx[1].first + dx[1]][idx[1].second + dy[1]]);
					}
				}
				continue;
			}

			tetro_max(map, row + dx[i], col + dy[i], cnt + 1, crrSum + map[row + dx[i]][col + dy[i]]);
		}
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				idx[k].first = -2;
				idx[k].second = -2;
			}
			tetro_max(map, i, j, 0, map[i][j]);
		}
	}
	cout << maxVal;
	return 0;
}