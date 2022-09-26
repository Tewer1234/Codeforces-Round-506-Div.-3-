#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <typeinfo>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<ll,ll> pp;
pp ary[1000000];
pp aryall[1000000];
ll ans;
void solve(ll a, ll b,ll len){
  ll lp,rp,l2p,r2p,amount=-1,per,pos=0,cnt=0,total=a+b;
  for (ll i=1;i*i<=a;i++){
    if (a%i==0){
      cnt++;
      ary[cnt].first=i;
      ary[cnt].second=a/i;
    }
  }
  
  
  // for (int i=1;i<=cnt;i++) cout<<ary[i].first<<" "<<ary[i].second<<"\n";
  for (int i=1;i<=len;i++){
    lp=aryall[i].first,rp=aryall[i].second;
    
    while (pos+1<=cnt and (ary[pos+1].first<=lp)){
      pos++;
    }
    l2p=ary[pos].first,r2p=ary[pos].second;
    // amount=(lp-l2p)*rp+(rp-r2p)*lp;
    // cout<<a<<" "<<b<<": "<<l2p<<" "<<r2p<<" --> "<<lp<<" "<<rp<<"\n";
    if (l2p!=0 and (total/lp)>=(a/l2p)){
      per=2*(lp+rp);
      ans=min(ans,per);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a,b,temp,len=0,total;
  cin>>a>>b;
  
  total=a+b;
  ans=LLONG_MAX;
  for (ll i=1;i*i<=total;i++){
    if (total%i==0){
      len++;
      aryall[len].first=i;
      aryall[len].second=total/i;
    }
  }
  
  
  solve(a,b,len);
  solve(b,a,len);
  cout<<ans;
  return 0; 
}
