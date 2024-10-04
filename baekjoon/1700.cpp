#include <iostream>
#include <vector>
using namespace std;

int N, K;
int plugged[100]; //플러그 순서대로
int is_use[100]; //n번 용품을 쓰고 있는 중
int order_i = 0;
vector<int> Order;

int dist(int curr, int p_idx) {//Order, plug 인덱스
	int ans = 0;
	for (int i = curr; i < K; i++) {
		if (Order[i] == plugged[p_idx])
			break;
		else
			ans++;
	}

	return ans;
}

int main() {
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		Order.push_back(tmp);
	}
	int idx = 0;
	//N개 종류가 나올 때 까지만 꽂을 수 있음
	//하나꽂으면 idx, order_i 올라감
	//원래 있었으면 order_i 올라감
	for (order_i; order_i < K; order_i++) { //처음에 일단 되는대로 꽂기

		if (!is_use[Order[order_i]]) {
			plugged[idx++] = Order[order_i];
			is_use[Order[order_i]] = 1;
		}
		if (idx == N) {
			idx--;
			break;
		}
	}

	for (int i = order_i + 1; i < K; i++) {
		int maxi = 0;
		int maxi_idx = 0;

		if (is_use[Order[i]]) continue; //이미 꽂혀있으면 뺄 필요 없음

		for (int j = 0; j < N; j++) { //플러그 어디서 뺄까 고민중
			int tmp = dist(i, j);
			if (tmp > maxi) {
				maxi = tmp;
				maxi_idx = j;
			}
		}
		int prev = plugged[maxi_idx];
		plugged[maxi_idx] = Order[i];
		is_use[prev] = 0;
		is_use[Order[i]] = 1;
		cnt++;
	}
	cout << cnt;
	return 0;
}