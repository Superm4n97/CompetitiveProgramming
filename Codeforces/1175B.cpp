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
#define mx              4294967295
using namespace std;

ll n,x=0;
bool overflow = false;
stack < ll > st;
//mx=4294967295‬
int main()
{
   // cout << mx << endl;
    ll n;
    cin >> n;

    for (int i=0;i<n;i++){
        string s;
        cin >>s;

        if (s=="add"){
            st.push(1);
        }
        else if (s=="for"){
            ll a;
            cin >> a;
            a*=-1;
            st.push(a);
        }
        else if (s=="end") {
            ll tut = 0;
            while(!st.empty()){
                if (st.top()<0)break;
                tut+=st.top();
                st.pop();
            }
            if (!st.empty()){
                ll temp = st.top();
                st.pop();
                temp*=-1;
                tut*=temp;
            }
            st.push(tut);
            if (tut>mx)overflow = true;
        }
    }

    if (!st.empty()){
        ll temp = 0;
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        st.push(temp);
        if (temp>mx)overflow = true;
    }
    if (st.empty())st.push(0);
    if (overflow)cout << "OVERFLOW!!!" << endl;
    else {
        cout << st.top() << endl;
    }


    return 0;
}

