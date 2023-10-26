#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct pos {
	int x, y;
};

int N, M;
int MIN = 987654321; // 출력할 도시의 치킨 거리 최솟값
bool selected[13];
vector<pos> house;
vector<pos> chicken;
vector<pos> picked;

int dist(pos a, pos b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void minDist() {
	int res = 0;
    for (int i = 0; i < house.size(); i++) // 각 집으로부터
    {
        int min_dist = 987654321;
        for (int j = 0; j < picked.size(); j++) // 모든 고른 치킨집에 대해
        {
            min_dist = min(min_dist, dist(house[i], picked[j])); // 최소 치킨거리 찾아
        }
        res += min_dist; // 최소 도시의 치킨거리 구함
    }
    MIN = min(MIN, res);
}

void find(int idx, int m) {
    if (m == M) {
        minDist();
    }

    for (int i = idx; i < chicken.size(); i++) {
        if (selected[i] == 1)
            continue;
        selected[i] = true;
        picked.push_back({ chicken[i].x, chicken[i].y });
        find(i, m + 1);
        selected[i] = false;
        picked.pop_back();
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                house.push_back({ i, j });
            else if (tmp == 2)
                chicken.push_back({ i, j });
        }
    }
    find(0, 0);
    cout << MIN << endl;
    return 0;
}