#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define bs binary_search
typedef vector<vector<int>> vvi;
const ll sized = 39005;
const ll N = 1e6 +1;
const ll inf = 1e17;
const ll MOD = 2111992;
const ll LOG = 20;
int bang[sized];
int dem[N];
int n,q;
vector<pair<pii,int> >tv;
int fre[N];
bool cmp(pair<pii,int> a,pair<pii,int> b){
    int divide=pow(n,1/2);
    if(a.first.first/divide!=b.first.first/divide) return (a.first.first/divide <b.first.first/divide);
    else return a.first.second>b.first.second;
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>bang[i];
    }
    cin>>q;
    int chia=pow(n,1/2);
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        tv.push_back({{a,b},i+1});
    }
    sort(tv.begin(),tv.end(),cmp);
    int l=tv[0].first.first;
    int r=tv[0].first.second;
    int res =0;
    for(int i=l;i<=r;i++){
        fre[bang[i]]++;
        if(fre[bang[i]]==1) res++;
    }
    dem[tv[0].second]=res;
    // cout<<s.size()<<endl;
    for(int i=1;i<q;i++){
        int start=tv[i].first.first;
        int finish=tv[i].first.second;
        int tvid=tv[i].second;
        if(l>start){
            for (int j = l-1; j >= start; j--)
            {
                fre[bang[j]]++;
                if(fre[bang[i]]==1) res++;

            }
        }
        else if(l<start){

            for(int j=l;j<=start-1;j++){
                fre[bang[j]]--;
                if(fre[bang[j]]==0) res--;
            }
        }
        l=start;
        if(r>finish){

            for (int j=r;j>=finish+1;j--)
            {
               fre[bang[j]]--;
                if(fre[bang[j]]==0) res--;
            }
        }
        else if(r<finish){

            for(int j=r+1;j<=finish;j++){
                 fre[bang[j]]++;
                if(fre[bang[i]]==1) res++;
            }
        }
        r=finish;
        dem[tvid]=res;

        // cout<<s.size()<<endl;
    }
    for(int i =1; i<=q; i++ )
    cout<<dem[i]<<endl;
    return 0;
}
