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
#define inf             10000000

using namespace std;

string s;

int main()
{
    int n,cnt=0;
    cin >> n;
    vii v;
    map < int , int > mp;
    for (int j=0;j<n;j++){
        cin >> s;
        stack < char> st;
        int  nn = s.size();
        for (int i=0;i<nn;i++){
            if (st.empty() || s[i]=='(')st.push(s[i]);
            else {
                if (st.top()=='(')st.pop();
                else st.push(s[i]);
            }
        }
        string ss = "";
        if (st.empty()){
            mp[0]++;
            continue;
        }
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ss+=ch;
        }


        //cout <<"ok " << endl;

        nn  = ss.size();
        //cout << ss << endl;
        int temp=0;
        if (ss[0]=='(')temp=1;
        else temp=-1;
        for (int i=1;i<nn;i++){
            if (ss[i]!=ss[i-1]){
                temp=inf;
                break;
            }
            else {
                if (ss[i]=='(')temp++;
                else temp--;
            }
        }
        if (temp==inf)continue;
        if (mp[temp]==0)v.pb(temp);
        mp[temp]++;
        //cout << temp << endl;
    }
    for (int i=0;i<v.size();i++){
        int tut = v[i],put=tut*-1;
        if (mp[tut]){
                int mn = min(abs(mp[tut]),abs(mp[put]));
                //cout <<tut << "  " << mn << endl;
                cnt+=mn;
                //cout << tut*-1 << endl;
                mp[tut]=0;
        }
    }
    //cout << cnt << endl;
    cnt+=(mp[0]/2);
    cout << cnt << endl;

    return 0;
}
