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
const int N=1e5+7;
bool DataS=0,FilE=0;
int T;
void init(){
	return;
}

struct Tree{int l,r;ll val,tag;}t[N<<2];int a[N],n,q;
void change(int v,int k){t[k].tag+=v,t[k].val+=(t[k].r-t[k].l+1)*v;}
void push_up(int k){t[k].val=t[ls(k)].val+t[rs(k)].val;}
void build(int l,int r,int k){
	t[k].l=l,t[k].r=r;if(l==r){return change(a[l],k);}
	int mid=l+r>>1;build(l,mid,ls(k));build(mid+1,r,rs(k));push_up(k);
}void push_down(int k){
	if(t[k].l==t[k].r||!t[k].tag)return (void)(t[k].tag=0);
	change(t[k].tag,ls(k)),change(t[k].tag,rs(k));t[k].tag=0;
}void update(int l,int r,int k,int v){
	if(l<=t[k].l&&t[k].r<=r)return change(v,k);
	if(t[k].l>r||t[k].r<l)return;push_down(k);
	update(l,r,ls(k),v),update(l,r,rs(k),v),push_up(k);return;
}ll query(int l,int r,int k){
	if(l<=t[k].l&&t[k].r<=r)return t[k].val;
	if(t[k].l>r||t[k].r<l)return 0;push_down(k);
	return query(l,r,ls(k))+query(l,r,rs(k));
}

int main(){
	if(FilE){
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	}
	T=(DataS?read():1);
	while(T--){
		init();
		n=read(),q=read();for(int i=1;i<=n;i++)a[i]=read();build(1,n,1);
		while(q--){int op=read(),l=read(),r=read();(op^1)?(void)(printf("%lld\n",query(l,r,1))):update(l,r,1,read());}
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


