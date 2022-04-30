#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf 1e9+11
#define sized 100005
#define MOD 20122007
vector<int>x,y;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
    // freopen("main.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b; 
        x.push_back(a);
        y.push_back(b);
    }
    sort(y.begin(),y.end());
    int ans=inf;
    for (int  i = 0; i < x.size(); i++)         
    {
        int f=x[i];
        int pos=int(lower_bound(y.begin(),y.end(),-f)-y.begin());
        ans=min(min(ans,abs(f+y[pos])),abs(f+y[pos-1]));
    }
    cout<<ans<<endl;
    return 0;
}
