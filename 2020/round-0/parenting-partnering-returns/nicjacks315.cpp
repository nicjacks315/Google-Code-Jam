//Notes:
//  1) Should work for test case #2 with greedy activity assignment, but I didn't time this one
//  2) Could cut back on memory usage by slimming down the struct vectors
//  3) Realistically only need to track the end times of events so we know when people are busy until
//  4) Taking some notes from other contestants - defining some of the std::vector methods as short hand symbols makes typing go alot faster
//  5) Without looking at the analysis, I arrived at pre-sorting and greedy assignment as the optimal solution
//  6) Seems like testing all possible combinations or treating this as a graph problem is way over-engineering for this problem

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
    out[n]='\0';
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
