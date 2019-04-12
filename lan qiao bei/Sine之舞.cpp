#include<iostream>
using namespace std;
void sine(int n,int times,bool flag);
void sn (int n,int times);
int main (){
	int n;
	cin>>n;
	sn(n,n);
	cout<<endl;
	return 0;
}
void sine(int n,int times,bool flag){
	 cout<<"sin(";
	 if(times==n)
	 	cout<<n;
	else{
		cout<<times;
		if(flag){
			cout<<"-";
			flag=false;
		}
		else{
			cout<<"+";
			flag=true;
		}
		sine(n,times+1,flag);
	}
	cout<<")";
}
void sn (int n,int times){
	if(times==1){
		sine(times,1,true);
		cout<<"+"<<n-times+1;
	}else{
		cout<<"(";
		sn(n,times-1);
		sine(times,1,true);
		cout<<"+"<<n-times+1;
	}
	if(times!=n)
			cout<<")";
}
