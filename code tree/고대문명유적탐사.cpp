#include <iostream>
#include <queue>

#define N_large 5
#define N_small 3

using namespace std;

class Board {
public:
    int a[N_large][N_large];
private:
    bool InRange(int y, int x) {
        return 0 <= y && y < N_large && 0 <= x && x < N_large;
    }
public:
    Board() {
        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++)
                a[i][j] = 0;
        }
    }
    Board* Rotate(const int sy, const int sx, const int cnt) {
        Board* result = new Board();
        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                result->a[i][j] = a[i][j];
            }
        }
        for (int k = 0; k < cnt; k++) {
            int tmp = result->a[sy + 0][sx + 2];
            result->a[sy + 0][sx + 2] = result->a[sy + 0][sx + 0];
            result->a[sy + 0][sx + 0] = result->a[sy + 2][sx + 0];
            result->a[sy + 2][sx + 0] = result->a[sy + 2][sx + 2];
            result->a[sy + 2][sx + 2] = tmp;
            tmp = result->a[sy + 1][sx + 2];
            result->a[sy + 1][sx + 2] = result->a[sy + 0][sx + 1];
            result->a[sy + 0][sx + 1] = result->a[sy + 1][sx + 0];
            result->a[sy + 1][sx + 0] = result->a[sy + 2][sx + 1];
            result->a[sy + 2][sx + 1] = tmp;
        }
        return result;
    }
    int CalScore() {
        int score = 0;
        bool visit[N_large][N_large];
        int dy[4] = { 0,1,0,-1 }, dx[4] = { 1,0,-1,0 };
        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                visit[i][j] = false;
            }
        }
        for (int i = 0; i < N_large; i++) {
            for (int j = 0; j < N_large; j++) {
                if (!visit[i][j]) {
                    queue<pair<int, int> > q, trace;
                    q.push(make_pair(i, j));
                    trace.push(make_pair(i, j));
                    visit[i][j] = true;
                    while (!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int ny = cur.first + dy[k], nx = cur.second + dx[k];
                            if (InRange(ny, nx) && a[ny][nx] == a[cur.first][cur.second] && (!visit[ny][nx])) {
                                q.push(make_pair(ny, nx));
                                trace.push(make_pair(ny, nx));
                                visit[ny][nx] = true;
                            }
                        }
                    }


                    if (trace.size() >= 3) {
                        score += trace.size();
                        while (!trace.empty()) {
                            pair<int, int>t = trace.front();
                            trace.pop();
                            a[t.first][t.second] = 0;
                        }
                    }
                }
            }
        }

        return score;
    }
    void Fill(queue<int>* que) {
        for (int j = 0; j < N_large; j++) {
            for (int i = N_large - 1; i >= 0; i--) {
                if (a[i][j] == 0) {
                    a[i][j] = que->front();
                    que->pop();
                }
            }
        }
    }


};

int main() {
    int M, K;
    queue<int>q;
    Board* board = new Board();
    //입력 받기
    cin >> K >> M;
    for (int i = 0; i < N_large; i++) {
        for (int j = 0; j < N_large; j++) {
            cin >> board->a[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        q.push(t);
    }

    //K번탐사
    //회전: 1차 획득 최대화, 회전각도 가장 작은, 중심점 열이 작은, 행이 작은
    //획득 안되면 종료
    //획득했으면 채움
    while (K--) {
        int maxScore = 0;
        Board* maxScoreBoard = NULL;
        for (int cnt = 1; cnt <= 3; cnt++) {

            for (int sx = 0; sx <= N_large - N_small; sx++) {
                for (int sy = 0; sy <= N_large - N_small; sy++) {
                    Board* rotated = board->Rotate(sy, sx, cnt);
                    int score = rotated->CalScore();
                    if (maxScore < score) {
                        maxScore = score;
                        maxScoreBoard = rotated;
                    }
                }
            }

        }
        if (maxScoreBoard == NULL)
            break;
        board = maxScoreBoard;

        while (true) {
            board->Fill(&q);
            int newScore = 0;
            newScore = board->CalScore();
            if (newScore == 0) break;
            maxScore += newScore;
        }
        cout << maxScore << " ";

    }

}