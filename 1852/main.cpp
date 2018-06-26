#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_NUM = 1000000;

int main() {
	int c;
	scanf("%d", &c);
	int l, n;
	int a[MAX_NUM];
	for (int num = 0; num < c; num++) {
		int max = 0;
		int min = 0;
		scanf("%d %d", &l, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			int tmp = std::max(a[i], l-a[i]);
			max = std::max(tmp, max);
			tmp = std::min(a[i], l-a[i]);
			min = std::max(tmp, min);
		}
		printf("%d %d\n", min, max);
	}
}
