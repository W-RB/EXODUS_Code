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
	while(ch==' '&&ch=='\n')ch=getchar();
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
int T;
int DataS=0,FilE=0;


const int N=5e3+7,M=5e4+7;
int n,m,s=0,siz=0,t=siz+1,cnt=0,dis[N],flw[N],pre[N],lst[N],mxf,mnc,tot,head[N];bool inque[N];
struct edge{int to,nxt,dis,cst;}e[M<<1];queue<int>q;
void add_edge(int u,int v,int w,int c){
	e[tot].to=v,e[tot].dis=w,e[tot].cst=c,e[tot].nxt=head[u],head[u]=tot++;
	e[tot].to=u,e[tot].dis=0,e[tot].cst=-c,e[tot].nxt=head[v],head[v]=tot++;
}
bool spfa(int s,int t){
	memset(dis,0x7f,sizeof(dis));memset(flw,0x7f,sizeof(flw));
	inque[s]=1;dis[s]=0;pre[t]=-1;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();inque[u]=0;
		for(int i=head[u],v;~i;i=e[i].nxt)
			if(dis[v=e[i].to]>dis[u]+e[i].cst&&e[i].dis){
				dis[v]=dis[u]+e[i].cst,pre[v]=u,lst[v]=i,flw[v]=min(flw[u],e[i].dis);
				if(!inque[v])inque[v]=1,q.push(v);
			}
	}return pre[t]!=-1;
}
void MCMF(){
	while(spfa(s,t)){
		int u=t;mxf+=flw[t],mnc+=flw[t]*dis[t];
		while(u!=s)e[lst[u]].dis-=flw[t],e[lst[u]^1].dis+=flw[t],u=pre[u];
	}
}
int main(){
	memset(head,-1,sizeof(head));
	n=read(),m=read(),s=read(),t=read();
	for(int i=1,u,v,c,w;i<=m;i++)u=read(),v=read(),w=read(),c=read(),add_edge(u,v,w,c);
	MCMF();printf("%d %d\n",mxf,mnc);
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


