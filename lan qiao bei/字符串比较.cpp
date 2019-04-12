#include<iostream>
#include<cstring>
using namespace std;
int main (){
	char s1[15];
	char s2[15];
	cin>>s1>>s2;
	int len1=strlen(s1);
	int len2=strlen(s2);
	if(len1!=len2){
		cout<<1;
	}else if(strcmp(s1,s2)==0){
		cout<<2;
	}else if(stricmp(s1,s2)==0){
		cout<<3;
	}else{
		cout<<4;
	}
	return 0;
}
