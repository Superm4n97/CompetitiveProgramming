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

double LikelihoodTable[100][5];

map < int , string >mp;

int main()
{
    cout << "Input number of dataset: ";
    int n , temp = 0;
    cin  >> n;
    for (int _i=0;_i<n;_i++){
        string s1 , s2;
        for (int i=0;i<s1.size();i++){
            if (s1[i]<95)s1[i]+=32;
        }
        for (int i=0;i<s2.size();i++){
            if (s2[i]<95)s2[i]+=32;
        }
        int tut  = 0;
            for (int i=1;i<=temp;i++){
                if (mp[i]==s1)tut = i;
            }
        if (tut==0){
            temp++;
            mp[temp]=s1;
            tut = temp;
        }
        if (s2 == "yes")LikelihoodTable[tut][1] +=1;
        else LikelihoodTable[tut][2] +=1;
    }

    cout << "Insert Number of new data: ";
    int q;
    cin >> q;

    double xx = 0 , yy = 0;
    for (int i=1;i<=temp;i++){
        LikelihoodTable[i][3] = (LikelihoodTable[i][1]+LikelihoodTable[i][2])/n;
        xx+=LikelihoodTable[i][1];
        yy+=LikelihoodTable[i][2];
    }
    temp++;
    LikelihoodTable[temp][1] = xx/n;
    LikelihoodTable[temp][2] = yy/n;


    while(q--){
        string s1,s2;
        for (int i=0;i<s1.size();i++){
            if (s1[i]<95)s1[i]+=32;
        }
        for (int i=0;i<s2.size();i++){
            if (s2[i]<95)s2[i]+=32;
        }

        int dammy = 1 , st = 1;
        for (int i=1;i<temp;i++){
            if (s2==mp[i]){
                dammy = i;
                break;
            }
        }
        if(s1=="yes")st = 1 ;
        else st = 2;

        double temprary = LikelihoodTable[dammy][st] / LikelihoodTable[temp][st];
        double ans = temprary*(LikelihoodTable[temp][st]) / LikelihoodTable[dammy][3];

        cout << "THE PROBABILITY IS :  " << ans << endl;
    }

    return 0;
}
