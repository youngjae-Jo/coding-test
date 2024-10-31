#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[5000001];
int N, L;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	// A_(i-L+1) ~ A_i ÃÖ¼Ú°ª = D_i
	for (int i = 1; i <= N; i++) cin >> arr[i];

	deque<pair<int, int>>dq;
	for (int i = 1; i <= N; i++) {
		if (!dq.empty()) {
			if (dq.front().second < i - L + 1) dq.pop_front();
		}
		while (!dq.empty() && dq.back().first > arr[i]) dq.pop_back();
		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";

	}
	cout << endl;

	return 0;
}