#include<iostream>
using namespace std;
int main (){
	int a,b;
	cin>>a>>b;
	int i,j;
	for (i=a;i<=b;i++){
		cout<<i<<"=";
		bool first=true;
		int t=i;
		for(j=2;j<=i/2;j++){
			if(t%j==0){
				if(first){
					cout<<j;
					first=false;
				}else{
					cout<<"*"<<j;
				}
				t/=j;
				j=1;
			}
		}
		if(t!=1){
			if(first){
				cout<<t;
			}else{
				cout<<"*"<<t;
			}
		}
		cout<<endl;
	}
	return 0;
}
