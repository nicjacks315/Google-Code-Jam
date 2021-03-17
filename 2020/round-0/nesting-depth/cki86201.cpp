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
	char In[110];
	scanf("%s", In);
	int t = 0;
	for(int i=0;In[i];i++) {
		int c = In[i] - '0';
		while(t < c) printf("("), ++t;
		while(t > c) printf(")"), --t;
		printf("%c", In[i]);
	}
	while(t > 0) printf(")"), --t;
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
