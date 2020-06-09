#define show(x) cout << #x << " : " << x << endl
#define pb      push_back
#define ll      long long int
#define maxn    300005

#include<bits/stdc++.h>

using namespace std;

ll n;
string s;
ll leftA[maxn] , rightA[maxn] , leftB[maxn] , rightB[maxn];

int main()
{
    scanf("%I64d",&n);
    cin >> s;

    ll flick = 0;

    for (int i=0;i<n;i++){
        if (i>0 && s[i]!=s[i-1])flick++;
        if (s[i] == 'A')leftA[i+1] += leftA[i]+1;
        else leftB[i+1] += leftB[i]+1;
    }
    for (int i=n-1;i>=0;i--){
        if (s[i] == 'A')rightA[i+1] += rightA[i+2]+1;
        else rightB[i+1] += rightB[i+2]+1;
    }

//    for (int i=0;i<=n;i++)cout << leftA[i] << " ";cout << endl;
//    for (int i=0;i<=n;i++)cout << rightA[i] << " ";cout << endl;
//    for (int i=0;i<=n;i++)cout << leftB[i] << " ";cout << endl;
//    for (int i=0;i<=n;i++)cout << rightB[i] << " ";cout << endl;

    ll cnt = 0;

    for (int i=1; i<=n ; i++){
        if (s[i-1] == 'A'){
            cnt += leftB[i-1]+rightB[i+1];
        }
        else {
            cnt += leftA[i-1]+rightA[i+1];
        }
    }
    //show(cnt);
    cnt-=flick;

    printf("%I64d\n",(n*(n-1)/2) - cnt);


    return 0;
}

