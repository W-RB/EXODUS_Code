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
#define lowbit(i) (i&-i)
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
int n;
int a[N],b[N];
void merge(int st1,int ed1,int st2,int ed2){
	int pos1=st1,pos2=st2,cnt=0;
	while(pos1!=ed1+1&&pos2!=ed2+1)b[++cnt]=a[pos1]<a[pos2]?a[pos1++]:a[pos2++];
	for(;pos1<=ed1;pos1++)b[++cnt]=a[pos1];for(;pos2<=ed2;pos2++)b[++cnt]=a[pos2];
	for(int i=0;i<cnt;i++)a[st1+i]=b[i+1];return;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,tot;i<=n;i++,tot=0){
		for(int j=i;lowbit(j)!=1;j>>=1,tot++);
		for(int j=1;j<=tot;j++)merge(i-(1<<j)+1,i-(1<<j-1),i-(1<<j-1)+1,i);
	}
	for(int i=20,lst=0;i>=0;i--){
		if(n&(1<<i)){
			if(!lst){lst=(1<<i);continue;}
			merge(1,lst,lst+1,lst+(1<<i));lst+=(1<<i);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
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


