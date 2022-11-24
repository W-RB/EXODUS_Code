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
il ll read(){
	ll ans=0,flag=1;
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
const int N=1e6+7;
int n,k;ll a[N];np ans[N];
struct monotone_max_queue{
	int q[N],head,tail;
	monotone_max_queue(){head=1,tail=0;}
	void ins(int x,int start){
		while(q[head]<start&&head<=tail)head++;
		while(head<=tail&&a[q[tail]]<=a[x])tail--;
		q[++tail]=x;
	}
	int que(){return q[head];}
	int siz(){return tail-head+1;}
	bool emp(){return !(tail-head+1);}
}qmax;
struct monotone_min_queue{
	int q[N],head,tail;
	monotone_min_queue(){head=1,tail=0;}
	void ins(int x,int start){
		while(q[head]<start&&head<=tail)head++;
		while(head<=tail&&a[q[tail]]>=a[x])tail--;
		q[++tail]=x;
	}
	int que(){return q[head];}
	int siz(){return tail-head+1;}
	bool emp(){return !(tail-head+1);}
}qmin;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<k;i++)qmax.ins(i,-1),qmin.ins(i,-1);
	for(int i=1;i<=n-k+1;i++){
		qmax.ins(i+k-1,i);qmin.ins(i+k-1,i);
		ans[i]=mp(qmax.que(),qmin.que());
	}
	for(int i=1;i<=n-k+1;i++)printf("%lld ",a[ans[i].second]);puts("");
	for(int i=1;i<=n-k+1;i++)printf("%lld ",a[ans[i].first ]);
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


