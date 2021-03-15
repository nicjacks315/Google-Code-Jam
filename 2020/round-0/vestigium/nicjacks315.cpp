/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// Example program
#include <iostream>
#include <string>

#define ms 64

using namespace std;
typedef unsigned int ui;


bool dup( int v[], int s ) {
    for( unsigned int i=0; i<s; i++ ) {
        for( unsigned int j=0; j<s; j++ ) {
            if( j!= i && v[i]==v[j] ) {
                return true;
            }
        }
    }
    return false;
}

void rv( int m[ms][ms], int v[], int r, int s ) {
    for( ui c=0; c<s; c++ ) {
        v[c] = m[r][c];
    }
}

void cv( int m[ms][ms], int v[], int c, int s ) {
    for( ui r=0; r<s; r++ ) {
        v[r] = m[r][c];
    }
}

void solve( int n, int s ) {
    
    int m[ms][ms];
    int v[s];
    int k = 0, r = 0, c = 0;
    
    //build matrix, find trace
    for( unsigned int cc = 0; cc < s; cc++ ) {
        for( unsigned int rr = 0; rr < s; rr++ ) {
            cin >> m[rr][cc];
            k+=(rr==cc)?m[rr][cc]:0;
        }
    }
    
    //repeat c
    for( unsigned int cc = 0; cc < s; cc++ ) {
        cv(m,v,cc,s);
        c+=dup(v,s)?1:0;
    }
    
    //repeat r
    for( unsigned int rr = 0; rr < s; rr++ ) {
        rv(m,v,rr,s);
        r+=dup(v,s)?1:0;
    }
    
    cout<<"Case #"<<n+1<<": "<<k<<" "<<r<<" "<<c<<endl;
    
}



int main() {
    int n,s;
    cin>>n;
    for(ui i=0; i<n; i++) {
        cin>>s;
        solve(i,s);
    }
}

//ex. output Case #x: k r c
//x is case number
//k trace of square matrix (sum of diagonal elements from (0,0) to (n,n))
//r number of rows with repeat elements
//c number of colums with repeat elements
