#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define inf 1000
#define pii pair<ll,ll>
vector<pair<ll,ll>> graph[inf];
vector<ll>D;
ll trace[inf];
void Dijkstra(ll start,ll nodes){
    for(ll i=0;i<nodes+2;i++){
      D.push_back(inf);
    }
    D[start]=0;
    trace[start]=-1;
    pq<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    q.push({0,start});
    while (q.size()!=0)
    {
      ll u=q.top().second;
      q.pop();
      for(ll i=0;i<graph[u].size();i++){
        ll v=graph[u][i].second;
        ll w=graph[u][i].first;
        if(D[v]>D[u]+w){
          D[v]=D[u]+w;
          q.push({D[v],v});
          trace[v]=u;
        }
      }
    }
    
}
main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n,m,k;
  cin>>n>>m>>k;
  // freopen("main.inp","r",stdin);
  // freopen("main.out","w",stdout);
  for(ll i=0;i<m;i++){
     ll u,v,c;
     cin>>u>>v>>c;
     pii o={c,v};
     pii p={c,u};
     graph[u].push_back(o);
     graph[v].push_back(p);
  }
  for(ll i=0;i<k;i++){
    ll k0,u,v;
    cin>>k0>>u>>v;
    if(k0==0){
      Dijkstra(u,n);
      cout<<D[v]<<endl;
    }
    if(k0==1){
      ll cur=v;
      vector<ll>way;
      ll cnt=0;
      while(cur!=-1){
          cnt++;
          way.push_back(cur);
          cur=trace[cur];
      }
      cout<<cnt<<" ";
      for(ll i=cnt-1;i>=0;i--){
            cout<<way[i]<<" ";
      }
      cout<<endl;
    }
  }
}
