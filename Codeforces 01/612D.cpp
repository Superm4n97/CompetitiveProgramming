#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,m;
map < ll , ll > mp , mark;
vector < ll > v;
vector < pair < ll , ll > > ans;
int main()
{

    cin >> n >> m;
    for (int i=0;i<n;i++){
        ll a , b;
        //cin >> a >> b;
        scanf("%I64d %I64d",&a,&b);
        if (mp[a]==0)v.push_back(a);
        mp[a]++;
        if (mp[b]==0)v.push_back(b);
        mp[b]--;
        if (a==b)mark[a] = 1;
    }
    sort(v.begin() , v.end());
    cout << "   size " << v.size() << endl;
    for (int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;

    ll x = 0 , index;
    if (mp[v[0]]>=m){
        x = 1;
        index = v[0];
    }
    else if (mark[v[0]] && m==1 && mp[v[0]]==0){
        ans.push_back({v[0],v[0]});
    }

    for (int i=1;i<v.size();i++){
        mp[v[i]]+=mp[v[i-1]];
        //cout << v[i] << "  -  " << mp[v[i]] << endl;

        if (x==1 && mp[v[i]]<m){
            ans.push_back({index , v[i]});
            x = 0;

        }
        else if (x==0 && mp[v[i]]>=m){
            x = 1;
            index = v[i];
        }
        else if(x==0 && m==1 && mark[v[i]]){
            ans.push_back({v[i],v[i]});
        }
        //cout << "  " << v[i] << " " << mark[v[i]] << endl;
    }
    if (!ans.empty())sort(ans.begin(),ans.end());
    //cout << ans.size() << endl;
    ll temp = ans.size();
    printf("%I64d\n",temp);
    for (int i=0;i<ans.size();i++){
        //cout << ans[i].first << " " << ans[i].second << endl;
        printf("%I64d %I64d\n",ans[i].first , ans[i].second);
    }

    return 0;
}
