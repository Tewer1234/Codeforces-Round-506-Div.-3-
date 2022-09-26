#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#define ll long long int
#define pb push_back
using namespace std;
typedef pair <int,int> pp;
ll ary[1000000];
int len[1000000];
map <ll,int> mp[1000];
//mp[length of integer][<rem,cnt>]
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k,rem;
  unsigned ll temp;
  cin>>n>>k;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
    temp=ary[i];
    while (temp){
      temp/=10;
      len[i]++;
    }
    rem=ary[i]%k;
    mp[len[i]][rem]++;
  }
  
  // for (int i=1;i<=10;i++){
  //   cout<<i<<": \n";
  //   for (auto it:mp[i]){
  //     cout<<it.first<<" "<<it.second<<"\n";
  //   }
  //   cout<<"\n";
  // }
  
  ll ans=0;
  for (int i=1;i<=n;i++){
    ll ten=1;
    for (int j=1;j<=10;j++){
      ten*=10;
      temp=((unsigned ll) ary[i]*ten)%k;
      auto it=mp[j].find((k-temp)%k);
      // if (ary[i]==11) cout<<temp<<" "<<k-temp<<"\n";
      if (it!=mp[j].end()){
        rem=mp[j][(k-temp)%k];
        // cout<<ary[i]<<" "<<ary[i]*ten<<" "<<temp<<" "<<rem<<"\n";
        ans+=rem;
      }
    }
  }
  
  for (int i=1;i<=n;i++){
    temp=ary[i];
    for (int j=1;j<=len[i];j++) temp*=10;
    if ((temp+ary[i])%k==0){
      ans--;
      // cout<<ary[i]<<" "; 
    }
  }
  
  cout<<ans;
  return 0;
}
