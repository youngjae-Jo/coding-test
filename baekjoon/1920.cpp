#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int numb;
int arr[100000];

int binarySearch(int numb){
    int start = 0;
    int end = N - 1;
    while(start<=end){
        int mid = (start+end) / 2;
        if(arr[mid] == numb)
            return 1;
        else if(numb < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
    sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> numb;
		cout << binarySearch(numb) << "\n";
	}
    return 0;
}
