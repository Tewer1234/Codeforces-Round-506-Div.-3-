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
  int n,k;
  string s,temp,sub,add="";
  cin>>n>>k>>s;
  
  for (int i=1;i<s.size();i++){
    sub=s.substr(i);
    temp=s.substr(0,s.size()-i);
    // cout<<sub<<" "<<temp<<"\n";
    if (sub==temp){
      for (int j=sub.size();j<s.size();j++){
        add+=s[j];
      }
      break;
    }
  }
  if (!add.size()) add=s;
  cout<<s;
  for (int i=1;i<=k-1;i++){
    cout<<add;
  }
  return 0; 
}
