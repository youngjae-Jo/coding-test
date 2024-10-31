#include <iostream>

using namespace std;

int N, K;

int main() {
	cin >> N;
	cin >> K;

	// 1~N, 2*(1~N), ... , N*(1~N)

	int low = 1, high = K;
	while (low < high) {
		int mid = (low + high) / 2, cnt = 0;

		for (int i = 1; i <= N; i++) cnt += min(N, mid / i); //mid / i : i�࿡�� mid ������ ���� ����, �ִ� N����

		if (cnt < K) low = mid + 1; //K��° ���� �տ� �ִ� ����� mid �������� Ž��
		else high = mid; //mid �����ؼ� Ž���ؾ� �Ǵϱ� �̷��� ����
	}
	cout << high;

	return 0;
}