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
	int n = nxt();
	vector<vector<int>> a(n);
	for (auto& v : a) {
		v.resize(n);
		generate(all(v), nxt);
	}
	int trace = 0;
	for (int i = 0; i < n; ++i) {
		trace += a[i][i];
	}
	cout << trace << " ";
	int rows = 0;
	for (int i = 0; i < n; ++i) {
		auto v = a[i];
		sort(all(v));
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (v[j] != j + 1) {
				ok = false;
			}
		}
		rows += !ok;
	}
	cout << rows << " ";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			swap(a[i][j], a[j][i]);
		}
	}
	int cols = 0;
	for (int i = 0; i < n; ++i) {
		auto v = a[i];
		sort(all(v));
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (v[j] != j + 1) {
				ok = false;
			}
		}
		cols += !ok;
	}
	cout << cols << "\n";
}

int main() {
	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
