#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int psize=1000001;
int mpf[psize+5];
int mpff[psize+5];
int prime[664589];
int phi[psize+5];
long long he[psize+5];
int pn=0;
int n;
void getprime(){
    int i,j;
    memset(mpf,0,sizeof(mpf));
	memset(mpff,0,sizeof(mpff));
	memset(he,0,sizeof(he));
    for (i=2;i<psize;i++){
        if(mpf[i]==0) {prime[pn++]=i;phi[i]=i-1;mpf[i]=i;he[i]=i+i-1;mpff[i]=i;}
        for (j=0;j<pn&&i*prime[j]<psize&&prime[j]<=mpf[i];j++){
			int tmp=i*prime[j];
            mpf[tmp]=prime[j];
            if(mpf[i]==prime[j]) {
				phi[tmp]=phi[i]*prime[j];
				mpff[tmp]=mpff[i]*prime[j];
			}
            else {
				phi[tmp]=phi[i]*phi[prime[j]];
				mpff[tmp]=prime[j];
			}
			if(tmp==mpff[tmp]){
				he[tmp]=he[i]*prime[j]+phi[tmp];
			}
			else {
				he[tmp]=he[mpff[tmp]]*he[tmp/mpff[tmp]];
			}
        }
    }
}

int main(){
	getprime();
	//cout<<"4: "<<he[4]<<' '<<mpf[4]<<' '<<mpff[4]<<' '<<phi[4]<<endl;
	//cout<<"8: "<<he[8]<<' '<<mpf[8]<<' '<<mpff[8]<<' '<<phi[8]<<endl;
	he[1]=1;
	while(scanf("%d",&n)!=EOF){
		if(n&1){
			printf("%lld %lld\n",(he[n]+n)/2,(he[n]-n)/2);
		}
		else {
			printf("%lld %lld\n",(he[n]+n/2)/2,(he[n]-n/2)/2);
		}
	}
}
