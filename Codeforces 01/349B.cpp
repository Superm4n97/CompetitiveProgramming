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

int A[1000006][11] , C[11];
int n , mn = 10000000 , index;

void solve1()
{
    scd(n);
    for (int i=1;i<=9;i++){
        scd(C[i]);
        if (mn>=C[i]){
            mn = C[i];
            index = i;
        }
    }

    map < int , int > mp;
    int temp = n/mn , tut = n%mn;
    mp[index] = temp;

    while(tut>0){
        //cout << tut << endl;
        bool tt = true;
        for (int i=9;i>index;i--){
            if (tut+mn >= C[i]){
                mp[index] --;
                mp[i]++;
                tt = false;
                tut = tut+mn-C[i];
                break;
            }
        }
        if (tt)break;
    }
    bool ans = true;
    //cout << "ok 2 " << mp[5] << endl;
    for (int i=9;i>=1;i--){
        for (int j=0;j<mp[i];j++){
            cout << i;
            ans = false;
        }
    }
    if (ans)cout <<-1;
    cout << endl;
}

void solve2()
{

}

int main()
{
    //solve1();

    return 0;
}

