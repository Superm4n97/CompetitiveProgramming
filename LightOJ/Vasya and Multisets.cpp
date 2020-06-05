#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define mk          make_pair

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector < int > v;
    input(v,n);
    vector < pair < int , int > > vp;
    map < int , int > mp,mm2;
    for (int i=0;i<n;i++){
        mp[v[i]]++;
    }
    for (int i=0;i<n;i++){
        if (mm2[v[i]]==0){
            vp.pb(mk(mp[v[i]],v[i]));
            mm2[v[i]]=1;
        }
    }
    srt(vp);
    vii v1,v2;
    int s1=0,s2=0;
    for (int i=0;i<vp.size();i++){
        int tut = vp[i].second;
        if(s1<s2){
            v1.pb(tut);
            s1++;
            mp[tut]--;
            if (mp[tut] ==1){
                mp[tut]--;
                v2.pb(tut);
                s2++;
                continue;
            }
            while(mp[tut]!=0){
                v2.pb(tut);
                mp[tut]--;
            }
        }
        else if (s1>s2){
            v2.pb(tut);
            s2++;
            mp[tut]--;
            if (mp[tut] ==1){
                mp[tut]--;
                v1.pb(tut);
                s1++;
                continue;
            }
            while(mp[tut]!=0){
                v1.pb(tut);
                mp[tut]--;
            }
        }
        else {
          //  cout << "mp tut " << mp[tut]  << "   tut " << tut<< endl;
            if (mp[tut]==1){
                mp[tut]--;
                v1.pb(tut);
                s1++;
        //cout << "dhoke" << endl;
                continue;
            }
            while(mp[tut]!=0){
                v1.pb(tut);
            //    cout << "dhoke 2" << endl;
                mp[tut]--;
            }
        }
    }
//    cout << "s1 " << s1 << "    s2 " << s2 << endl;
//    cout << v1.size() << " " << v2.size() << endl;
    if (s1!=s2){
        cout << "NO" << endl;
        return 0;
    }
    string st = "";
    for(int i=0;i<105;i++){
        st+="*";
    }
    for (int i=0;i<v1.size();i++){
        for (int j=0;j<n;j++){
            if (v[j]==v1[i]){
                st[j]='A';
                v[j]=-1;
                break;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (st[i]=='*')st[i]='B';
    }
//
//    for (int i=0;i<v1.size();i++)cout << v1[i] << " ";
//    cout << endl;
//    for (int i=0;i<v2.size();i++)cout << v2[i] << " ";
//    cout << endl;
    cout << "YES" << endl;
    for (int i=0;i<n;i++)cout << st[i] ;
    cout << endl;


    return 0;
}
