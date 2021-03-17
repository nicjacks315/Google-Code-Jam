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

struct Activity {
	int id;
	int from;
	int to;

	bool operator <(const Activity& ot) {
		return tie(from, to) < tie(ot.from, ot.to);
	}
};

bool intersect(const Activity& fst, const Activity& snd) {
	return max(fst.from, snd.from) < min(fst.to, snd.to);
}

void solve() {
	int n = nxt();
	vector<Activity> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].id = i;
		a[i].from = nxt();
		a[i].to = nxt();
	}
	vector<vector<int>> g(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (intersect(a[i], a[j])) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}

	string ans(n, 0);
	for (int i = 0; i < n; ++i) {
		if (ans[i]) {
			continue;
		}
		vector<int> st = {i};
		ans[i] = 'C';
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (int x : g[v]) {
				if (ans[x]) {
					if (ans[x] == ans[v]) {
						cout << "IMPOSSIBLE\n";
						return;
					}
				} else {
					ans[x] = (ans[v] == 'C') ? 'J' : 'C';
					st.push_back(x);
				}
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
