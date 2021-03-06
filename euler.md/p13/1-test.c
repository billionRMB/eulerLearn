/*************************************************************************
	> File Name: 1-test.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月20日 星期四 23时48分08秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main(){
    int ans[55] = {0};
    char num[55];//记得下次改一下名字 为 input_num 不然容易和ans乱掉
    while(scanf("%s",num)!= EOF){
        int num_len = strlen(num);
        //if(ans[0] < num_len) ans[0] = num_len;
        (ans[0] < num_len) && (ans[0] = num_len);
        for(int i = 1;i <= num_len;i ++){ // 注意此次如果没有先用strlen则可以使用; num[i];作为循环的判断条件 在循环string里的时候是个小技巧
            ans[i] += num[num_len - i] - '0';//因为string里0对应的是最高位上的数字 需要处理一下
        }
        for(int i = 1;i <= ans[0];i ++){
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i]/10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    printf("%d\n",ans[0]);
    for(int i = 0;i < 10;i++){
        printf("%d",ans[ans[0]-i]);
    }
    printf("\n");
}
