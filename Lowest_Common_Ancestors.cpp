#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define re register
#define il inline
#define pb push_back
#define POS(i,l,r) for(re int i(l);i<=r;i=-~i)
#define REV(i,r,l) for(re int i(r);i>=l;i--)
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
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	return;
}
bool DataS=0,FilE=0;
int T;
void init(){
	return;
}

const int N=5e5+7;
struct Edge{int to,nxt;}e[N<<1];
int fa[N][22],head[N],dep[N],cnt=0,n,m,rt;

void add_edge(int u,int v){e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;}
void dfs(int u,int f){
	fa[u][0]=f?f:u;dep[u]=dep[f]+1;for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)dfs(e[i].to,u);
}
int get_lca(int u,int v){
	if(dep[v]>dep[u])swap(u,v);
	for(int i=20;i>=0;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=20;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}

int main(){
	n=read(),m=read(),rt=read();int u,v;
	for(int i=1;i<n;i++)u=read(),v=read(),add_edge(u,v),add_edge(v,u);
	dfs(rt,0);while(m--)u=read(),v=read(),printf("%d\n",get_lca(u,v));
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
*/


