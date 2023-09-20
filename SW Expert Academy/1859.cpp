#include <iostream>
using namespace std;
long res = 0;
int _max = 0;

long find_interest(int arr_i[], int n ,int start)
{
	int index = 0;
	for (int i = start; i < n; i++){
		if (start < n && arr_i[i] >= _max){
			_max = arr_i[i];
			index = i;
		}
	}
	for (int i = start; i <= index; i++)
		res += _max - arr_i[i];
	for (int j = index + 1; j < n; j++) {
		//if (index < n && arr_i[index + 1] < arr_i[j]) {
			_max = arr_i[index + 1];
			find_interest(arr_i, n, index + 1);
			break;
		//}
	}
	return res;
}

int main(){
	int T = 0;
	cin >> T;
	int** arr = new int* [T];
	int* N = new int[T];
	for (int i = 0; i < T; i++)
		arr[i] = new int[1000000];
	for (int i = 0; i < T; i++){
		cin >> N[i];
		for (int j = 0; j < N[i]; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < T; i++) {
		cout << "#" << i + 1 << " ";
		cout << find_interest(arr[i], N[i], 0) << endl;
		res = 0;
		_max = 0;
	}
	return 0;
}