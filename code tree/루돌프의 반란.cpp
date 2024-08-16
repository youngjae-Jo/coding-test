#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, P, C, D;
int Rr, Rc;
int maap[51][51];

struct snt {
    int row = 0;
    int col = 0;
    int alive = 1;
    int rest = 0;
    int score = 0;
};

snt santa[31];

void input() {
    cin >> N >> M >> P >> C >> D;
    cin >> Rr >> Rc;

    for (int i = 1; i <= P; i++) {
        int idx = 0;
        cin >> idx;
        cin >> santa[idx].row >> santa[idx].col;
        maap[santa[idx].row][santa[idx].col] = idx;
    }
}


int dist(int a, int b, int c, int d) {
    int diff_r = a - c;
    int diff_c = b - d;
    return diff_r * diff_r + diff_c * diff_c;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        if (santa[a.second].row == santa[b.second].row)
            return santa[a.second].col > santa[b.second].col;
        return santa[a.second].row > santa[b.second].row;
    }
    return a.first < b.first;
}

int nearest_santa(int r, int c) {
    vector<pair<int, int>> s;

    for (int i = 1; i <= P; i++) {
        if (santa[i].alive) {
            int d = dist(r, c, santa[i].row, santa[i].col);
            pair<int, int> pp = make_pair(d, i);
            s.push_back(pp);
        }
    }
    sort(s.begin(), s.end(), compare);
    return s[0].second;
}

int direction(int rr, int rc, int sr, int sc) {
    if (rr > sr && rc > sc)//����
        return 0;
    else if (rr > sr && rc == sc)//��
        return 1;
    else if (rr > sr && rc < sc)//����
        return 2;
    else if (rr == sr && rc < sc)//��
        return 3;
    else if (rr < sr && rc < sc)//����
        return 4;
    else if (rr < sr && rc == sc)//��
        return 5;
    else if (rr < sr && rc > sc)//�޾�
        return 6;
    else if (rr == sr && rc > sc)//��
        return 7;

    return -1;
}

bool is_out(int num) {//���� �ȿ� �ֳ�
    bool res = false;
    if (santa[num].row < 1 || santa[num].row > N || santa[num].col < 1 || santa[num].col > N)
        res = true;
    return res;
}

void ludolph_santa(int mode, int dir);

void santa_santa(int a, int dir) {//��Ÿ���� �浹, ���� �� �Ϻ�
    int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };//���� �� ���� �� ���� �� �޾� ��   
    int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    int b = maap[santa[a].row][santa[a].col];
    maap[santa[a].row][santa[a].col] = a;//����

    santa[b].row += dx[dir];
    santa[b].col += dy[dir];
    int newRow = santa[b].row;
    int newCol = santa[b].col;
    if (is_out(b))
        santa[b].alive = 0;
    else {
        if (maap[newRow][newCol] != 0)
            santa_santa(b, dir);
        else if (newRow == Rr && newCol == Rc)
            ludolph_santa(2, dir);
        else
            maap[newRow][newCol] = b;
    }
}


void ludolph_santa(int mode, int dir) {//�絹�� ��Ÿ �浹
    int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };//���� �� ���� �� ���� �� �޾� ��   
    int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    if (mode == 1) {
        int santa_num = maap[Rr][Rc];
        maap[Rr][Rc] = 0; //���� �ִ� �� ����
        santa[santa_num].score += C;
        santa[santa_num].rest += 2;
        santa[santa_num].row += C * dx[dir];
        santa[santa_num].col += C * dy[dir];

        int newRow = santa[santa_num].row;
        int newCol = santa[santa_num].col;

        if (is_out(santa_num))
            santa[santa_num].alive = 0;
        else if (maap[newRow][newCol] != 0)
            santa_santa(santa_num, dir);
        else
            maap[newRow][newCol] = santa_num;

    }
    else if (mode == 2) {
        int santa_num = maap[Rr][Rc];

        if (dir == 0) dir = 5;
        else if (dir == 1) dir = 7;
        else if (dir == 2) dir = 1;
        else if (dir == 3) dir = 3;

        maap[Rr][Rc] = 0; //���� �ִ� �� ����
        santa[santa_num].score += D;
        santa[santa_num].rest += 2;
        santa[santa_num].row += D * dx[dir];
        santa[santa_num].col += D * dy[dir];

        int newRow = santa[santa_num].row;
        int newCol = santa[santa_num].col;

        if (is_out(santa_num))
            santa[santa_num].alive = 0;
        else if (maap[newRow][newCol] != 0)
            santa_santa(santa_num, dir);
        else
            maap[newRow][newCol] = santa_num;
    }
}

void ludolph_move() {
    int s_num = nearest_santa(Rr, Rc);
    int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };//���� �� ���� �� ���� �� �޾� ��   
    int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    int dir = direction(Rr, Rc, santa[s_num].row, santa[s_num].col);

    Rr += dx[dir]; Rc += dy[dir]; //�絹�� ��ġ ����

    if (maap[Rr][Rc] != 0)//�Űܰ� ���� ��Ÿ�� �ִ� ���
        ludolph_santa(1, dir);
}

bool isis_out(int row, int col) {//���� �ȿ� �ֳ�
    bool res = false;
    if (row < 1 || row > N || col < 1 || col > N)
        res = true;
    return res;
}

int santa_direction(int row, int col) {
    int dx[4] = { -1, 0, 1, 0 };//�������  
    int dy[4] = { 0, 1, 0, -1 };

    int distance = dist(row, col, Rr, Rc);
    int res = -1;

    vector <pair<int, int>> candi;
    for (int i = 0; i < 4; i++) {
        int nr = row + dx[i];
        int nc = col + dy[i];
        if (!isis_out(nr, nc)) {
            int candi_dist = dist(nr, nc, Rr, Rc);
            if (!maap[nr][nc] && distance > candi_dist) {
                pair<int, int> c = make_pair(candi_dist, i);
                candi.push_back(c);
            }
        }
    }

    if (candi.size() == 0)// �� ���� ��
        return -1;
    else if (candi.size() == 1) //�ĺ��� �ϳ�
        return candi[0].second;
    else if (candi[0].first == candi[1].first) {//2�� �ĺ� �Ÿ��� ������ �������
        if (candi[0].second < candi[1].second)
            res = candi[0].second;
        else
            res = candi[1].second;
    }
    else {//�� ��������� ������
        if (candi[0].first < candi[1].first)
            res = candi[0].second;
        else
            res = candi[1].second;
    }

    return res;
}

void santa_move() {
    int dx[4] = { -1, 0, 1, 0 };//�������  
    int dy[4] = { 0, 1, 0, -1 };

    for (int i = 1; i <= P; i++) {
        if (santa[i].alive && santa[i].rest == 0) {
            int dir = santa_direction(santa[i].row, santa[i].col);
            if (dir >= 0) {//��ȿ�Ҷ�
                //�絹������ ����� ���� �������� �̵�, ��ĭ�� ����, ������� �켱 ����
                maap[santa[i].row][santa[i].col] = 0; //���� �ִ� �ڸ� ����
                santa[i].row += dx[dir];
                santa[i].col += dy[dir];
                int nx = santa[i].row;
                int ny = santa[i].col;
                maap[nx][ny] = i; //�Űܰ�
                if (Rr == nx && Rc == ny)
                    ludolph_santa(2, dir);
            }
        }
    }
}

bool is_end() {
    bool res = true;
    for (int i = 1; i <= P; i++) {
        if (santa[i].alive)
            return false;
    }
    return res;
}

void solve() {
    for (int i = 1; i <= M; i++) {
        ludolph_move();
        if (is_end())  return;

        santa_move();
        if (is_end())  return;

        for (int idx = 1; idx <= P; idx++) {//�� �����̰� ��������� ���� ����
            if (santa[idx].alive)
                santa[idx].score++;
            if (santa[idx].rest != 0)
                santa[idx].rest--;
        }
        cout << "lu = " << Rr << ", " << Rc << endl;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << maap[i][j] << " ";
            }
            cout << endl;
        }
        cout << "score = ";
        for (int i = 1; i <= P; i++)
            cout << santa[i].score << " ";
        cout << endl;

    }
}

void output() {
    for (int i = 1; i <= P; i++)
        cout << santa[i].score << " ";
}

int main() {
    input();
    solve();
    output();

    return 0;
}