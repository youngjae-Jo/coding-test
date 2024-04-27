��#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, K;
int x[100000];
int y[100000];

int dist(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2));
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> y[i];
	}
	int ans = 9999999999;
	//N�� �� K���� ���, K�� �� ���� ����� ���� �Ÿ��� �� ������ ����ϰ�, �� �Ÿ� �� �ִ��� �ּ��� ���
	int max_min = 9999999999;
	int tmp = 0;
	if (K == 1) {
		for (int i = 1; i <= N; i++) {

			for (int j = 1; j <= N; j++) {
				if (j != i)
					tmp = max(tmp, dist(x[i], y[i], x[j], y[j]));
			}
			max_min = min(max_min, tmp);
			tmp = 0;

		}
	}
	else if (K == 2) {
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {

				for (int z = 1; z <= N; z++) {
					if (z != i && z != j) {
						int mini = min({ dist(x[i], y[i], x[z], y[z]), dist(x[j], y[j], x[z], y[z]) });
						tmp = max(tmp, mini);
					}
				}
				max_min = min(max_min, tmp);
				tmp = 0;

			}
		}
	}
	else if (K == 3) {
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				for (int z = j + 1; z <= N; z++) {

					for (int idx = 1; idx <= N; idx++) {
						if (idx != i && idx != j && idx != z) {
							int mini = min({ dist(x[i], y[i], x[idx], y[idx]), dist(x[j], y[j], x[idx], y[idx]), dist(x[z], y[z], x[idx], y[idx]) });
							tmp = max(tmp, mini);
						}
					}
					max_min = min(max_min, tmp);
					tmp = 0;
				}
			}
		}
	}

	cout << max_min;


	return 0;
}