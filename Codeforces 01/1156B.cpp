#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define mk              make_pair
#define inf8            100000008

using namespace std;

int main()
{
    ll tc;
    cin >> tc;
    while(tc--){
        string ss , s="";
        cin >> ss ;
        map < char , ll > mp;
        queue < char > q;

        for (int i=0;i<ss.size();i++)mp[ss[i]]++;

        for (char i = 'a';i<='z';i++){
            if (mp[i])q.push(i);
        }
        bool temp = false;

        while(!q.empty()){
            ll n = s.size();

            if (s.empty()){
                s+=q.front();
                q.pop();
            }
            else if (abs(s[0]-q.front()) != 1){
                s = q.front()+s;
                q.pop();
            }
            else if (abs(s[n-1]-q.front()) != 1){
                s = s+q.front();
                q.pop();
            }
            else{
                if (q.size()==1){
                    cout << "No answer" << endl;
                    temp = true;
                    break;
                }
                else {
                    q.push(q.front());
                    q.pop();
                }
            }
        }

        if (temp){
            continue;
        }
        //cout << "    ok " << s << endl;

        for (int i=0;i<s.size();i++){
            for (int j=0;j<mp[s[i]];j++){
                cout << s[i];
            }
        }
        cout << endl;
    }

    return 0;
}

