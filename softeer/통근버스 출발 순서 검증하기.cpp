#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	int arr[5000];
	int d[5001];
	unsigned long long res = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	//i<j<k, a_k<a_i<a_j
	for (int j = 0; j < n; j++) {//d
		for (int i = 0; i <= n; i++)
			d[i] = 0;
		for (int i = 0; i < j; i++) {
			if (arr[j] > arr[i])
				d[arr[i]] = 1;
		}
		for (int k = n - 1; k > 0; k--)
			d[k] += d[k + 1];
		for (int k = j + 1; k < n; k++)
			res += d[arr[k]];
	}

	cout << res;

	return 0;
}