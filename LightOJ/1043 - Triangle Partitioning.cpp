#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int _t=1;_t<=tc;_t++){
        double A,B,C,S,area,rat;
        cin >> A >> B >> C >> rat;
        S=(A+B+C)/2;
        area= sqrt(S*(S-A)*(S-B)*(S-C));
        double b=0,e=A,mid;
        for (int i=0;i<60;i++){
            mid = (b+e)/2.0;
            double ade,bdec;
            ade = area*mid/A;
            bdec = area-ade;
            if(ade/bdec>rat)e = mid;
            else b=mid;
        }
        printf("Case %d: %.5f\n",_t,mid);
    }


    return 0;
}
