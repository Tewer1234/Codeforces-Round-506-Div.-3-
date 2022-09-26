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
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[1000000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,st=1,sum=1,ans=0;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  sort(ary+1,ary+n+1);
  for (int i=1;i<=n;i++){
    st=i;
    while (st+1<=n and ary[st]*2>=ary[st+1]){
      st++;
    }
    ans=max(ans,st-i+1);
    i=st;
  }
  
  cout<<ans;
  return 0; 
}
