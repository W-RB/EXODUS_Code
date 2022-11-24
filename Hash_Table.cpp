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
	while(ch=='\n'||ch==' ')ch=getchar();
	while(ch!='\n'&&ch!=' ')ans+=ch,ch=getchar();
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
const int N=1e4+7,L=1e3+5e2+7,H=0;
const int base[3]={1000000007,157},mod[3]={1000000013,998244353};
string s[N];
np ans[N];
int n,Hash[N][L][3],Pow[L][3];
void init(){
	for(int i=0;i<=H;i++){Pow[0][i]=1;
		for(int j=1;j<=L-7;j++)Pow[j][i]=1ll*Pow[j-1][i]*base[i]%mod[i];
	}return;
}
void get_hash(int id){
	int len=s[id].length();
	for(int i=0;i<=H;i++){
		Hash[id][0][i]=s[id][0];
		for(int j=1;j<len;j++)
			Hash[id][j][i]=1ll*(Hash[id][j-1][i]*base[i]+s[id][j])%mod[i];
	}return;
}
np get_val(int id,int l,int r){return mp((1ll*Hash[id][r][0]-1ll*Hash[id][l-1][0]*Pow[r-l+1][0]%mod[0]+mod[0])%mod[0],(1ll*Hash[id][r][1]-1ll*Hash[id][l-1][1]*Pow[r-l+1][1]%mod[1]+mod[1])%mod[1]);}
bool query(int id1,int l1,int r1,int id2,int l2,int r2){return get_val(id1,l1,r1)==get_val(id2,l2,r2);}
int main(){
	n=read();init();
	for(int i=1;i<=n;i++)s[i]=reads(),get_hash(i),ans[i]=get_val(i,0,s[i].length()-1);
	sort(ans+1,ans+n+1);int Len=unique(ans+1,ans+n+1)-ans-1;printf("%d\n",Len);
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


