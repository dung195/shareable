#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pq priority_queue
#define pii pair<int,int>
#define inf 10000000
int n,k;
int thang[100005];
int F[100005];
ll find(int n){
   if(thang[n]==1) return 0;
   if(F[n]!=0) return F[n];
   if(n==1) return 1;
   else{
      F[n]=find(n-1)+find(n-2);
      return F[n];
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   // freopen("main.inp","r",stdin);
   // freopen("main.out","w",stdout);
   cin>>n>>k;
   for(int i=0;i<k;i++){
      int a;
      cin>>a;
      thang[a]=1;
   }
   cout<<find(n)%14062008<<endl;
   return 0;

}
