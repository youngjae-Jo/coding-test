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

	//N���� ������ ��� �ϳ��� ���߱��� ����� �����ؾ� �Ѵ�.
	//�� ���߱��� ���� ���ɿ����� �Ÿ��� ���� �ּڰ�
	//N���� ��Ƽ�, ��� ������ ��ġ�� �ؾ���

	return 0;

}