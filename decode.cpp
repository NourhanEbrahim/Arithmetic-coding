#include <bits/stdc++.h>

using namespace std;
set<char> :: iterator it;
string s1,out,s;
long double l = 0.0 , u = 1.0 , l1 ;
long double x = 1 , tag ;
int cnt;
map<char,int>ma;
long double btd (string d)      //convert from binary to decimal
{

    long double x1=0;
    for(int i=0; i< d.size(); i++)
    {
        if(d[i]=='1')
        {
            x1+=(long double)pow(2,-1*(long double)(i+1));
        }
    }
    return x1;

}
int main()
{
    freopen("../encode/output.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    cin>>s;                                 //set
    long double cdf[s.size()+1];
    cdf[0]=0;
    for(int i = 1 ; i <= s.size() ; i++)   //cdf
    {
        cin>>cdf[i];
        x = min(x , cdf[i]-cdf[i-1]);      //Minimum interval
    }
    cin>>s1;                               //encode
    cin>>cnt;                             //Size of message
    int bit = s1.size(),a=0;
    //log2(1/x),a=0;
    //if(pow(2,bit)!=(1/x))bit++;           //ceil
   // tag = btd(s1.substr(a,bit));          //read first bit from encode
    tag = btd(s1);
    a=1;
    for(int i = 0 ; i < cnt ; i++)
    {
        int y = 1;
        long double w1,w2;
        while(1)                        //compute the new interval where tag in between
        {
            w1=l+(u-l)*cdf[y-1];
            w2=l+(u-l)*cdf[y];
            if(tag>=w1&&tag<=w2)
            {
                out+=s[y-1];//cout<<y<<" "<<i<<endl;
                l=w1;
                u=w2;
                break;
            }
            y++;
        }
        while((l<(long double)0.5&&u<=(long double)0.5)||(l>=(long double)0.5&&u>(long double)0.5))
        {   s1+=s1[a-1];
            tag = btd(s1.substr(a,bit));
            a++;                                 //Shift the encode bit by bit
            if(l<(long double)0.5&&u<=(long double)0.5)       //rescale with E1
            {
                l=(long double)2.0*(l);
                u=(long double)2.0*(u);
            }
            else if(l>=(long double)0.5&&u>(long double)0.5)    //rescale with E2
            {
                l=(long double)2.0*(l-(long double)0.5);
                u=(long double)2.0*(u-(long double)0.5);
            }
        }
    }
    cout<<out<<endl;
    return 0;
}
