#include <iostream>
#include <cstring>

using namespace std;

void app(string& a, char c, int n) {
    for(int i=0;i<n;i++) {
        a+=c;
    }  
}

void solve(int c) {
    string in;
    cin >> in;

    string out;
    int depth=0;
    
    int e=in[0]-'0';
    app(out,'(',e);
    depth+=e;
    out+=in[0];

    for(int i=1;i<in.length();i++) {
        int dif=in[i]-in[i-1];
        if(dif>0) {
            app(out,'(',dif);
        } else if(dif<0) {
            app(out,')',abs(dif));
        }
        out+=in[i];
        depth+=dif;
    }
    
    app(out,')',depth);

    cout<<"Case #"<<c<<": "<<out;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        solve(i);  
    }

    return 0;
}
