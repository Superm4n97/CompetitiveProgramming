#include<bits/stdc++.h>
#define ll long long int
#define pb      push_back
#define show(x) cout << #x << " : " << x << endl
#define maxn    500005
#define modulous    1000000007

using namespace std;

string s,t;
ll m , d , n;
///     pos num mod sm val
ll DPB[2005][2005][3][3];
ll DPA[2005][2005][3][3];

string A , B;

ll functionDPB(ll position, ll mod , ll small, ll valid)
{
    if (DPB[position][mod][small][valid] != -1){
         //cout << " 1. ";show(DPB[position][number][mod][small][valid]);
        return DPB[position][mod][small][valid];
    }
    //if (small==0 && number>B[position]-'0')return 0;
    if (position==n-1){
        if (valid==1 && mod==0){
            DPB[position][mod][small][valid] = 1;
//            cout << " 2. ";show(DPB[position][number][mod][small][valid]);
//            show(position);
//            show(number);
//            show(mod);
//            show(small);
//            show(valid);
            return DPB[position][mod][small][valid];
        }
        return DPB[position][mod][small][valid] =  0;
    }

    ll temp = 0;

    for (int i=0;i<=9;i++){
        ll md = (mod*10+i)%m , sm = small , val = valid;
        if (i<B[position+1]-'0')sm = 1;

        if ((position+1)%2==0 && i == d)continue;
        if (sm==0 && i>B[position+1]-'0')continue;

        if ((position+1)%2 && i==d)val = 1;

        temp += functionDPB(position+1,md,sm,val);
        temp%=modulous;
    }
    DPB[position][mod][small][valid] = temp;
//    cout << " 3. ";show(DPB[position][number][mod][small][valid]);
//    show(position);
//    show(number);
//    show(mod);
//    show(small);
//    show(valid);
    return DPB[position][mod][small][valid];
}

ll functionDPA(ll position, ll mod , ll small, ll valid)
{
    if (DPA[position][mod][small][valid] != -1)return DPA[position][mod][small][valid];
    //if (small==0 && number>A[position]-'0')return 0;
    if (position==n-1){
        if (valid==1 && mod==0)return DPA[position][mod][small][valid] = 1;
        return DPA[position][mod][small][valid] =  0;
    }

    ll temp = 0;

    for (int i=0;i<=9;i++){
        ll md = (mod*10+i)%m , sm = small , val = valid;
        if (i<A[position+1]-'0')sm = 1;

        if ((position+1)%2==0 && i == d)continue;
        if (sm==0 && i>A[position+1]-'0')continue;

        if ((position+1)%2 && i==d)val = 1;

        temp += functionDPA(position+1,md,sm,val);
        temp%=modulous;
    }

    return DPA[position][mod][small][valid] = temp;
}

int main()
{
    scanf("%I64d %I64d",&m,&d);
    cin >> A >> B;
    n = B.size();

    memset(DPB,-1,sizeof(DPB));
    memset(DPA,-1,sizeof(DPA));

    ll sumB = 0 , sumA = 0;

    for (int i=0;i<=B[0]-'0';i++){
        ll small = 1;
        if (i==B[0]-'0')small = 0;

        if (i==d)continue;

        sumB += functionDPB(0,i%m,small,0);
        sumB%=modulous;
    }

    for (int i=0;i<=A[0]-'0';i++){
        ll small = 1;
        if (i==A[0]-'0')small = 0;

        if (i==d)continue;

        sumA += functionDPA(0,i%m,small,0);
        sumA%=modulous;
    }

    show(sumA) , show(sumB);

    ll carry = 0;
    int ansA = 0 , num = 0;
    for (int i=0;i<n;i++){
        if (A[i]-'0' == d)num++;
        if (A[i]-'0'==d && i%2==0)ansA = 1;
    }
    if (ansA==0 && num)sumA--;
    sumB-=sumA;
    if (sumB<0)sumB += modulous;

    printf("%I64d\n",sumB);

    return 0;
}
