#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define inf 10000000
#define size 100001
int timed[100005];
int t[100005];
int F[100005];
int find(int n){
    if(F[n]!=0) return F[n];
    if(n==1) return timed[1];
    if(n==0) return t[1];
    if(n<0) return inf;
    else{
       int a=find(n-1)+timed[n];
       int b=find(n-2)+t[n];
       F[n]=min(a,b);
       return F[n];
    }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   freopen("main.inp","r",stdin);
   freopen("main.out","w",stdout);
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      int a;
      cin>>a;
      timed[n-i+1]=a;
   }
   for(int i=1;i<n;i++){
      int r;
      cin>>r;
      t[n-i]=r;
   }
   cout<<find(n)<<endl;
   return 0;

}
