#include <bits/stdc++.h>
#define pb              push_back
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
#define pll             pair < ll , ll >
#define mk              make_pair
#define inf8            100000008

using namespace std;

ll nn,mm;
ll dir[100] , X[100] , Y[100];
vector < pll > edg;

ll x = 0;

int main()
{
    scll(nn,mm);
    for (int i=0;i<mm;i++){
        scll(X[i],Y[i]);
    }
    ll mx = 0;

    for (int i=1;i<=6;i++){
        for (int j=1;j<=6;j++){
            for (int k=1;k<=6;k++){
                for (int l=1;l<6;l++){
                    for (int m=1;m<=6;m++){
                        for (int n = 1;n<=6;n++){
                            for (int o=1;o<=6;o++){
                                dir[1] = i , dir[2] = j , dir[3] = k;
                                dir[4] = l , dir[5] = m , dir[6] = n;
                                dir[7] = o;

                                ll G[8][8];
                                memset(G,0,sizeof(G));


//                                if (x==0){
//                                    for (int q=0;q<8;q++){
//                                        for (int w=0;w<8;w++)cout << G[q][w] << " ";
//                                        cout << endl;
//                                    }
//                                }

                                ll temp = 0;
                                for (int ii = 0 ;ii<mm;ii++){
                                    ll a = X[ii], b = Y[ii];
                                    if (G[dir[a]][dir[b]]==0){
                                        G[dir[a]][dir[b]] = 1;
                                        G[dir[b]][dir[a]] = 1;
                                        temp++;
                                    }
                                }
                                //if (x==0)cout << "  t " << temp << endl;
                                mx = max(temp,mx);
                                x = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << mx << endl;



    return 0;
}
