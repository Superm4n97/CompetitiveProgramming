#include <bits/stdc++.h>
#define ll long long
#define maxn 1000000
using namespace std;


int main(){
    string s, t = "0000";
    int mx = 0;
    for(int i=4;i<10;i++){
        char c = '0' + i;
        s = "0123";
        s[0] = c;
        for(int j=0;j<4;j++)printf("%c", s[j]);
        printf("\n");
        fflush(stdout);

        int x, y;
        cin >> x >> y;
        if(x == 4) return 0;
        if(x >= mx){
            mx = x;
            t[0] = c;
        }
    }

    mx = 0;
    for(int i=0;i<7;i++){
        char c = '0' + i;
        s = "0789";
        s[0] = c;
        for(int j=0;j<4;j++)printf("%c", s[j]);
        printf("\n");
        fflush(stdout);

        int x, y;
        cin >> x >> y;
        if(x == 4) return 0;
        if(x >= mx){
            mx = x;
            t[0] = c;
        }
    }

    mx = 0;
    for(int i=0;i<3;i++){
        char c = '0' + i;
        s = t;
        s[1] = c;
        for(int j=0;j<4;j++)printf("%c", s[j]);
        printf("\n");
        fflush(stdout);
        int x, y;
        cin >> x >> y;
        if(x == 4) return 0;
        if(x >= mx){
            mx = x;
            t[1] = c;
        }
    }

    mx = 0;
    for(int i=0;i<3;i++){
        char c = '0' + i;
        s = t;
        s[2] = c;
        for(int j=0;j<4;j++)printf("%c", s[j]);
        printf("\n");
        fflush(stdout);
        int x, y;
        cin >> x >> y;
        if(x == 4) return 0;
        if(x >= mx){
            mx = x;
            t[2] = c;
        }
    }

    mx = 0;
    for(int i=0;i<3;i++){
        char c = '0' + i;
        s = t;
        s[3] = c;
        for(int j=0;j<4;j++)printf("%c", s[j]);
        printf("\n");
        fflush(stdout);
        int x, y;
        cin >> x >> y;
        if(x == 4) return 0;
        if(x >= mx){
            mx = x;
            t[3] = c;
        }
    }
    return 0;
}
