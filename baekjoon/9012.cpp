#include <iostream>

using namespace std;

void VPS(string arr) {
	int size = arr.size();
	int i = 0;
	while (i<size) {
		if (arr[i] == '(') {
			for (int j = i + 1; j < size; j++) {
				if (arr[j] == ')') {
					arr[i] = '-';
					arr[j] = '-';
					j = size;
				}
			}
		}
		int check = 0;
		for (int idx = 0; idx < size; idx++) {
			if (arr[idx] != '-')
				check = 1;
		}
		if (check == 0) {
			cout << "YES" << endl;
			return;
		}
		i++;
	}
	cout << "NO" << endl;
}

int main() {
	int T;
	cin >> T;
	string arr;
	for (int i = 0; i < T; i++) {
		cin >> arr;
		VPS(arr);
	}


	return 0;
}