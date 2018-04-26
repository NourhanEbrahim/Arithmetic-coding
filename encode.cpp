#include <bits/stdc++.h>

using namespace std;
string s1,out,s;
long double l = 0.0 , u = 1.0 , l1 ;
int x = 31;
map<char,int>ma;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   /* for(int i=0;i<243;i++)cout<<"b";
    return 0;*/
    cin>>s>>s1;                 //set , input
    long double cdf[s.size()+1],p[s.size()+1];
    cdf[0]=0;
    for(int i = 1 ; i <= s.size() ; i++)//cdf
    {
        cin>>p[i];          //input the probability
        cdf[i]=p[i]+cdf[i-1];
        ma[s[i-1]]=i;       //indexes of the symbol
    }

    for(int i = 0 ; i < s1.size() ; i++)
    {
        l1=l;
        l=l+(u-l)*cdf[ma[s1[i]]-1];
        u=l1+(u-l1)*cdf[ma[s1[i]]];

        while((l<(long double)0.5&&u<=(long double)0.5)||(l>=(long double)0.5&&u>(long double)0.5))
        {
            if(l<(long double)0.5&&u<=(long double)0.5)       //rescale with E1
            {
                out+='0';
                l=(long double)2.0*(l);
                u=(long double)2.0*(u);
            }
            else if(l>=(long double)0.5&&u>(long double)0.5)  //rescale with E2
            {
                out+='1';
                l=(long double)2.0*(l-(long double)0.5);
                u=(long double)2.0*(u-(long double)0.5);
            }
        }

    }
    out+='1';            //0.5
    while(x--)          //decoder length (32)
    {
        out+='0';
    }
    cout<<s<<endl;     //Set
    for(int i = 1 ; i <= s.size() ; i++)//cdf
    {
        cout<<cdf[i]<<" ";
    }
    cout<<endl;
    cout<<out<<endl;
    cout<<s1.size();     //size of input
    return 0;
}
