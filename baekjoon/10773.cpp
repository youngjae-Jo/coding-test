#include <iostream>
#include <vector>

using namespace std;

int main() {
	int K;
	cin >> K;
	int sum = 0;
	int num = 0;
	vector<int> v;

	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0)
			v.erase(v.begin() + v.size() - 1);
		else
			v.push_back(num);
	}
	for (int i = 0; i < v.size(); i++)
		sum += v[i];
	cout << sum;

	return 0;
}