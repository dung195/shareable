#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<ll ,ll >
#define inf 10e9+7
#define maxn 1000000
vector<pair<int,int> >graph[100005];
int D[1000005];
int way[1000005];
void Dijkstra(int S){
    D[S]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,S});
    while (q.empty()!=true)
    { 
       int u=q.top().second;
       q.pop();
       for(int i=0;i<graph[u].size();i++){
             int v=graph[u][i].second;
             int w=graph[u][i].first;
             if(D[v]>D[u]+w){
                D[v]=D[u]+w;
                q.push({D[v],v});
                way[v]+=way[u];
                }
             }
    }
}
main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   // freopen("main.inp","r",stdin);
   // freopen("main.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n+3;i++) D[i]=inf;
   for(int i=0;i<m;i++){
      int k;
      cin>>k;
      int u,v,l;
      cin>>u>>v>>l;
      pii o={l,v};
      pii p={l,u};
      if(k==1){
         graph[u].push_back(o);
      }
      if(k==2){
         graph[u].push_back(o);
         graph[v].push_back(p);
      }
   }
   way[1]=1;
   Dijkstra(1);
   cout<<D[n]<<" "<<way[n]<<endl; 
}
