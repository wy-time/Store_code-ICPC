#include<iostream>
using namespace std;
const int yi=100000000;
char ans[11][10]={{"ling"},{"yi"},{"er"},{"san"},{"si"},{"wu"},{"liu"},{"qi"},{"ba"},{"jiu"},{"shi"}};
int main (){

	int n;
	cin>>n;
	int a[11]={0};
	int i=0;
	int temp=n;
	while(n){
		a[i]=n%10;
		n/=10;
		i++;
	}
	bool first=true;
	bool ling=true;
	for(i-=1;i>=0;i--){
		switch (i){
			case 9:
				if(a[i]!=1)
					cout<<ans[a[i]]<<" ";
				cout<<"shi";
				first=false;
				break;
			case 8:
				if(first){
					cout<<ans[a[i]]<<" "<<"yi";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"yi";
						ling=true;
					}
					else{
						cout<<" "<<"yi";
						if(temp%yi){
							cout<<" "<<ans[a[i]];
							ling=false;
						}
						
					}
				}
				break;
			case 7:
				if(first){
					cout<<ans[a[i]]<<" "<<"qian";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"qian";
						ling=true;
					}else if(ling&&temp%yi>=10000){//万有没有 
						cout<<" "<<ans[a[i]];
						ling=false;
					}
				}
				break;
			case 6:
				if(first){
					cout<<ans[a[i]]<<" "<<"bai";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"bai";
						ling=true;
					}else if(ling&&(a[4]||a[5])){
						cout<<" "<<ans[a[i]];
						ling=false;
					}
				}
				break;
			case 5:
				if(first){
					if(a[i]!=1)
						cout<<ans[a[i]]<<" ";
					cout<<"shi";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"shi";
						ling=true;
					}else if(ling&&a[4]){
						cout<<" "<<ans[a[i]];
						ling=false;
					}
				}
				break;
			case 4:
				if(first){
					cout<<ans[a[i]]<<" "<<"wan";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"wan";
						ling=true;
					}else {
						if(temp%yi>=10000){
							cout<<" "<<"wan";
						}
						if(ling&&temp%10000>0){
							cout<<" "<<ans[a[i]];
							ling=false;
						}
					}
				}
				break;
			case 3:
				if(first)
				{
					cout<<ans[a[i]]<<" "<<"qian";
					first=false;
				}else {
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"qian";
						ling=true;
					}else{
						if(ling&&temp%1000){
						 	cout<<" "<<ans[a[i]];
						 	ling=false;
						 }
					}
				}
				break;
			case 2:
				if(first){
					cout<<ans[a[i]]<<" "<<"bai";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"bai";
						ling=true;
					}else if(ling&&temp%100){
						cout<<" "<<ans[a[i]];
						ling=false;
					}
				}
				break;
			case 1:
				if(first){
					if(a[i]!=1)
						cout<<ans[a[i]]<<" ";
					cout<<"shi";
					first=false;
				}else{
					if(a[i]){
						cout<<" "<<ans[a[i]]<<" "<<"shi";
						ling=true;
					}else if(ling&&temp%10){
						cout<<" "<<ans[a[i]];
						ling=false;
					}
				}
				break;
			case 0:
				if(first){
					cout<<ans[a[i]];
				}else{
					
					if(a[i]){
						cout<<" "<<ans[a[i]];
					}
				}
				break;
		}
	}
}
