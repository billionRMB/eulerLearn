/*************************************************************************
	> File Name: random.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月14日 星期一 09时10分24秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
#define max 2000000

int prime[max + 5] = {0};

void init(){
    for(int i = 2;i < max ;i++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0];j ++){
            if(i * prime[j] > max)break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0)break;
        }
    }
}

int main(){
    init();
    int64_t ans = 0;
    for(int i = 1;i <= prime[0];i ++){
        ans += prime[i];
    }
    printf("%"PRId64"\n",ans);
    return 0;
}
