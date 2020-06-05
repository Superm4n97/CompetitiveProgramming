#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define maxn 200005

using namespace std;

int firstOccur[15];

int main() {
    int TC;
    cin >> TC;
    while(TC--){
        memset(firstOccur, 0, sizeof firstOccur);
        int n; string s , sorted, solve;
        vector<int> v, t, all;
        cin >> n >> s;
        for(int i=0;i<n;i++){
            int x = s[i] - '0';
            if(!firstOccur[x]){
                firstOccur[x] = i+1;
            }
        }
        int  tt = 0;
        for(int i=9;i>=0;i--){
            if(firstOccur[i]){
                tt = i;
                break;
            }
        }
        int pos = 0;
        for(int i=n-1;i>=0;i--){
            int x = s[i] - '0';
            if(x == tt){
                pos = i + 1;
                break;
            }
        }

        for(int i=9;i>=0;i--){
            if(!firstOccur[i])continue;
            if( pos >= firstOccur[i]){
                for(int j=1;j<=pos;j++){
                    int x = s[j-1] - '0';
                    if(x == i)v.pb(j-1);
                }
                pos = firstOccur[i];
            }
            else{
                break;
            }
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        vector<int> vis;
        for(int i=0;i<n;i++){
            vis.push_back(0);
        }
        for(int i=0;i<v.size();i++)vis[v[i]] = 1;
        for(int i=0;i<n;i++){
            if(!vis[i])t.push_back(i);
        }
        //for(int i=0;i<t.size();i++)cout << t[i]<<" ";cout << endl;
        sorted = s;
        bool ans = true;
        sort(sorted.begin(), sorted.end());
        for(int i=0;i<t.size();i++) all.pb(s[t[i]] - '0');
        for(int i=0;i<v.size();i++) all.pb(s[v[i]] - '0');
        for(int i=0;i<n;i++){
            int x = sorted[i] - '0';
            //cout << x << " "<< all[i]<<endl;
            if(x != all[i]){
                ans = false;
                break;
            }
        }
        if(!ans) cout << '-' << endl;
        else{
            solve = s;
            for(int i=0;i<t.size();i++){
                solve[t[i]] = '1';
            }
            for(int i=0;i<v.size();i++){
                solve[v[i]] = '2';
            }
            cout << solve << endl;
        }

    }



    return 0;
}

