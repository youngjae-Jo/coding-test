#include <iostream>
#include <climits>

using namespace std;

int N, M;
int arr[201][201], s[201][201];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			s[i][j] = arr[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1]; // 1,1에서 i,j까지 누적합
		}
	}
	int ans = INT_MIN;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int tmp_i = 0; tmp_i < i; tmp_i++) {
				for (int tmp_j = 0; tmp_j < j; tmp_j++) {
					ans = max(ans, s[i][j] - s[tmp_i][j] - s[i][tmp_j] + s[tmp_i][tmp_j]);
				}
			}
		}
	}


	cout << ans;

	return 0;
}