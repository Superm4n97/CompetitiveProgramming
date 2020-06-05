#include <bits/stdc++.h>
#define pb(a)           push_back(a)
#define ll              long long int
#define ull             unsigned long long
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

using namespace std;

string arr[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

bool leapYear(int n)
{
    if (n%100==0){
        if (n%400==0)return true;
        else return false;
    }
    if (n%4==0)return true;
    return false;
}

int numberOfLeapYear(int n)
{
    int tut = 0;
    tut+=n/4;
    tut-=(n/100);
    tut+=(n/400);
    return tut;
}

int main()
{
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++){
        string month1,month2;
        int d1,d2,y2,y1;
        cin >> month1;
        scanf(" %d, %d",&d1,&y1);

        cin >> month2;
        scanf(" %d, %d",&d2,&y2);

        if (leapYear(y1)){
            if (month1 == "January")y1--;
            else if (month1=="February"){
                if (d1<=29)y1--;
            }
        }

        if (leapYear(y2)){
            if (month2 == "January")y2--;
            else if (month2=="February"){
                if (d2<29)y2--;
            }
        }

        //cout << y1 << " " << y2 << endl;

        int temp = numberOfLeapYear(y2)-numberOfLeapYear(y1);
        cout << "Case "<< t<< ": " << temp << endl;
    }

    return 0;
}
