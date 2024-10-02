#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N = 0;
	int K = 0;
	vector<int> sensor;
	vector<int> v;
	int ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int location = -1;
		cin >> location;
		sensor.push_back(location);
	}
	sort(sensor.begin(), sensor.end());
	for (int i = 1; i < N; i++)
		v.push_back(sensor[i] - sensor[i - 1]);

	sort(v.begin(), v.end());


	for (int i = 0; i < (int)v.size() + 1 - K; i++)
		ans += v[i];
	cout << ans;

	//N개의 센서가 적어도 하나의 집중국과 통신이 가능해야 한다.
	//각 집중국의 수신 가능영역의 거리의 합의 최솟값
	//N개를 깔아서, 모든 센서를 터치는 해야함

	return 0;

}