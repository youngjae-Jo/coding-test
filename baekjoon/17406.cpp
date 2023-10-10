#include <iostream>

using namespace std;

int K = 0; // 1 ≤ K ≤ 6
int N = 0, M = 0;  //3 ≤ N, M ≤ 50
int r[6] = { 0, }, c[6] = { 0, }, s[6] = { 0, }; // 1 ≤ s , 1 ≤ r-s < r < r+s ≤ N, 1 ≤ c-s < c < c+s ≤ M -> 2<=r<=N-1, 2<=c<=M-1
int mini = 0;
int map[51][51] = { 0, };
int visited[6] = { 0, };

//가장 왼쪽 윗 칸이 (r-s, c-s), 가장 오른쪽 아랫 칸이 (r+s, c+s)인 정사각형을 시계 방향으로 한 칸씩 돌린다 
void rotate(int r, int c, int s) {
    int temp[51][51] = { 0, };
    for (int cntR = 0; cntR < s; cntR++) {
        for (int i = 1; i <= 2 * s - 2 * cntR; i++) {//좌변
            temp[i - 1 + r - s + cntR][c - s + cntR] = map[i + r - s + cntR][c - s + cntR];
        }
        for (int i = 0; i < 2 * s - 2 * cntR; i++) {//상변
            temp[r - s + cntR][i + 1 + c - s + cntR] = map[r - s + cntR][i + c - s + cntR];
        }
        for (int i = 0; i < 2 * s - 2 * cntR; i++) {//우변
            temp[i + 1 + r - s + cntR][c + s - cntR] = map[i + r - s + cntR][c + s - cntR];
        }
        for (int i = 1; i <= 2 * s - 2 * cntR; i++) {//하변
            temp[r + s - cntR][i - 1 + c - s + cntR] = map[r + s - cntR][i + c - s + cntR];
        }
    }
    temp[r][c] = map[r][c];
    //대입
    for (int i = r - s; i <= r + s; i++) {
        for (int j = c - s; j <= c + s; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

void rotate_back(int r, int c, int s) {//반시계
    int temp[51][51] = { 0, };
    for (int cntR = 0; cntR < s; cntR++) {
        for (int i = 0; i < 2 * s - 2 * cntR; i++) {//좌변
            temp[i + 1 + r - s + cntR][c - s + cntR] = map[i + r - s + cntR][c - s + cntR];
        }
        for (int i = 1; i <= 2 * s - 2 * cntR; i++) {//상변
            temp[r - s + cntR][i - 1 + c - s + cntR] = map[r - s + cntR][i + c - s + cntR];
        }
        for (int i = 1; i <= 2 * s - 2 * cntR; i++) {//우변
            temp[i - 1 + r - s + cntR][c + s - cntR] = map[i + r - s + cntR][c + s - cntR];
        }
        for (int i = 0; i < 2 * s - 2 * cntR; i++) {//하변
            temp[r + s - cntR][i + 1 + c - s + cntR] = map[r + s - cntR][i + c - s + cntR];
        }
    }
    temp[r][c] = map[r][c];
    //대입
    for (int i = r - s; i <= r + s; i++) {
        for (int j = c - s; j <= c + s; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

void Avalue() {
    int temp = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            temp += map[i][j];
        }
        if (mini > temp)
            mini = temp;
        temp = 0;
    }
}

void permutate(int depth) {
    if (depth == K) {
        Avalue();
        return;
    }

    for (int i = 0; i < K; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            //이 시점에 갖고 있는 map을 
            rotate(r[i], c[i], s[i]);
            permutate(depth + 1); // 깊이 끝까지 가고 다른 경우를 탐색할 때 쓸 수 있어야 함
            rotate_back(r[i], c[i], s[i]);
            visited[i] = 0;
        }
    }
}

int main() {

    //입력
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    for (int idx = 0; idx < K; idx++) {
        cin >> r[idx] >> c[idx] >> s[idx];
    }
    for (int j = 1; j <= M; j++) {
        mini += map[1][j];
    }
    permutate(0);
    
    //출력
    cout << mini;

    return 0;
}