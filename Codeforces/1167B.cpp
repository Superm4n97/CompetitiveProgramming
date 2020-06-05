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

int A[10];
vector < int >  v = { 4, 8, 15, 16, 23,  42};
map < int , int > mp;

int main() {

    for (int i=0;i<6;i++)mp[v[i]]=1;
   // while (l--) {
        printf("? 1 2\n");
        fflush(stdout);

        string s;
        cin >> s;
        int a = atoi(s.c_str());

        printf("? 2 3\n");
        fflush(stdout);
        cin >> s;
        int b = atoi(s.c_str());
        A[2] = __gcd(a,b);
        A[1] = a/A[2];
        A[3] = b/A[2];

        for (int i=0;i<6;i++){
            if (a%v[i] == 0){
                int temp = a/v[i];
                if (mp[temp]){
                    A[1] = v[i];
                    A[2] = temp;
                    break;
                }
            }
        }
        for (int i=0;i<6;i++){
            if (b%v[i] == 0){
                int temp = b/v[i];
                if (mp[temp]){
                    /// temp , v[i]
                    if (A[1]==temp || A[2]==temp){
                        if (A[1]==temp)swap(A[1],A[2]);
                        A[3] = v[i];
                    }
                    else{
                        if (A[1]==v[i])swap(A[1],A[2]);
                        A[3] = temp;
                    }
                }
            }
        }



        /////////////////////////////////

        printf("? 4 5\n");
        fflush(stdout);
        cin >> s;
        a = atoi(s.c_str());

        printf("? 5 6\n");
        fflush(stdout);
        cin >> s;
        b = atoi(s.c_str());

        for (int i=0;i<6;i++){
            if (a%v[i] == 0){
                int temp = a/v[i];
                if (mp[temp]){
                    A[4] = v[i];
                    A[5] = temp;
                    break;
                }
            }
        }
        for (int i=0;i<6;i++){
            if (b%v[i] == 0){
                int temp = b/v[i];
                if (mp[temp]){
                    /// temp , v[i]
                    if (A[4]==temp || A[5]==temp){
                        if (A[4]==temp)swap(A[4],A[5]);
                        A[6] = v[i];
                    }
                    else{
                        if (A[4]==v[i])swap(A[4],A[5]);
                        A[6] = temp;
                    }
                }
            }
        }

        cout << "! " <<A[1] << " " << A[2] << " " << A[3] << " " << A[4] << " " << A[5] << " " << A[6] << endl;
    //}

    //printf("! %d\n", l);
   fflush(stdout);
}

