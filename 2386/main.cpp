#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const char CHECK = 'C';
const int MAX_N = 100;
string str[MAX_N];
int N, M;
int addx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int addy[] = {-1, -1, -1, 0, 1, 1, 1, 0};

void dfs(int y, int x) {
	str[y][x] = CHECK;
	for (int i = 0; i < 8; i++) {
		int nx = x+addx[i];
		int ny = y+addy[i];
		if (nx < 0 || ny < 0 || N <= ny || M <= nx)
			continue;
		if (str[ny][nx] != 'W')
			continue;
		dfs(ny, nx);
	}
}

int solve() {
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (str[i][j] == 'W') {
				dfs(i, j);
				sum++;
			}
	return sum;
				
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i  < N; i++)
		cin >> str[i];
	int sum = solve();
	cout << sum << endl;
}
