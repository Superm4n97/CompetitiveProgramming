#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x <<endl;
#define maxn 1000006

using namespace std;

vector < ll > prime , A , B;
map < ll , ll > mp1 , mp2;
bool MARK[maxn] , ans;
ll a,b , lcm , lcm2 , solution;

void Clean()
{
    solution = 1;
    ans = true;
    mp1.clear();
    mp2.clear();
    A.clear();
    B.clear();
}

void Build()
{
    for (int i = 2 ; i*i<maxn ; i++){
        if (!MARK[i]){
            for (int j= i+i ; j<maxn ; j+=i)MARK[j] = true;
        }
    }
    for (int i=2; i<maxn ; i++){
        if (!MARK[i])prime.push_back(i);
    }
}

void deform1(ll temp)
{
    for (int i=0 ; i<prime.size() && prime[i]*prime[i]<=temp ; i++){
        if (temp%prime[i]==0){
            A.push_back(prime[i]);

            while(temp%prime[i]==0){
                mp1[prime[i]]++;
                temp/=prime[i];
            }
        }
    }

    if (temp>1){
        mp1[temp]++;
        if (mp1[temp]==1)A.push_back(temp);
    }


    return;
}

void deform2(ll temp)
{
    for (int i = 0 ; i<prime.size() && prime[i]*prime[i]<=temp ; i++){
        if (temp%prime[i]==0){
            B.push_back(prime[i]);

            while(temp%prime[i]==0){
                mp2[prime[i]]++;
                temp/=prime[i];
            }
        }
    }

    if (temp>1){
        mp2[temp]++;
        if (mp2[temp]==1){
            B.push_back(temp);
        }
    }

    for (int i=0;i<B.size() ; i++){
        if (mp2[B[i]]>mp1[B[i]])ans = false;
    }

    return;
}

int main()
{
    Build();
    ll tc;
    scanf("%lld",&tc);

    for (int _t=1 ; _t<=tc ; _t++){
        Clean();

        scanf("%lld %lld %lld",&a,&b,&lcm);

        lcm2 = a*b / __gcd(a,b);

        deform1(lcm);
        deform2(lcm2);

        for (int i = 0 ; i<A.size() ; i++){
            if (mp1[A[i]] < mp2[A[i]])ans = false;
            else if (mp1[A[i]]>mp2[A[i]]){
                for (int j = 0 ; j<mp1[A[i]] ; j++)solution*=A[i];
            }
        }

        if (ans)printf("Case %d: %lld\n",_t,solution);
        else printf("Case %d: impossible\n",_t);
    }


    return 0;
}
