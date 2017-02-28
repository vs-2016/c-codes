#include <stdio.h>
#include <stdlib.h>	//malloc free
#include <time.h>	//time()
#include <sys/time.h>	//gettimeofday()
int GenRandNumsUniq(int lower,int upper,int n,int *arr,size_t arrsize){
	if(lower>upper || !arr)return -1;
	int cnt=upper-lower+1;
	if(n>cnt||(arrsize/sizeof(int))<cnt)return -2;
	srand((int)time(0));
	for(int i=0;i<cnt;i++)arr[i]=lower+i;
	for(int i=0,x,t;i<n;i++){
		x=rand()%cnt;
		t=arr[i];
		arr[i]=arr[x];
		arr[x]=t;
	}
	return 0;
}
void Example0(void){
	int low,up,n;
	printf("input lower and upper:");
	scanf("%d%d",&low,&up);
	n=up-low+1;
	size_t bufsz=sizeof(int)*n;
	int *p=(int *)malloc(bufsz);
	struct timeval tv0,tv1;
	gettimeofday(&tv0,NULL);
	int r=GenRandNumsUniq(low,up,n,p,bufsz);
	gettimeofday(&tv1,NULL);
	if(r)printf("error input!\n");
	else{
		float ft=(tv1.tv_sec-tv0.tv_sec)*1000+(tv1.tv_usec-tv0.tv_usec)/1000.0;
		if(n<=20)for(int i=0;i<n;i++)printf("%d\n",p[i]);
		printf("cost:%.2fms\n",ft);
	}
	if(p)free(p);
}
void Example1(){
	int low,up,n=0;
	printf("input lower,upper,number:");
	scanf("%d%d%d",&low,&up,&n);
	size_t bufsz=sizeof(int)*(up-low+1);
	int *p=(int *)malloc(bufsz);
	struct timeval tv0,tv1;
	gettimeofday(&tv0,NULL);
	int r=GenRandNumsUniq(low,up,n,p,bufsz);
	gettimeofday(&tv1,NULL);
	if(r)printf("error input!\n");
	else{
		float ft=(tv1.tv_sec-tv0.tv_sec)*1000+(tv1.tv_usec-tv0.tv_usec)/1000.0;
		if(n<=20)for(int i=0;i<n;i++)printf("%d\n",p[i]);
		printf("cost:%.2fms\n",ft);
	}
	if(p)free(p);
}
int main(int argc, char **argv){
	Example1();
	return 0;
}