#include<iostream>

using namespace std;
int n;
int arr[101];

int main(int argc, char** argv) {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //����~
    }
    //������ �������� ��ź �������� ����� ���� ���� 
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