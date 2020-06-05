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
    #define mod             100000000
    #define inf8            100000008

    using namespace std;

    ll dp[102][102][12][3] , n1 , n2 , k1 , k2;

    ll recursion(ll _n1 , ll _n2  , ll k , ll type)
    {
        //cout << "  ok " << endl;
        if (_n1 > n1 || _n2 > n2)return 0;
        if ((type == 0 && k>k1) || (type==1 && k>k2))return 0;
        if (_n1 == n1 && _n2 == n2)return 1;
        if (dp[_n1][_n2][k][type] != -1)return dp[_n1][_n2][k][type];

        ll temp;
        if (!type)temp = recursion(_n1+1 , _n2 , k+1 , type) + recursion(_n1,_n2+1,1,1-type);
        else temp = recursion(_n1 , _n2+1 , k+1 , type) + recursion(_n1+1 , _n2 , 1, 1-type);
        temp%=mod;

        return dp[_n1][_n2][k][type] = temp;
    }

    int main()
    {
        cin >> n1 >> n2 >> k1 >> k2;
        for (int i=0;i<102;i++){
            for(int j=0;j<102;j++){
                for (int k=0;k<12;k++){
                    for (int l=0;l<3;l++)dp[i][j][k][l] =  -1;
                }
            }
        }
        cout << (recursion(1,0,1,0) + recursion(0,1,1,1))%mod << endl;

        return 0;
    }
