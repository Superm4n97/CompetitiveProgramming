#include <bits/stdc++.h>
#define ll long long int
#define pb          push_back
#define srt(v)      sort(v.begin(),v.end())
#define rsrt        sort(v.rbegin(),v.rend())
#define vii         vector < int >
#define input(v,n)  for (int i=0;i<n;i++){int a;cin >>a;v.pb(a);}
#define pii         pair<int,int>
#define pll         pair<ll,ll>

using namespace std;

bool same(char a, char b)
{
    if (a>='a' && a<='z' && b>='a' && b<='z')return true;
    if (a>='A' && a<='Z' && b>='A' && b<='Z')return true;
    if (a>='0' && a<='9' && b>='0' && b<='9')return true;
    return false;
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        map < char , int > ss,cc,dd;
        set < char> st;
        char baki='*',baki2;
        int sm =0, cap =0, dig=0;
        for (int i=0;i<s.size();i++){
            if (s[i]>='a' && s[i]<='z')ss['a']++,st.insert('a');
            if (s[i]>='A' && s[i]<='Z')ss['A']++,st.insert('A');
            if (s[i]>='0' && s[i]<='9')ss['0']++,st.insert('0');
        }
        if (ss['a']==0)
        {
            baki='a';
            if (ss['A']==0)baki2='A';
            if (ss['0']==0)baki2='0';
        }
        else if(ss['A']==0)
        {
            baki='A';
            if (ss['a']==0)baki2='a';
            if (ss['0']==0)baki2='0';
        }
        else if (ss['0']==0)
        {
            baki='0';
            if (ss['A']==0)baki2='A';
            if (ss['a']==0)baki2='a';
        }
        if (baki=='*'){
            cout << s << endl;
            continue;
        }
        if (st.size()==2){
            char tut;
            if (s[0]>='a' && s[0]<='z')tut='a';
            if (s[0]>='A' && s[0]<='Z')tut='A';
            if (s[0]>='0' && s[0]<='9')tut='0';
            if (ss[tut]>1)s[0]=baki;
            else s[1]=baki;
        }
        if (st.size()==1){
            for (int i=0;i<s.size()-1;i++){
                if (same(s[i],s[i+1])){
                    s[i]=baki2;
                    s[i+1]=baki;
                }
            }
        }
        cout << s << endl;
    }

    return 0;
}
