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
#define int long long
#define lowbit(x) (x&-x)
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
ll n,m,arr[N],a[N];
void add(int x,ll v){for(;x<=n;x+=lowbit(x))arr[x]+=v;}
ll ask(int x){ll res=0;for(;x;x-=lowbit(x))res+=arr[x];return res;}

signed main(){
	if(FilE){
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	}
	T=(DataS?read():1);
	while(T--){
		init();
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=read(),add(i,a[i]-a[i-1]);
		while(m--){int op=read();if(op&1){int l=read(),r=read(),v=read();add(l,v),add(r+1,-v);}else printf("%lld\n",ask(read()));}
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

