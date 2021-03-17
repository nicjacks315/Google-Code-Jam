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

pii A[1010];
int E[1010][1010], color[1010], n;

void dfs(int x, int c) {
	color[x] = c;
	for(int i=1;i<=n;i++) if(E[x][i] && color[i] == 0) dfs(i, 3 - c);
}

void solve() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d%d", &A[i].Fi, &A[i].Se);
	memset(E, 0, sizeof E);
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) {
		int lv = max(A[i].Fi, A[j].Fi);
		int rv = min(A[i].Se, A[j].Se);
		if(lv < rv) E[i][j] = E[j][i] = 1;
	}
	memset(color, 0, sizeof color);
	for(int i=1;i<=n;i++) if(color[i] == 0) dfs(i, 1);
	int ok = 1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(E[i][j] && color[i] == color[j]) ok = 0;
	if(!ok) puts("IMPOSSIBLE");
	else {
		for(int i=1;i<=n;i++) printf("%c", color[i] == 1 ? 'J' : 'C'); puts("");
	}
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
