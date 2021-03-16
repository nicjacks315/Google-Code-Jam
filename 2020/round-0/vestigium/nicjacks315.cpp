//Notes: lots of changes can be made here
//  1) dup function can either return an int or we can remove the ternary conditional operator to avoid unnecessary +=0 operations
//  2) ternary conditional operator could also be removed in trace summation to save a few operations
//  3) v[s] could be pulled to higher scope to avoid unnecessary deallocations, but this comes at the cost of memory
//  4) function declarations could be organized a little better
//  5) rv, cv, and dup could probably be rolled into two functions to avoid 2 extra loops
//  6) the buffer matrix could be allocated to the heap, less memory and more robust program at the cost of speed
//  7) there exists better algorithms for finding dups
//  8) 

#include <iostream>

#define ms 64

using namespace std;

//vector has dups
bool dup(int v[], int s) {
    for(int i=0; i<s; i++) {
        for(int j=0; j<s; j++) {
            if(j!= i && v[i]==v[j]) {
                return true;
            }
        }
    }
    return false;
}

//get row
void rv(int m[ms][ms], int v[], int r, int s) {
    for(int c=0; c<s; c++) {
        v[c]=m[r][c];
    }
}

//get col
void cv(int m[ms][ms], int v[], int c, int s) {
    for(int r=0; r<s; r++) {
        v[r]=m[r][c];
    }
}

void solve(int n, int s, int m[ms][ms]) {
    
    int v[s];
    int k=0, r=0, c=0;
    
    //build matrix, find trace
    for(int cc = 0; cc < s; cc++) {
        for(int rr = 0; rr < s; rr++) {
            cin>>m[rr][cc];
            k+=(rr==cc)?m[rr][cc]:0;
        }
    }
    
    //cols with dups
    for(int cc = 0; cc < s; cc++) {
        cv(m,v,cc,s);
        c+=dup(v,s)?1:0;
    }
    
    //rows with dups
    for(int rr = 0; rr < s; rr++) {
        rv(m,v,rr,s);
        r+=dup(v,s)?1:0;
    }
    
    cout<<"Case #"<<n+1<<": "<<k<<" "<<r<<" "<<c<<"\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,s,m[ms][ms];
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>s;
        solve(i,s,m);
    }
    
    return 0;
}
