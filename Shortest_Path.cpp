#include<bits/stdc++.h>
using namespace std;
/*define about others*/
#define ls(k) k<<1
#define rs(k) k<<1|1
#define all(x) x.begin(), x.end()
/*define about variable*/
#define re register
#define il inline
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
/*define about pair*/
#define np pair<int,int>
#define tup paor<int,pair<int,int> >
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) make_pair(a,make_pair(b,c))
#define fi first
#define se second
#define _1 first
#define _2 second.first
#define _3 second.second
/*define about loop*/
#define rep(i,l,r) for(int i(l);i<=r;++i)
#define per(i,l,r) for(int i(r);i>=l;--i)
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
//#define EXODUS
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
	while(ch==' '&&ch=='\n')ch=getchar();
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

const int N=2e5+7;
struct edge{int to,dis,nxt;}e[N<<1];
int n,m,s,head[N],ans[N],vis[N],cnt;priority_queue<np>q; 


bool mem2=0;
void add_edge(int u,int v,int w){e[++cnt]={v,w,head[u]};head[u]=cnt;}
void dijkstra(int s){
	q.push(mp(0,s));
	memset(ans,0x3f,sizeof(ans));ans[s]=0;
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(ans[v]>ans[u]+e[i].dis){
				ans[v]=ans[u]+e[i].dis;
				if(!vis[v])q.push(mp(-ans[v],v)); 
			}
		}
	}
}
void Main(){
	n=read(),m=read();s=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}dijkstra(1);
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return;
}

int main(){
#ifdef EXODUS
	printf("%.5lfMB\n",abs(&mem2-&mem1)/1024.0/1024.0);
	freopen("Data.in","r",stdin);
	freopen("Code.out","w",stdout);
#endif
#ifdef online_judge
	freopen("input.in","r",stdin);
	freopen("user_out.ans","w",stdout);
#endif
	if(Datas)T=read();
	while(T--)Main();
#ifdef EXODUS
	cerr<<clock()<<"ms"<<endl;
#endif
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



