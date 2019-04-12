#include<iostream>
using namespace std;
void slove(int n);
int main (){
	int n;
	cin>>n;
	slove(n);
	return 0;
}
void slove(int n){
	char temp='A'+n-1;
	if(n==1)
		cout<<temp;
	else{
		slove(n-1);
		cout<<temp;
		slove(n-1);
	}
}
