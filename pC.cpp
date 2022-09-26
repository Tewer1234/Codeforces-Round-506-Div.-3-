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
int ary[1000000];
int l[1000000],r[1000000];
int sul[1000000],sur[1000000];
pp nodes[1000000];
bool comp(pp a,pp b){
  if (a.first<b.first) return true;
  else if (a.first==b.first and a.second<b.second) return true;
  else return false;
}
int main(){
  int n;
  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>nodes[i].first>>nodes[i].second;
  }
  
  sort(nodes+1,nodes+n+1,comp);
  l[1]=nodes[1].first;
  r[1]=nodes[1].second;
  for (int i=2;i<=n;i++){
    l[i]=max(l[i-1],nodes[i].first);
    r[i]=min(r[i-1],nodes[i].second);
  }
  
  sul[n]=nodes[n].first;
  sur[n]=nodes[n].second;
  for (int i=n-1;i>=1;i--){
    sul[i]=max(sul[i+1],nodes[i].first);
    sur[i]=min(sur[i+1],nodes[i].second);
  }
  
  // for (int i=1;i<=n;i++){
  //   cout<<nodes[i].first<<" "<<nodes[i].second<<"\n";
  // }
  // cout<<"\n";
  // for (int i=1;i<=n;i++){
    // cout<<l[i]<<" "<<r[i]<<" "<<sul[i]<<" "<<sur[i]<<"\n";
  // }
  
  int ans=0;
  for (int i=2;i<n;i++){
    int templ=l[i-1],tempr=r[i-1],tsul=sul[i+1],tsur=sur[i+1];
    int dis=0,comx,comy;
    comx=max(templ,tsul);
    comy=min(tempr,tsur);
    dis=max(dis,comy-comx);
    // cout<<comx<<" "<<comy<<"\n";
    ans=max(ans,dis);
  }
  ans=max(ans,max(sur[2]-sul[2],r[n-1]-l[n-1]));
  cout<<ans;
  
  return 0;
}
