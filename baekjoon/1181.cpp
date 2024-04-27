#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> arr;

bool compare(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else if (a.size() == b.size())
		return a < b;
}


int main() {
	int N;
	string word;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		arr.push_back(word);
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 1; i < arr.size(); i++) {
		int j = i - 1;
		if (arr[j] == arr[i])
			arr.erase(arr.begin() + i--);
	}

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << endl;


	return 0;
}