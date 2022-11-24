#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
#define re register
#define il inline
#define pb push_back
#define POS(i,l,r) for(re int i(l);i<=r;i=-~i)
#define REV(i,r,l) for(re int i(r);i>=l;i--)
#define ls(k) t[k].lson
#define rs(k) t[k].rson
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
const int N=1e6+7;
int n,m,tot,a[N],rt[N];
struct Tree{int lson,rson,val;}t[N<<7];

int build(int l,int r,int k){
	k=++tot;if(l==r){t[k].val=a[l];return k;}
	int mid=l+r>>1;ls(k)=build(l,mid,ls(k)),rs(k)=build(mid+1,r,rs(k));return k;
}
int update(int l,int r,int k,int pos,int v,int lst){
	k=++tot;if(l==r){t[k].val=v;return k;}
	int mid=l+r>>1;t[k]=t[lst];
	if(pos<=mid)ls(k)=update(l,mid,ls(k),pos,v,ls(lst));
	else rs(k)=update(mid+1,r,rs(k),pos,v,rs(lst));return k;
}
int query(int l,int r,int k,int pos){
	if(l==r){return t[k].val;}int mid=l+r>>1;
	if(pos<=mid)return query(l,mid,ls(k),pos);
	else return query(mid+1,r,rs(k),pos);
}

int main(){
	n=read(),m=read();for(int i=1;i<=n;i++)a[i]=read();rt[0]=build(1,n,rt[0]);
	for(int i=1;i<=m;i++){
		int lst=read(),op=read(),pos=read(),v;
		if(op==1)v=read(),rt[i]=update(1,n,rt[i],pos,v,rt[lst]);
		else rt[i]=rt[i-1],printf("%d\n",query(1,n,rt[lst],pos));
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

  4. Delete the DEBUGGING? Add FILE I/O? Use The TRUE MODULE?
*/

