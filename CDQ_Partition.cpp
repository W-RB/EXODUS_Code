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

#define lowbit(x) x&-x
const int N=3e5+7;
int n,k,tot=1,cnt,arr[N],ans[N];
struct node{int x,y,z,ans,cnt;}a[N<<1],r[N<<1];
void add(int x,int v){for(;x<=k;x+=lowbit(x))arr[x]+=v;}
int ask(int x){int res=0;for(;x;x-=lowbit(x))res+=arr[x];return res;}
bool cmpx(node a,node b){return a.x==b.x?a.y==b.y?a.z<b.z:a.y<b.y:a.x<b.x;}
bool cmpy(node a,node b){return          a.y==b.y?a.z<b.z:a.y<b.y;        }
void CDQ(int l,int r){
    if(l==r)return;int mid=l+r>>1;CDQ(l,mid);CDQ(mid+1,r);
    sort(a+l,a+mid+1,cmpy);sort(a+mid+1,a+r+1,cmpy);
    int j=l,i=mid+1;
    for(;i<=r;i++){
        while(a[j].y<=a[i].y&&j<=mid)add(a[j].z,a[j].cnt),j++;
        a[i].ans+=ask(a[i].z);
    }for(int k=l;k<j;k++)add(a[k].z,-a[k].cnt);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)r[i].x=read(),r[i].y=read(),r[i].z=read();
	sort(r+1,r+n+1,cmpx);
	for(int i=1;i<=n;i++,tot++)
	    if(r[i].x!=r[i+1].x||r[i].y!=r[i+1].y||r[i].z!=r[i+1].z)
	        a[++cnt]=r[i],a[cnt].cnt=tot,tot=0;
	CDQ(1,cnt);
	for(int i=1;i<=cnt;i++)ans[a[i].ans+a[i].cnt-1]+=a[i].cnt;
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
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


