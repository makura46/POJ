#include <cstdio>
#include <algorithm>
using namespace std;

#define SPACE 0
#define BLOCK 1
#define START 2
#define GOAL 3
#define MAX_W 20
#define MAX_H 20

int W, H;
int gx, gy;
int sx, sy;
int addx[] = {0, 1, 0, -1};
int addy[] = {-1, 0, 1, 0};

void copy(char cp[MAX_H][MAX_W], char c[MAX_H][MAX_W]) {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cp[i][j] = c[i][j];
}

int dfs(int level, char map[MAX_H][MAX_W], int x, int y) {
	int sum = 1000;
	if (level == 10)
		return -1;
	else {
		for (int i = 0; i < 4; i++) {
			int nx = x+addx[i];
			int ny = y+addy[i];
			if (0 <= nx && 0 <= ny && nx < W && ny < H && map[ny][nx] == BLOCK)
				continue;
			char cpMap[MAX_H][MAX_W];
			copy(cpMap, map);
			while (1) {
				if (0 <= nx && 0 <= ny && nx < W && ny < H) {
					if (nx == gx && ny == gy)
						return level+1;
					if (cpMap[ny][nx] == SPACE) {
						nx += addx[i];
						ny += addy[i];
					} else if (cpMap[ny][nx] == BLOCK) {
						cpMap[ny][nx] = SPACE;
						ny -= addy[i];
						nx -= addx[i];
						break;
					}
				} else {
					break;
				}
			}
			if (nx < 0 || ny < 0 || W <= nx || H <= ny) 
				continue;
			int tmp = dfs(level+1, cpMap, nx, ny);
			if (tmp == -1)
				tmp = 100;
			sum = min(sum, tmp);
		}
	}
	return sum;
}

int main() {
	char map[MAX_H][MAX_W];
	while (1) {
		scanf("%d %d", &W, &H);
		if (!W && !H)
			break;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				int tmp;
				scanf("%d", &tmp);
				map[i][j] = tmp;
			}
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (map[i][j] == START) {
					sx = j;
					sy = i;
					map[i][j] = SPACE;
				} else if (map[i][j] == GOAL) {
					gx = j;
					gy = i;
					map[i][j] = SPACE;
				}
		int sum = dfs(0, map, sx, sy);
		if (sum > 10)
			sum = -1;
		printf("%d\n", sum);
	}
}
