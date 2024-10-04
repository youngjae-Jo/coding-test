#include<iostream>

using namespace std;

int maap[101][101];
long long dp[101][101];

int main(int argc, char** argv)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maap[i][j];
        }
    }
    //0,0 -> i,j
    //현재칸에 있는 수만큼 아래로 가거나 오른쪽으로
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) continue;

            int dist = maap[i][j];
            int candi_down = dist + i;
            int candi_right = dist + j;

            if (candi_down < N)
                dp[candi_down][j] = dp[candi_down][j] + dp[i][j];
            if (candi_right < N)
                dp[i][candi_right] = dp[i][candi_right] + dp[i][j];

        }
    }
    cout << dp[N - 1][N - 1];

    return 0;
}



















