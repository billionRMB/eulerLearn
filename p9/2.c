/*************************************************************************
	> File Name: 1.try.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月04日 星期五 08时28分01秒
 ************************************************************************/

#include<stdio.h>
#include<inttypes.h>
int main(){
    int64_t a,b,c = 0;
    for(a = 1;a < 334;a ++){
        for(b = a; b < 1000 - a ; b++){
            c = 1000 - a - b;
            if(c * c == a * a + b * b )break;
        }
    }
    printf("%d %d %d\n",a,b,c);
    printf("%d + %d = %d\n",a * a, b * b,c * c);
}
