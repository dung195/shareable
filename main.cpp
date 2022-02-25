#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define inf 1000000
#define pii pair<int,int>
vector<pair<int,int>> graph[inf];
int D[inf];
int trace[inf];
void Dijkstra(int start,int nodes){
    for(int i=0;i<nodes+2;i++){
      D[i]=inf;
    }
    D[start]=0;
    trace[start]=-1;
    pq<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    while (q.size()!=0)
    {
      int u=q.top().second;
      q.pop();
      for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i].second;
        int w=graph[u][i].first;
        if(D[v]>D[u]+w){
          D[v]=D[u]+w;
          q.push({D[v],v});
          trace[v]=u;
        }
      }
    }
    
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n,m,k;
  cin>>n>>m>>k;
  // freopen("main.inp","r",stdin);
  // freopen("main.out","w",stdout);
  for(int i=0;i<m;i++){
     int u,v,c;
     cin>>u>>v>>c;
     pii o={c,v};
     pii p={c,u};
     graph[u].push_back(o);
     graph[v].push_back(p);
  }
  for(int i=0;i<k;i++){
    int k0,u,v;
    cin>>k0>>u>>v;
    if(k0==0){
      Dijkstra(u,n);
      cout<<D[v]<<endl;
    }
    if(k0==1){
      int cur=v;
      int way[inf];
      int cnt=0;
      while(cur!=-1){
          ++cnt;
          way[cnt]=cur;
          cur=trace[cur];
      }
      cout<<cnt<<" ";
      for(int i=cnt;i>=1;i--){
            cout<<way[i]<<" ";
      }
      cout<<endl;
    }
  }
}
