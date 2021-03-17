//Notes:
//  0) Works for both test cases
//  1) I've done this before in writing my own XML parser:
//  2) Take the difference in nesting depth and stick in appropriate number of open/close parentheses
//  3) Only works for constructing your own nested data structure, doesnt work for reading as malformed structures break the algorithm
//  4) Could be cleaner by using c-style strings, but in the name of time I used std::string
//  5) This whole thing can written in about 3 lines in python
//  6) Other contestants favored while loops and directly appending parentheses chars, but more or less did the same thing
//  7) Other contestants eliminated the calculation of dif with the while loops

#include <iostream>
#include <cstring>

using namespace std;

//append chars
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
    
    //handle first char
    int e=in[0]-'0';
    app(out,'(',e);
    depth+=e;
    out+=in[0];

    //add chars based on delta depth
    int dif;
    for(int i=1;i<in.length();i++) {
        dif=in[i]-in[i-1];
        if(dif>0) {
            app(out,'(',dif);
        } else if(dif<0) {
            app(out,')',dif*-1);
        }
        out+=in[i];
        depth+=dif;
    }
    
    //close out remaining
    app(out,')',depth);

    cout<<"Case #"<<c<<": "<<out<<'\n';
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
