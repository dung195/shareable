#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define inf 10000000
int a[50005];
int treemax[50005*4];
int treemin[55005*4];
void Buildtree(int id,int l,int r){
    if(l==r){
       treemax[id]=a[l];
       treemin[id]=a[l];
       return;
    }
    int mid=(l+r)/2;
    Buildtree(id*2,l,mid);
    Buildtree(id*2+1,mid+1,r);
    treemax[id]=max(treemax[id*2],treemax[id*2+1]);
    treemin[id]=min(treemin[id*2],treemin[id*2+1]);
}
int  maximum(int id,int l,int r,int u,int v){
    if(r<u || l>v) return -INFINITY;

    if(u<=l && v>=r){
        return treemax[id];
    }
    int mid=(l+r)/2;
    return max(maximum(id*2,l,mid,u,v),maximum(id*2+1,mid+1,r,u,v));
}
int minimum(int id,int l,int r,int u,int v){
    if(r<u || l>v) return INFINITY;

    if(u<=l && v>=r){
        return treemin[id];
    }
    int mid=(l+r)/2;
    return min(minimum(id*2,l,mid,u,v),minimum(id*2+1,mid+1,r,u,v));
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("main.inp","r",stdin);
   freopen("main.out","w",stdout);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      int b;
      cin>>b;
      a[i]=b;
   }
   Buildtree(1,1,n);
   for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      cout<<maximum(1,1,n,a,b)-minimum(1,1,n,a,b)<<endl;
   }
   return 0;

}
