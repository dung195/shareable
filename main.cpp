#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
// #define int ll
const ll sized = 1e6;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
int par[sized];
struct ac
{
    int x,y,id;
};
struct Edge
{
    int u,v,w;
};
vector<ac>x;
vector<ac>y;
map<pii,bool>check;
vector<Edge>ed;
bool cmp_e(Edge a,Edge b){
    return a.w<b.w;
}
bool cmp(ac x,ac y){
    return x.x<y.x;
}
bool cmp2(ac x,ac y){
    return x.y<y.y;
}
int getroot(int u){
    if(par[u]<0) return u;
    par[u]=getroot(par[u]);
    return par[u];
}
void connect(int u,int v){
    u=getroot(u);
    v=getroot(v);
    if(par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    for(int i=0;i<sized;i++) par[i]=-1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        x.push_back({a,b,i});
        y.push_back({a,b,i});
    }
    sort(x.begin(),x.end(),cmp);
    sort(y.begin(),y.end(),cmp2);
    for(int i=0;i<x.size()-1;i++){
        int x1=x[i].x;
        int id1=x[i].id;
        int x2=x[i+1].x;
        int id2=x[i+1].id;
        // cout<<id1<<" "<<id2<<" "<<abs(x1-x2)<<endl;
        ed.push_back({id1,id2,abs(x1-x2)});
    }
    // cout<<endl;
    for(int i=0;i<y.size()-1;i++){
        int y1=y[i].y;
        int id1=y[i].id;
        int y2=y[i+1].y;
        int id2=y[i+1].id;
        // cout<<id1<<" "<<id2<<" "<<abs(y1-y2)<<endl;
        ed.push_back({id1,id2,abs(y1-y2)});
    }
    // cout<<endl;
    // for(int i=0;i<y.size();i++){
    //     cout<<y[i].x<<" "<<y[i].y<<" "<<y[i].id<<endl;
    // }
    // cout<<endl;
    sort(ed.begin(),ed.end(),cmp_e);
    // for(int i=0;i<ed.size();i++){
    //     cout<<ed[i].u<<" "<<ed[i].v<<" "<<ed[i].w<<endl;
    // }
    // cout<<endl;
    int j=0;
    int ans=0;
    for(int i=0;i<ed.size();i++){
        int u=ed[i].u;
        int v=ed[i].v;
        int w=ed[i].w;
        if(check[{u,v}]==false){
            connect(u,v);
            ans+=w;
            check[{u,v}]=true; 
            check[{v,u}]=true;
            j++;
        }
        if(j==n-1) break;
    }
    cout<<ans<<endl;
    return 0;
}
