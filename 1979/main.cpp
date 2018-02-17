#include <cstdio>

#define MAX_W 20
#define MAX_H 20
#define RED '#'
#define BLACK '.'
#define START '@'
#define CHECK 'C'

int W, H;
char map[MAX_H][MAX_W] = {0};
int sx, sy;
int addx[] = {0, 1, 0, -1}, addy[] = {-1, 0, 1, 0};

int dfs(int sum, int x, int y) {
	map[y][x] = CHECK;
	sum++;
	int s = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + addx[i];
		int ny = y + addy[i];
		if (0 <= nx && 0 <= ny && nx < W && ny < H && map[ny][nx] == BLACK)
			sum = dfs(sum, nx, ny);
	}
	return sum;
}

int main() {
	while (1) {
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0)
			break;
		for (int i = 0; i < H; i++)
			scanf("%s", map[i]);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				if (map[i][j] == START) {
					sx = j;
					sy = i;
					break;
				}
		int sum = dfs(0, sx, sy);
		printf("%d\n", sum);
	}
}
