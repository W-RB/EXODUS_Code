#include<bits/stdc++.h>
#define re register
#define il inline
#define pb push_back
#define rep(i,l,r) for(int i(l);i<=r;++i)
#define per(i,l,r) for(int i(r);i>=l;--i)
#define repe(u) for(int i=head[u];i;i=e[i].nxt)

#define np pair<int,int>
#define mp make_pair
#define nb(k) bitset<k>
#define rev reverse
using namespace std;
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

#define ls(k) t[k].son[0]
#define rs(k) t[k].son[1]
const int N=2e5+7;
struct FHQ_Treap{int val,siz,wei,son[3];}t[N<<1];
stack<int>rub;int Rt,n;
void push_up(int rt){t[rt].siz=t[ls(rt)].siz+t[rs(rt)].siz+1;}
int newnode(int key){
	int rt=rub.top();rub.pop();ls(rt)=rs(rt)=0;
	t[rt].val=key,t[rt].wei=rand(),t[rt].siz=1;return rt;
}
void split(int rt,int key,int &x,int &y){
	if(!rt){x=y=0;return;}
	if(key>=t[rt].val)x=rt,split(rs(rt),key,rs(x),y);
	else y=rt,split(ls(rt),key,x,ls(y));
	push_up(rt);
}
int merge(int x,int y){
	if(!x||!y){return x|y;}
	if(t[x].wei<t[y].wei){rs(x)=merge(rs(x),y),push_up(x);return x;}
	else{ls(y)=merge(x,ls(y)),push_up(y);return y;}
}
void insert(int val){
	int x=0,y=0;split(Rt,val-1,x,y);
	Rt=merge(x,merge(newnode(val),y));
}
void remove(int val){
	int x=0,y=0,z=0;split(Rt,val,x,z);split(x,val-1,x,y);
	if(y)rub.push(y),y=merge(ls(y),rs(y));
	Rt=merge(merge(x,y),z);
}
int getrnk(int val){
	int x=0,y=0,ans=0;split(Rt,val-1,x,y);
	ans=t[x].siz+1;Rt=merge(x,y);return ans;
}
int getnum(int val){
	int rt=Rt;
	while(1){
        if(t[ls(rt)].siz+1==val)break;
        else if(t[ls(rt)].siz+1>val)rt=ls(rt);
        else val-=t[ls(rt)].siz+1,rt=rs(rt);
    }return t[rt].val;
}
int getpre(int val){
	int x=0,y=0,rt,ans;split(Rt,val-1,x,y);rt=x;
	while(rs(rt))rt=rs(rt);ans=t[rt].val;Rt=merge(x,y);
	return ans;
}
int getnxt(int val){
	int x=0,y=0,rt,ans;split(Rt,val,x,y);rt=y;
	while(ls(rt))rt=ls(rt);ans=t[rt].val;Rt=merge(x,y);
	return ans;
}

int main(){
	n=read();
	for(int i=1;i<=2e5;i++)rub.push(i);
	for(int i=1;i<=n;i++){
		int op=read(),x=read();
		if(op==1)insert(x);
        if(op==2)remove(x);
        if(op==3)printf("%d\n",getrnk(x));
        if(op==4)printf("%d\n",getnum(x));
        if(op==5)printf("%d\n",getpre(x));
        if(op==6)printf("%d\n",getnxt(x));
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
