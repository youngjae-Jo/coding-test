#include<iostream>

using namespace std;

int N;
//int arr[100000][3];
int dp_maxi[3];
int dp_mini[3];

int main(int argc, char** argv)
{
    cin >> N;
    int a, b, c;
    cin >> a >> b >> c;
    dp_maxi[0] = a; dp_maxi[1] = b; dp_maxi[2] = c;
    dp_mini[0] = a; dp_mini[1] = b; dp_mini[2] = c;

    for (int i = 1; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        int origin_0 = dp_maxi[0], origin_2 = dp_maxi[2];
        dp_maxi[0] = max(dp_maxi[0], dp_maxi[1]) + x;
        dp_maxi[2] = max(dp_maxi[1], dp_maxi[2]) + z;
        dp_maxi[1] = max(max(origin_0, dp_maxi[1]), origin_2) + y;

        //
        origin_0 = dp_mini[0], origin_2 = dp_mini[2];
        dp_mini[0] = min(dp_mini[0], dp_mini[1]) + x;
        dp_mini[2] = min(dp_mini[1], dp_mini[2]) + z;
        dp_mini[1] = min(min(origin_0, dp_mini[1]), origin_2) + y;
    }

    //내려가면서, 왼쪽 아래, 그냥 아래, 오른쪽 아래로만 가능, 2칸 이동 x
    int maxi = max(max(dp_maxi[0], dp_maxi[1]), dp_maxi[2]);
    int mini = min(min(dp_mini[0], dp_mini[1]), dp_mini[2]);

    cout << maxi << " " << mini;
    return 0;
}