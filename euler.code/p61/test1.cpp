/*************************************************************************
	> File Name: 1.c
	> Author:Gin.TaMa 
	> Mail:1137554811@qq.com 
	> Created Time: 2018年12月29日 星期六 12时02分47秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Triangle(int n) {
    return (n * (n + 1)) / 2;
}

int Square(int n) {
    return n * n;
}

int Pentagonal(int n) {
    return n * (3 * n - 1) / 2;
}

int Hexagonal(int n) {
    return n * (2 * n - 1);
}

int Heptagonal(int n) {
    return n * (5 * n - 3) / 2;
}

int Octagonal(int n) {
    return n * (3 * n - 2);
}

int binary_search(int (*func)(int),int y){
    int head = 1,tail = y,mid;
    while(head <= tail){
        mid = (head + tail)/2;
        int temp = func(mid);
        if(temp == y)return 1;
        if(temp < y) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int (*FuncList[6])(int) = {
    Triangle,Square,Pentagonal,
    Hexagonal,Heptagonal,Octagonal
};// 函数指针变量数组

int check(int *num){
   sort(num,num + 6);
    do{
        int i;
        for(i = 0;i < 6;i ++){
            if(binary_search(FuncList[i],num[i]))continue;
            break;
        }
        if(i == 6)return 1;
    }while(next_permutation(num,num + 6));
    return 0;
}

vector<int> g[100];
int ans[7] = {0};
int vis[100] = {0};//ｖｉｓ数组为１００　就够了主要目的还是为了避免有指向自己的环
void init_graph(){
    int cnt = 0;
    for(int i = 0;i < 6;i ++){
        int k = 1;
        while(FuncList[i](k) < 1000) ++k;
        while(FuncList[i](k) < 10000){
            int num = FuncList[i](k++);
            g[num/100].push_back(num);
            cnt += 1;
        } 
    }
    cout<<"graph has "<<cnt<<" nodes"<<endl;
    return ;
}

int dfs(int x,int k){
    ans[k - 1] = x;
    if(k == 6){
        return (x % 100 == ans[0]/100)&&check(ans);
    }
    int ind = x % 100;
    if(vis[ind])return 0;
    for(int i = 0;i < g[ind].size();i++){
        if(dfs(g[ind][i], k+1))return 1;
    }
    return 0;
}

int main(){
    init_graph();
    int flag = 1;
    for(int i = 10;i < 100&& flag;i++){
        vis[i] = 1;
        for(int j = 0;j < g[i].size()&& flag;j++){
            if(dfs(g[i][j],1)) flag = 0;
        }
    }
    int sum = 0;
    for(int i = 0;i < 6;i++){
        cout<<ans[i]<<" ";
        sum += ans[i];
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}
