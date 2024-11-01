#include<iostream>

using namespace std;
int n;
int arr[101];

int main(int argc, char** argv) {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //난로~
    }
    //난로의 반지름이 연탄 반지름의 배수인 곳만 가능 
    for (int i = 2; i <= 100; i++) {
        int chk = 0;
        for (int idx = 0; idx < n; idx++) {
            if (i <= arr[idx] && arr[idx] % i == 0) chk++;
        }
        if (chk > ans)
            ans = chk;
    }
    cout << ans;
    return 0;
}