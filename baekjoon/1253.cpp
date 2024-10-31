#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[2001];

int main() {
	int ans = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		int s = 0;
		int e = N - 1;
		while (s < e) {
			if (arr[s] + arr[e] == arr[i]) {
				if (s != i && e != i) {
					ans++;
					break;
				}
				else if (s == i) s++;
				else if (e == i) e--;
			}
			else if (arr[s] + arr[e] < arr[i]) s++;
			else e--;
		}
	}
	cout << ans;
	return 0;
}