#include<iostream>
using namespace std; 
int main (){
	int n;
	cin>>n;
	int table [25][25];
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			cin>>table[i][j];
		}
	}
	bool first=true;
	for (i=0;i<n;i++){
		int r=0;
		for (j=0;j<n;j++){
			if(table[j][i])
				r++;
			}
			if(r>n/2){
				if(first){
					cout<<i+1;
					first=false;
				}else
					cout<<" "<<i+1;
		}
	}
	return 0;
}
