#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s,st,p,ano="";
    cin >> s;
    p=s;
    st=s;
    reverse(st.begin(),st.end());
    if(st==s)
    {
        cout << s << endl;
        return 0;
    }
    for(ll i=0;i<s.size()-1;i++)
    {
        ano+=s[i];
        reverse(ano.begin(),ano.end());
        p=s+ano;
        //cout << p << endl;
        st=p;
        reverse(st.begin(),st.end());
        if(p==st)
        {
            cout << p << endl;
            return 0;
        }
        reverse(ano.begin(),ano.end());
    }
    //cout << p << endl;
}
