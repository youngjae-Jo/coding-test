#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
	cin >> n;
	vector<long long> plus;
	vector<long long> minus;

	int zero_cnt = 0;
	int one_cnt = 0;
	long long point = 0;


	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		if (num == 0) zero_cnt++;
		else if (num == 1) one_cnt++;
		else if (num < 0) minus.push_back(num);
		else plus.push_back(num);
	}
	sort(minus.begin(), minus.end());
	sort(plus.begin(), plus.end(), greater<int>());
	int minus_size = minus.size();
	int plus_size = plus.size();

	for (int i = 0; i < minus_size - 1; i += 2) {
		point += minus[i] * minus[i + 1];
	}
	if (minus_size % 2 == 1 && !zero_cnt) point += minus.back();

	for (int i = 0; i < plus_size - 1; i += 2) {
		point += plus[i] * plus[i + 1];
	}
	if (plus_size % 2 == 1) point += plus.back();
	point += one_cnt;

	cout << point;


}