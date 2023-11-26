#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ground[11][11] = { 0, };
int A[11][11] = { 0, };
vector<int> tree[11][11];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void afterYear(int n) {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(tree[i][j].size() == 0) continue;
			int summer = 0;

			sort(tree[i][j].begin(), tree[i][j].end());

			vector<int> temp;
			for (int idx = 0; idx < tree[i][j].size(); idx++) {
				if (ground[i][j] >= tree[i][j][idx]) {
					ground[i][j] -= tree[i][j][idx];
					temp.push_back(tree[i][j][idx] + 1);
				}
				else 
					summer += (tree[i][j][idx] / 2);
				
			}
			tree[i][j].clear();
			for (int k = 0; k < temp.size(); k++)
				tree[i][j].push_back(temp[k]);
			ground[i][j] += summer;
		}

	}

	//가을 -> 번식: 나이가 5배수인 나무면 인접 8칸에 나이 1 나무
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (tree[i][j].size() == 0) continue;
			for (int idx = 0; idx < tree[i][j].size(); idx++) {
				if (tree[i][j][idx] % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						if (i+ dx[k] >= 1 && i + dx[k] <= n && j + dy[k] >= 1 && j + dy[k] <= n) {
							tree[i+dx[k]][j+dy[k]].push_back(1);
						}
					}
				}
			}
		}
	}
	
	//겨울 -> 양분 추가
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ground[i][j] += A[i][j];
		}
	}
}

//땅에 대한 정보, 나무들에 대한 정보를 알고 있는데, 모든 땅에서 정렬하고 그러기보다 나무들에 대해서 탐색하면서 해당 위치의 땅과 상호작용하기
int main() {
	
	int N, M, K; //1~10, 1~100, 1~1000
	int res = 0;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ground[i][j] = 5;
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x][y].push_back(age);
	}
	for (int i = 0; i < K; i++) afterYear(N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			res += tree[i][j].size();
		}
	}
	
	cout << res;

	return 0;
}