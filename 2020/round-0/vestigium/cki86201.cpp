#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

void solve() {
	int n, a[110][110];
	scanf("%d", &n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d", a[i] + j);
	int r = 0, c = 0, k = 0;
	for(int i=1;i<=n;i++) k += a[i][i];
	int chk[110][110] = {};
	for(int i=1;i<=n;i++) {
		int ok = 0;
		for(int j=1;j<=n;j++) {
			if(chk[i][a[i][j]]) ok = 1;
			chk[i][a[i][j]] = 1;
		}
		r += ok;
	}
	memset(chk, 0, sizeof chk);
	for(int i=1;i<=n;i++) {
		int ok = 0;
		for(int j=1;j<=n;j++) {
			if(chk[i][a[j][i]]) ok = 1;
			chk[i][a[j][i]] = 1;
		}
		c += ok;
	}
	printf("%d %d %d\n", k, r, c);
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
