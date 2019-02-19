/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月26日 星期三 17时42分21秒
 ************************************************************************/

#include<stdio.h>
#define max 100

int prime[max + 5] = {0};

void init(){
    for(int i = 2;i < max;i ++){
        if(prime[i])continue;
        prime[++prime[0]] = i;
        for(int j = i * i;j < max ;j+=i){
            prime[j] = 1;
        }
    }
}



int main(){
    init();
    printf("%d\n",prime[0]);
    
    for(int i = 1;i <= prime[0];i++){
        printf("%d\n",prime[i]);
    }
    return 0;
}
