#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define b back
#define s size

using namespace std;

struct a {
    a( int s, int e, int x ) : s(s), e(e), x(x) {}
    int s;
    int e;
    int x;
};

typedef vector<a> va;

bool cs(a a1, a a2) { 
    return (a1.s <= a2.s); 
} 

void solve() {
    
    int n;
    cin>>n;
    
    va v;
    int s,e;
    for(int i=0;i<n;i++) {
        cin>>s>>e;
        v.pb(a(s,e,i));
    }
    
    sort(v.begin(), v.end(), cs); 
    
    va ac, aj;
    ac.pb(v[0]);
    char out[n+1];
    out[v[0].x]='C';
    for(int i=1;i<n;i++) {
        if(v[i].s>=ac.b().e) {
            ac.pb(v[i]);
            out[v[i].x]='C';
        } else if(v[i].s>=(aj.s()>0?aj.b().e:0)) {
            aj.pb(v[i]);
            out[v[i].x]='J';
        } else {
            cout<<"IMPOSSIBLE"<<'\n';
            return;
        }
    }
    out[n+1]='\0';
    cout<<out<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c;
    cin>>c;
    for(int i=0;i<c;i++) {
        cout<<"Case #"<<i+1<<": ";
        solve(); 
    }
    
    return 0;
}
