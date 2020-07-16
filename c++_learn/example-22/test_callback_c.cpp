#include <iostream>
#include <cstdlib>

///回调函数就是普通函数，区别在于调用形式，它是通过函数指针的形式
//被调用，一般来说，它要通过中间函数发起调用，而不是被主程序直接调用

///回调函数 形式1
int finance_sum_result(int * a ,int n){
	int result = 0;
	for(int i = 0;i<n;i++){
		result +=*(a+i);
	}
	return result;
}

///回调函数 形式2
int finance_ave_result(int * a ,int n){
	int result = 0;
	for(int i = 0;i<n;i++){
		result +=*(a+i);
	}
	return result/n;
}

//函数指针，通过typedef将其变为一个类型，关注的是函数特征标和返回值
typedef int(*fp)(int* ,int );


//中间函数,在这里
void boss_read_finance(int* array,int n,fp p){
	////两种调用形式都可以
	//int result = (*p)(array,n);
	int result = p(array,n);
	printf("caculate result:%d\n",result);
}


///主程序
//中间函数
int main(){
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	boss_read_finance(array,10,finance_sum_result);
	boss_read_finance(array,10,finance_ave_result);
	return 0;
}
