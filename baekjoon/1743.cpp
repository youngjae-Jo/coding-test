#include<iostream>


using namespace std;

int N, M, K;
int maap[101][101];
int visited[101][101];
int dx[4] = { 1, -1, 0, 0 }; //ÇÏ»óÁÂ¿ì
int dy[4] = { 0, 0, -1, 1 };
int maxi;
int count;

bool is_valid(int r, int c) {
    if (r >= 1 && r <= N && c >= 1 && c <= M) {
        if (!visited[r][c] && maap[r][c])
            return true;
        else
            return false;
    }
    else
        return false;
}

void dfs(int r, int c) {
    visited[r][c] = 1;
    count++;
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (is_valid(nr, nc))
            dfs(nr, nc);
    }

}



int main(int argc, char** argv)
{
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        maap[x][y] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (maap[i][j] && !visited[i][j]) {
                dfs(i, j);
                if (count > maxi)
                    maxi = count;
                count = 0;
            }
        }
    }
    cout << maxi;
    return 0;
}