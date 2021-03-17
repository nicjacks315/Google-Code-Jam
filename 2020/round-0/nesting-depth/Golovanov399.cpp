#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	auto t = s;
	vector<int> open(n), close(n);
	for (char d = '9'; d > '0'; --d) {
		int l = -1, r = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == d) {
				if (r == -1) {
					l = r = i;
				} else if (i > r + 1) {
					open[l] += 1;
					close[r] += 1;
					l = r = i;
				} else {
					r = i;
				}
				--s[i];
			}
		}
		if (r > -1) {
			open[l] += 1;
			close[r] += 1;
		}
	}
	s = t;
	for (int i = 0; i < n; ++i) {
		cout << string(open[i], '(') << s[i] << string(close[i], ')');
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
