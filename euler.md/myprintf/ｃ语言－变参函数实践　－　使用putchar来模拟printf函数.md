## ｃ语言－变参函数实践　－　使用putchar来模拟printf函数



其实很简单的实现对于％ｄ的输出
测试用例
使用我们实现的my_printf　函数对于下列情况可以实现和使用printf相同的效果

```c
int main(){
    int n = 123;
    my_printf("hello haizei\n");
    my_printf("n = %d\n",n);
    my_printf("n = %d\n",456);
    my_printf("n = %d\n",-567);
    my_printf("n = %d\n",12000);
    my_printf("n = %d\n",INT32_MIN);
    my_printf("n = %d\n",INT32_MAX);
    my_printf("n = %d\n",0);
    return 0;
}

hello haizei
n = 123
n = 456
n = -567
n = 12000
n = -2147483648
n = 2147483647
n = 0

```

ＯＫ　怎么实现的呢？
首先介绍一下ｖａ　一族函数，算是ｃ预留的变参函数的接口

- va 一族

  va_list 　定义类型的变量   va_list arg;　类似　int ,就是一种类型定义

  va_start 　获得第一个变量的地址

  va_arg 　获得一个变量的值，同时指向下一个变量　

  va_end 　释放va_list 变量的内存　

接下来是my_printf 函数部分
```c
int my_printf(const char * str,...){
	//这里的　... 是在声明该函数是变参函数
    va_list arg;　// 声明　一个通用的函数类型，因为传入的参数的类型在此时是不确定的，所以使用这个来避免错误
    va_start(arg,str);　// 获得　第一个函数的指针位置，之所以这么做，是为了接下来的va_arg　找到下一个参数　具体原因可以百度学习一下　
    int lengh = 0;　// 普通字符的长度
    int num_lengh = 0;　// 数字的长度
    while(str[lengh]!='\0'){
        if(str[lengh] == '%'){
            int num = va_arg(arg,int);
            num_lengh += my_printf_num(num);
            lengh ++;
        }else{
            putchar(str[lengh]);
        }
        lengh++;
    }
    va_end(arg);
    return lengh + num_lengh;
}

```

很简单的逻辑就是　遍历　格式控制字符串，遇到 % 开头就调用　my_printf_num函数来处理，其他情况就普普通通的putchar就好。

接下来实现my_printf 函数

首先阐述要解决的问题
1.  输出不以零结尾的数字
2.  输出以零结尾的数字
3.  输出负数
4.  输出INT32_MAX
5.  输出INT53_MIN
6.  输出零

```c
int my_printf_num(int n){
    int tail = n % 10; // 之所以这么处理　是为了防止　输出　INT32_MAX 的时候炸了
    n /= 10;　
    // 处理负数的情况
    if(tail < 0){
        n *= -1;
        tail *= -1; 
        putchar('-');
    }
    // 接下来要输出了，为了方便输出将ｎ翻转一下，因为获取最后一位的数字，比获取第一位的数字容易，为啥呢，% 10 就可以方便的获得最后一位了，但是　获得最高位就稍微有点麻烦
    // 但是呢，反转后，容易出现丢失零的问题，１２０００　翻转后就变成了２１，这肯定不对，所以需要统计一下数字的长度
    int lengh = 0;
    int temp = 0;
    while(n){
        temp = temp * 10 + n % 10;
        n /= 10;
        lengh ++;
    }
    for(int i = 0;i < lengh;i ++){
        putchar('0' + temp % 10);
        temp /= 10;
    }
    // 别忘了输出最后的尾巴
    putchar('0'+tail);
    return lengh;
}


```

有一些小点需要注意，总而言之，蛮有趣的
另外　写程序的时候记得要有框架思维，就是说，不仅要把功能封装成函数
在写一个函数内部的时候，也要分层次的写
比如　
写了va_start
就接着把va_end写到底部，因为他们是一个层次的东西
不要向打印机一样，从头到尾，从上到下的一行一行的写，这样很容易出ｂｕｇ
因为人是分层次解决问题的，那就分层次的解决问题，分层次的写代码