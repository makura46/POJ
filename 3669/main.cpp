#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_X 302
#define MAX_Y 302
#define MAX_T 1000

int M;
int map[MAX_Y][MAX_X];
bool b[MAX_Y][MAX_X];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int bfs() {
	int sum = 0;
	int step = 1;
	queue<int> qx, qy;
	qx.push(0);
	qy.push(0);
	b[0][0] = true;
	while (!qx.empty()) {
		int size = qx.size();
		for (int i = 0; i < size; i++) {
			int x = qx.front();
			int y = qy.front();
			qx.pop();
			qy.pop();
			if (map[y][x] == -1)
				return sum;
			if (map[y][x] <= sum)
				continue;
			for (int j = 0; j < 4; j++) {
				int nx = x+dx[j], ny = y+dy[j];
				if (nx < 0 || ny < 0 || MAX_X <= nx || MAX_Y <= ny || b[ny][nx]) continue;
				if (map[ny][nx] <= step && map[ny][nx] != -1) continue;
				b[ny][nx] = true;
				qx.push(nx);
				qy.push(ny);
			}
		}
		step++;
		sum++;
	}
	return -1;
}

int main() {
	scanf("%d", &M);
	for (int i = 0; i < MAX_Y; i++)
		for (int j = 0; j < MAX_X; j++)
			map[i][j] = -1;
	for (int i = 0; i < M; i++) {
		int x, y, tmp;
		scanf("%d %d %d", &x, &y, &tmp);
		if (map[y][x] >= 0)
			map[y][x] = min(map[y][x], tmp);
		else
			map[y][x] = tmp;
		for (int j = 0; j < 4; j++) {
			int nx = x+dx[j], ny = y+dy[j];
			if (nx < 0 || ny < 0 || MAX_X <= nx || MAX_Y <= ny)
				continue;
			if (map[ny][nx] >= 0)
				map[ny][nx] = min(map[ny][nx], tmp);
			else
				map[ny][nx] = tmp;
		}
	}
	int sum = bfs();
	printf("%d\n", sum);
}
