#include<iostream>
using namespace std;
int main (){
	int v1,v2,s,T,l;
	cin>>v1>>v2>>T>>s>>l;
	int r=0,t=0;
	int sleep=0;
	int ans=0;
	while(r<l&&t<l){
		if(sleep<=0)
			r+=v1;
		t+=v2;
		sleep--;
		if(sleep<=0&&r-t>=T)
			sleep=s;
		ans++;
	}
	if(r>=l&&t>=l)
		cout<<"D"<<endl<<ans;
	else if(r>=l)
		cout<<"R"<<endl<<ans;
	else
		cout<<"T"<<endl<<ans;
	return 0;
}
