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
typedef pair<int,int> pp;
int ary[1000000];
int used[1000000];
int dis[1000000];
int par[1000000];
vector <int> nodes[1000000];
void dfs1(int n){
  int nxt;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (!used[nxt]){
      used[nxt]=1;
      par[nxt]=n;
      dis[nxt]=dis[n]+1;
      dfs1(nxt);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,u,v;
  set <pp> st;
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>u>>v;
    nodes[u].pb(v);
    nodes[v].pb(u);
  }
  used[1]=1;
  dfs1(1);
  // for (int i=1;i<=n;i++) cout<<par[i]<<" ";
  // cout<<"\n";
  
  memset(used,0,sizeof(used));
  for (int i=1;i<=n;i++){
    if (dis[i]>2){
      st.insert(make_pair(-dis[i],i));
    }
  }
  int ans=0;
  while (!st.empty()){
    auto it=st.begin();
    int cur=(*it).second;
    if (!used[cur]){
      for (int i=0;i<nodes[par[cur]].size();i++){
        int nxt=nodes[par[cur]][i];
        used[nxt]=1;
      }
      used[par[cur]]=1;
      ans++;
    }
    st.erase(st.begin());
  }
  cout<<ans;
  return 0;
}
