#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define inf 2e10+11
#define sized 10005
int X[sized];
int pa[sized];
int pb[sized];
bool check(string s){
    int dem=0;
    for(int i=0;i<s.size();i++){
        if(dem<0) return false;
        else{
            if(s[i]==40) dem++;
            else dem--;
        }
    }
    if(dem==0) return true;

    return false;
}
int ans=0;
void backtrack(int k){
    for(int i=0;i<1;i++){
        
    }
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>pa[i];
    }
    for(int i=0;i<n;i++){
        cin>>pb[i];
    }
    backtrack(1);
    cout<<ans<<endl;
    return 0;
}
