#include<bits/stdc++.h>
using namespace std;
/*define about others*/
#define ls(k) k<<1
#define rs(k) k<<1|1
#define lson(k) l,mid,ls(k)
#define rson(k) mid+1,r,rs(k)
#define sizea(x,d) x+1,x+d+1
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&-x)
/*define about variable*/
#define re register
#define il inline
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
/*define about pair*/
#define np pair<int,int>
#define tup pair<int,pair<int,int> >
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) make_pair(a,make_pair(b,c))
#define fi first
#define se second
#define _1 first
#define _2 second.first
#define _3 second.second
/*define about loop*/
#define rep(i,l,r) for(int i(l);i<=r;++i)
#define per(i,r,l) for(int i(r);i>=l;--i)
#define repe(u) for(int i=head[u];i;i=e[i].nxt)
#define repv(i,s) for(int i:s)
/*define about STL*/
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
#define ump unordered_map
#define pq priority_queue
#define iter iterator
/*define about function*/
#define clz __builtin_clz
#define ctz __builtin_ctz
#define ppc __builtin_popcount
#define clzl __builtin_clzll
#define ctzl __builtin_ctzll
#define ppcl __builtin_popcountll
#define EXODUS
//#define online_judge
#ifdef online_judge
#define debug(x) 1428
#define Debug(...) 2857
#else
#define debug(x) cerr<<"In Line "<<__LINE__<<' '<<#x<<" = "<<(x)<<'\n'
#define Debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace IO{
il int read(){
	int ans=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')flag=-1;ch=getchar();}
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*flag;
}
il string reads(){
	string ans="";char ch=getchar();
	while(ch==' '||ch=='\n')ch=getchar();
	while(ch!=' '&&ch!='\n')ans+=ch,ch=getchar();
	return ans;
}
il char readc(){
	char ch=getchar();
	while(ch==' '||ch=='\n')ch=getchar();
	return ch;
}
il int sqr(int x){return x*x;}
il void reada(int *a,int len){for(int i=1;i<=len;i++)a[i]=read();}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
}
using IO::read;
bool mem1=0;
int Datas=0,T=1;

const int N=17;
int n,a[N],m[N],c[N],d[N];ll M=1,ans;
int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return a;}
	int d=exgcd(b,a%b,y,x);y-=a/b*x;return d;
}
int getinv(int x,int p){
	int y;exgcd(x,p,x,y);
	return (x%p+p)%p;
}
ll CRT(){
	for(int i=1;i<=n;i++)M=M*m[i];
	for(int i=1;i<=n;i++){
		c[i]=M/m[i];
		ans+=a[i]*(M/m[i])%M*getinv(M/m[i]%m[i],m[i])%M;
	}return ans;
}

int main(){
	n=read();
	for(int i=1;i<=n;i++)m[i]=read(),a[i]=read();
    printf("%lld",CRT()%M);
    return 0;
}
//LOJ loyal users:EXODUS
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?

  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?

  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?

  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error? Use The TRUE MODULE?

  4. Do not forget to CHECK YOUR CODE before submitting!
  Delete the DEBUGGING? Add FILE I/O?
*/



