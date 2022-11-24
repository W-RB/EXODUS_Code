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





const int N=1e4+7,M=1e5+7;
struct edge{int fr,to,nxt;}e[M<<1];
int n,m,head[N],cnt,dfn[N],low[N],sta[N],top,typ[N],tmp,dfsc;bool ins[N];
void add_edge(int u,int v){e[++cnt].fr=u,e[cnt].to=v,e[cnt].nxt=head[u],head[u]=cnt;}
void tarjan(int u){
	dfn[u]=low[u]=++dfsc;ins[u]=1;sta[++top]=u;
	for(int i=head[u],v;i;i=e[i].nxt){
		if(!dfn[v=e[i].to])tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}if(dfn[u]==low[u]){tmp++;do{ins[sta[top]]=0,typ[sta[top--]]=tmp;}while(u!=sta[top+1]);}
	return;
}
void get_scc(){for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);}
int main(){
	n=read(),m=read();
	for(int i=1,u,v;i<=n;i++)u=read(),v=read(),add_edge(u,v);
	get_scc();return 0;
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


