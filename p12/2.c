/*************************************************************************
	> File Name: 2.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 17时53分27秒
 ************************************************************************/

#include<stdio.h>
#define max 100

int prime[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j ++){
            if(prime[j] * i > max) break;
            prime[prime[j] * i] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int main(){
    init();
    for(int i = 0;i <= prime[0];i ++){
        printf("%d\n",prime[i]);
    }
    return 0;
}
