#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 2000;
int N;
char s[MAX_N+2] = {0};
char str[MAX_N+2] = {0};

void solve() {
	int f = 0, e = N-1;
	for (int i = 0; i < N; i++) {
		int tmpf = f, tmpe = e;
		while (1) {
			if (str[tmpf] == str[tmpe] && tmpf < tmpe) {
				tmpf++;
				tmpe--;
			} else 
				break;	
		}
		if (str[tmpf] < str[tmpe]) {
			s[i] = str[f];
			f++;
		} else {
			s[i] = str[e];
			e--;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i && !(i % 80))
			cout << endl;
		cout << s[i];
	}
	cout << endl;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	solve();
}
