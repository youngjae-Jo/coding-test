#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N, M, K;

struct info {
    int row = -1;
    int col = -1;
    int out = 0;
};

int maap[11][11];
int exit_row; int exit_col;
int rect_row; int rect_col;
info player[11];
int dx[4] = { -1, 1, 0, 0 }; //상하좌우
int dy[4] = { 0, 0, -1, 1 };
int sum = 0;

void input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> maap[i][j];
        }
    }
    for (int i = 1; i <= M; i++)
        cin >> player[i].row >> player[i].col;

    cin >> exit_row >> exit_col;
    maap[exit_row][exit_col] = -1;
}

int dist(int x1, int y1, int x2, int y2) { return (abs(x1 - x2) + abs(y1 - y2)); }
bool in_map(int r, int c) { return (r >= 1 && r <= N && c >= 1 && c <= N); }

int direction(int idx) {
    if (player[idx].out)
        return -1;
    int distance = dist(player[idx].row, player[idx].col, exit_row, exit_col);//이동전 거리
    for (int i = 0; i < 4; i++) {
        int nr = player[idx].row + dx[i];
        int nc = player[idx].col + dy[i];
        if (in_map(nr, nc) && maap[nr][nc] <= 0) {//맵 안에 있고 벽 아니면
            if (dist(nr, nc, exit_row, exit_col) < distance)//거리가 가까워지면
                return i;
        }
    }
    return -1;
}

bool is_in_Rect(int idx, int l) {
    if (player[idx].out)
        return false;
    else
        return (rect_row <= player[idx].row && player[idx].row <= rect_row + l - 1 &&
            rect_col <= player[idx].col && player[idx].col <= rect_col + l - 1);
}

int rect() {
    int leng = 0;

    for (int l = 2; l <= N; l++) {//길이가 L인 사각형들 확인

        for (int i = exit_row - (l - 1); i <= exit_row; i++) {
            for (int j = exit_col - (l - 1); j <= exit_col; j++) {
                rect_row = i;
                rect_col = j;
                if (in_map(i, j)) {
                    for (int idx = 1; idx <= M; idx++) {
                        if (is_in_Rect(idx, l))
                            return l;
                    }
                }
            }
        }
    }
    return leng;
}

void rotate() {
    int length = rect();//정사각형 영역 선정
    //저장용
    int temp[11][11];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            temp[i][j] = maap[i][j];
        }
    }
    //회전
    int sz = length;
    for (int i = 0; i < length / 2; i++) {
        int tmp_row = rect_row + i;
        int tmp_col = rect_col + i;
        for (int idx = 0; idx < (sz - 1) && sz >= 2; idx++) {
            maap[tmp_row][tmp_col + idx] = temp[tmp_row + sz - 1 - idx][tmp_col]; //왼->위
            maap[tmp_row + idx + 1][tmp_col] = temp[tmp_row + sz - 1][tmp_col + idx + 1]; //아->왼
            maap[tmp_row + sz - 1][tmp_col + idx + 1] = temp[tmp_row + sz - 1 - idx - 1][tmp_col + sz - 1]; //오->아
            maap[tmp_row + idx][tmp_col + sz - 1] = temp[tmp_row][tmp_col + idx]; //위->오
        }
        sz -= 2;
    }

    for (int i = 1; i <= M; i++) {//player들 있었으면 옮기기
        int visited[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
        if (is_in_Rect(i, length) && !visited[i]) {
            for (int d = 0; d < length / 2; d++) {
                int position = 0;
                if (player[i].row == rect_row + d && player[i].col != rect_col + length - 1 - d) {
                    //윗줄
                    position = player[i].col - (rect_col + d);
                    player[i].row += position;
                    player[i].col = rect_col + length - 1 - d;
                    visited[i] = 1;
                    break;
                }
                else if (player[i].col == rect_col + length - 1 - d && player[i].row != rect_row + length - 1 - d) {
                    //오른쪽줄
                    position = player[i].row - (rect_row + d);
                    player[i].row = rect_row + length - 1 - d;
                    player[i].col = rect_col + length - 1 - d - position;
                    visited[i] = 1;
                    break;
                }
                else if (player[i].row == rect_row + length - 1 - d && player[i].col != rect_col + d) {
                    //아랫줄
                    position = (rect_col + length - 1 - d) - player[i].col;
                    player[i].row = rect_row + length - 1 - d - position;
                    player[i].col = rect_col + d;
                    visited[i] = 1;
                    break;
                }
                else if (player[i].col == rect_col + d && player[i].row != rect_row + d) {
                    //왼쪽줄
                    position = (rect_row + length - 1 - d) - player[i].row;
                    player[i].row = rect_row + d;
                    player[i].col = rect_col + d + position;
                    visited[i] = 1;
                    break;
                }
            }
        }
    }

    for (int i = rect_row; i < rect_row + length; i++) {//내구도
        for (int j = rect_col; j < rect_col + length; j++) {
            if (maap[i][j] >= 1)
                maap[i][j]--;
            else if (maap[i][j] == -1) {
                exit_row = i;
                exit_col = j;
            }
        }
    }
}

bool is_end() {
    for (int i = 1; i <= M; i++) {
        if (player[i].out == 0)
            return false;
    }
    return true;
}

void solve() {
    for (int idx = 1; idx <= K; idx++) {
        //1초마다 참가자 동시에 움직임(최단거리가 가까워지는 곳으로)
        for (int i = 1; i <= M; i++) {
            int dir = direction(i);
            if (dir >= 0) {
                player[i].row += dx[dir];
                player[i].col += dy[dir];
                sum++;
                if (maap[player[i].row][player[i].col] == -1) {//나감
                    player[i].out = 1;
                    if (is_end())
                        return;
                }
            }
        }
        rotate();
    }
}

int main() {
    input();

    solve();

    cout << sum << endl << exit_row << " " << exit_col;//output

    return 0;
}