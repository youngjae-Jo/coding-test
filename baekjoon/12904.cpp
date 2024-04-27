#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	string S, T;
	cin >> S;
	cin >> T;

	while (T.size() > S.size()) {
		if (T.back() == 'A')
			T.pop_back();
		else if (T.back() == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		}

	}
	cout << (S == T) ? 1 : 0;

	return 0;
}