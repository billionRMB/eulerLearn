/*************************************************************************
	> File Name: try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 09时57分15秒
 ************************************************************************/

#include<stdio.h>
#define max 100000
int prime[max + 5] = {0};
int mnum[max + 5] = {0};
int dnum[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i]){
            prime[++prime[0]] = i;
            mnum[i] = 1;
            dnum[i] = 2;
        }
        for(int j = 1;j <= prime[0];j++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0){
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                break;
            }else{
                mnum[i * prime[j]] = 1;
                dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            }
        }
    }
}

int Trangle(int x){
    return x * (x + 1)/2;
}

int DTrangle(int x){
    if(x & 1)return dnum[x] * dnum[(x + 1)/2];
    return dnum[x + 1] * dnum[x / 2];
}

int main(){
    init();
    for(int i = 1;Trangle(i) < 100000000;i ++){
        if(DTrangle(i)>500){
            printf("%d %d\n",Trangle(i),DTrangle(i));
            return 0 ;
        }
    }
}
