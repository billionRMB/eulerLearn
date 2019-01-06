/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月06日 星期日 16时02分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>
#include<inttypes.h>
int my_printf_num(int num){
    int tail = num % 10;
    num /= 10;
    if(tail < 0){
        putchar('-');
        tail *= -1;
        num *= -1;
    }
    int lengh = 0;
    int temp = 0;
    while(num){
        temp = temp * 10 + num % 10;
        num /= 10;
        lengh ++;
    }
    for(int i = 0;i < lengh;i ++){
        putchar('0' + temp % 10);
        temp /= 10;
    }
    putchar('0'+tail);
    return lengh;
}


int my_printf(const char* str, ...){
    int lengh = 0,num_lengh = 0;
    va_list arg;
    va_start(arg,str);
    while(str[lengh]!='\0'){
        if(str[lengh] == '%'){
            int n = va_arg(arg,int);
            num_lengh = my_printf_num(n);
            lengh++;
        }else{
            putchar(str[lengh]);
        }
        lengh++;
    }
    va_end(arg);
    return lengh + num_lengh;
}

int main(){
    int n = 123;
    my_printf("hello haizei\n");
    my_printf("n = %d\n",n);
    my_printf("n = %d\n",456);
    my_printf("n = %d\n",-5);
    my_printf("n = %d\n",12000);
    my_printf("n = %d\n",INT32_MIN);
    my_printf("n = %d\n",INT32_MAX);
    n = 0;
    my_printf("n = %d\n",n);
    return 0;
}
