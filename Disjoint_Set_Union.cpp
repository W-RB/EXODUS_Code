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
const int N=1e4+7;
int fa[N],siz[N],n,m;
void init(int x){if(fa[x]==0)fa[x]=x;}
int find(int x){init(x);while(x!=fa[x])x=fa[x]=fa[fa[x]];return x;}
bool check(int x,int y){return find(x)==find(y);}
void merge(int x,int y){x=find(x),y=find(y);(siz[x]<siz[y])?(fa[x]=y,siz[x]+=siz[y]):(fa[y]=x,siz[x]+=siz[y]);}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)init(i),siz[i]=1;
	for(int i=1;i<=m;i++){
		int op=read(),x=read(),y=read();
		if(op==1)merge(x,y);
		else if(check(x,y))puts("Y");
		else puts("N");
	}
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


