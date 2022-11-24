#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define re register
#define il inline
#define pb push_back
#define rep(i,l,r) for(int i(l);i<=r;++i)
#define per(i,l,r) for(int i(r);i>=l;--i)
#define repe(u) for(int i=head[u];i;i=e[i].nxt)
#define ls(k) k<<1
#define rs(k) k<<1|1
#define np pair<int,int>
#define mp make_pair
#define nb(k) bitset<k>
#define rev reverse
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
il int read(){
	int ans=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')flag=-1;ch=getchar();}
	while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return ans*flag;
}
il string reads(){
	string ans="";char ch=getchar();
	while(!isalpha(ch))ch=getchar();
	while(isalpha(ch))ans+=ch,ch=getchar();
	return ans;
}
il char readc(){
	char ch=getchar();
	while(!isalpha(ch))ch=getchar();
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
int T;
int DataS=0,FilE=0;

#define int long long

const int N=2e2+7,M=5e3+7;

struct edge{int to,nxt;ll dis;}e[M<<1];
int head[N],cur[N],dis[N],cnt=0,siz=0,n,m,s=0,t=siz+1;
void add_edge(int u,int v,int w){
	e[cnt].to=v;e[cnt].dis=w,e[cnt].nxt=head[u],head[u]=cnt++;
	e[cnt].to=u;e[cnt].dis=0,e[cnt].nxt=head[v],head[v]=cnt++;
}
bool bfs(){
	memset(dis,-1,sizeof(dis));dis[s]=0;
	queue<int>q;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u],v;~i;i=e[i].nxt)
			if(!(~dis[v=e[i].to])&&e[i].dis)dis[v]=dis[u]+1,q.push(v);
	}return dis[t]!=-1;
}
ll dfs(int u,ll flow){
	if(u==t)return flow;
	ll delta=flow;
	for(int i=cur[u],v;~i;i=e[i].nxt){
		cur[u]=e[i].nxt;v=e[i].to;
		if(dis[v]==dis[u]+1&&e[i].dis>0){
			ll f=dfs(v,min(e[i].dis,delta));
			if(!f){dis[v]=-1;continue;}
			e[i].dis-=f,e[i^1].dis+=f,delta-=f;
			if(!delta)break;
		}
	}return flow-delta;
}
int dinic(){
	ll ans=0;
	while(bfs()){
		memcpy(cur,head,sizeof(head));
		ans+=dfs(s,1e18+7);
	}return ans;
}

signed main(){
	memset(head,-1,sizeof(head));
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}cout<<dinic()<<endl;
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
  Time complexity? Memory usage? Precision error?

  4. Delete the DEBUGGING? Add FILE I/O? Use The TRUE MODULE?
*/


