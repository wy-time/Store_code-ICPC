#include<iostream>
using namespace std;
int main (){
	int t ;
	cin>>t;
	int h=0,m=0,s=0;
	h=t/3600;
	t%=3600;
	m=t/60;
	t%=60;
	s=t;
	cout<<h<<":"<<m<<":"<<s<<endl;
	return 0;
}
