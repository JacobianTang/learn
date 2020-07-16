#include <iostream>
typedef const double* (*p_fun)(const double*,int);

const double* f1(const double ar[],int n);
const double* f2(const double [],int );
const double* f3(const double* ,int);


const double* f1(const double *ar ,int n){
	return ar;
}

const double* f2(const double ar[],int n){
	return ar+1;
}

const double* f3(const double ar[],int n){
	return ar+2;
}

int main(){
	using namespace std;
	double ar[3]={1112.3,1542.6,2227.9};
	cout<< "ar address:"<<ar<<" ar array address: "<<&ar<<endl;
	cout<<" " <<sizeof(double)<<endl;
	int b=0;
	int* p=&b;
	cout<< "b address:"<<p<<" p- address: "<<&p<<endl;
	const double *(*p1)(const double*,int)=f1;
	auto p2=f2;
	cout<< " Using pointers to function:\n";
	cout<< " Address Value\n";
	cout<< (*p1)(ar,3)<<": "<<*(*p1)(ar,3) <<endl;
	cout<<p2(ar,3)<<": "<<*p2(ar,3)<<endl;
	
	const double* (*pa[3])(const double* ,int)={f1,f2,f3};
	auto pb=pa;
	cout<<"\n Using an array of pointers to functions:\n";
	cout<<" Address Value\n";
	for(int i=0;i<3;i++){
		cout<<pa[i](ar,3)<<": "<<*pa[i](ar,3)<<endl;
	}
	cout<<"\n Using a pointer to a pointer to a function:\n";
	cout<<" Address Value\n";

	for(int i=0;i<3;i++){
		cout<<pb[i](ar,3)<<": "<<*pb[i](ar,3)<<endl;
	}
	cout<< "\n Using pointers to an array of pointers:\n";
	cout<<" Address Value\n";
	
	auto pc=&pa;


}
