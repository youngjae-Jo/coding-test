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

		for (int i = 1; i <= N; i++) cnt += min(N, mid / i); //mid / i : i행에서 mid 이하인 값의 개수, 최대 N개임

		if (cnt < K) low = mid + 1; //K번째 보다 앞에 있는 수라면 mid 다음부터 탐색
		else high = mid; //mid 포함해서 탐색해야 되니까 이렇게 설정
	}
	cout << high;

	return 0;
}