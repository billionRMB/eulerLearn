### Euler 27 **二次“素数生成”多项式**

----

[题目链接](http://pe-cn.github.io/27/)

关于这道题目

需要解决的点主要是

1. 判断一个数是不是素数
2. 如何有效的减枝

#### 判断一个数是不是素数

判断一个数是不是素数有很多种做法，比如试除法

今天呢使用一个更快的办法**米勒测试**

主要的原理是根据费马小定理

**定理描述**

​	当且仅当　Ｐ　为素数时：

​			ａ^p-1^  mod P 为　１

​	１　<= a <= p - 1

那么我们只需要选取若干个ａ，代入以上公式

求得结果，若均为１，说明　Ｐ　在很大概率上是个素数

代码如下

```c
/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 11时52分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define test_round 30

int r_m_test(int x){
    if(x <= 1)return 0;
    //注意对函数的输入范围进行限制，这才是一个良好的函数定义方法
    int a , m, ans ;
    for(int i = 0;i < test_round;i ++){
        a = rand()%(x - 1) + 1;
        m = x - 1;
        ans = 1;
        while(m){
            if(m & 1)ans = ans * a % x;
            a = a * a % x;
            m >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}

int main(){
    srand(time(0));
    for(int i = 2;i < 100;i ++){
        if(r_m_test(i))printf("%d\n",i);
    }
    return 0;
}
```

这里有两点需要注意的是　

1. ａｎｓ　需要初始化　为　１

   凡是涉及到累乘的变量　初始化　为　１

   累加的变量　初始化　为　０

2. **对函数的输入范围进行限制，这才是一个健壮的函数定义方式**

#### 如何剪枝呢？

1. 考虑ｉ　＝　０时　ｂ　需要为　素数

2. 考虑ｉ　＝　１时　ａ　＋　ｂ　＋　１　需要为素数

3. 对于　x * x + a * x + b　这个式子的上界会是多少

   也就是说到某个最小的可能合数，也就是ａ，ｂ的最小公因子

结合上诉分析，我们需要一个素数筛的变形形式，来保留每个数字的最小素因子

```c
for(int i = 2; i < max_n;i ++){
    if(!prime[i])
    for(int j = i ;j < max_n;j += i)
    (!prime[j])&&(prime[j] = i);
}
```

ok 了

接下来就是合起来了

```c
/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2019年01月08日 星期二 11时52分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define test_round 30
#define max_n 10000

int prime[max_n + 5] = {0};

int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a % b);
}

int r_m_test(int x){
    if(x <= 1)return 0;// 注意对函数的输入范围进行限制，这才是一个良好的定义函数的方式
    int a , m, ans ;
    for(int i = 0;i < test_round;i ++){
        a = rand()%(x - 1) + 1;
        m = x - 1;
        ans = 1;// ans = 1;
        while(m){
            if(m & 1)ans = ans * a % x;
            a = a * a % x;
            m >>= 1;
        }
        if(ans != 1)return 0;
    }
    return 1;
}

int get_leng(int a,int b){
    int i = 0;
    while(r_m_test(i * i + a * i + b))i ++;
    return i;
}

void init(){
    for(int i = 2;i < max_n;i ++){
        if(!prime[i])
            for(int j = i;j < max_n;j += i)
                (!prime[j])&&(prime[j] = i);
    }
}

int main(){
    srand(time(0));
    init();
    int ans = 0,temp_l = 0,max_l = 0;
    for(int a = -999;a < 1000;a ++){
        for(int b = 2;b < 1000;b ++){
            if(prime[b] != b)continue;
            if(prime[a + b + 1]!= a + b + 1)continue;
            if(a > 0 && b > 0 && prime[gcd(a,b)] <= max_l)continue;
            temp_l = get_leng(a,b);
            if(temp_l > max_l){
                ans = a * b;
                max_l = temp_l;
            }
        }
    }
    printf("%d\n",ans); 
    return 0;
}
```

