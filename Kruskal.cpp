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

const int N=5e3+7,M=2e5+7;
struct edge{int fr,to,dis;}e[M<<1];
int head[N],fa[N],ans,n,m,cnt;
void add_edge(int u,int v,int w){e[++cnt]=(edge){u,v,w};head[u]=cnt;}
bool cmp(edge x,edge y){return x.dis<y.dis;}
void init(){for(int i=1;i<=n;i++)fa[i]=i;}
int find(int x){while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}
int kruskal(){
	init();sort(e+1,e+cnt+1,cmp);int ans=0,tot=0;
	for(int i=1;i<=cnt;i++){
		int u=e[i].fr,v=e[i].to;
		if(find(u)==find(v))continue;
		fa[find(u)]=fa[find(v)];tot++;ans+=e[i].dis;
		if(tot==n-1)break;
	}
	if(tot!=n-1)return -2e9-7;
	return ans;
}

int main(){
	n=read(),m=read();
	for(int i=1,u,v,w;i<=m;i++,u=read(),v=read(),w=read(),add_edge(u,v,w));
	int t=kruskal();printf((t==-2e9-7)?"orz":"%d\n",t);
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


