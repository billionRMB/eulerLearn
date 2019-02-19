/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail: 
	> Created Time: 2018年12月19日 星期三 20时26分00秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int fib[3][1005] = {0},n = 2;// 一定要初始化一下 局部变量
    fib[1][0] = fib[1][1] = 1;
    fib[2][0] = fib[2][1] = 1;

    while(fib[n % 3][0] < 1000){
        n ++;
        for(int i = 1;i <= fib[(n + 2)%3][0];i ++){
            fib[n % 3][i] = fib[(n + 1)%3][i] + fib[(n + 2)%3][i];
            //因为初始化的时候就是从1开始保存然后 i + 1 为高位
        }
        fib[n % 3][0] = fib[(n + 2)%3][0];
        for(int i = 1;i <= fib[n % 3][0];i ++){
            if(fib[n % 3][i] < 10) continue;
            fib[n % 3][i + 1] += fib[n % 3][i] / 10;
            fib[n % 3][i] %= 10;
            fib[n % 3][0] += (i == fib[n % 3][0]);//注意是  +=
        }
    }

    printf("%d\n",n);
    return 0;
}
