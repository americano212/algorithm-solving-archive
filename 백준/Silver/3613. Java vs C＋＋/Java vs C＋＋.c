#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[101];
int str_l;

void make_java(){
	for (int i=0;i<str_l;i++){
		if (str[i]<91){
			printf("Error!\n");
			return;
		}
	}
	int check_ = 0;
	for (int i=0;i<str_l;i++){
		if (str[i]=='_'){
			check_ = 1;
		}
		else if (check_ == 1){
			printf("%c",str[i]-32);
			check_ = 0;
		}
		else{
			printf("%c",str[i]);
		}
	}
	printf("\n");
}
void make_cpp(){
	for (int i=0;i<str_l;i++){
		if (str[i]=='_'){
			printf("Error!\n");
			return;
		}
	}
	for (int i=0;i<str_l;i++){
		if (str[i]<91){
			printf("_%c",str[i]+32);
		}
		else{
			printf("%c",str[i]);
		}
	}
	printf("\n");
}

int main(){
	scanf("%s",str);
	str_l = strlen(str);
	
	if (!(str[0]>96 && str[0]<123)){
		printf("Error!\n");
		return 0;
	}
	if (str[str_l-1]=='_'){
		printf("Error!\n");
		return 0;
	}
	int err_check = 0;
	for (int i=0;i<str_l;i++){
		if (str[i]=='_'){
			if (err_check==1){
				printf("Error!\n");
				return 0;
			}
			err_check = 1;
		}
		else{
			err_check = 0;
		}
	}
	
	for (int i=0;i<str_l;i++){
		if (str[i]=='_'){
			make_java();
			return 0;
		}
		if (str[i]<91){
			make_cpp();
			return 0;
		}
		
	}
	printf("%s",str);
	return 0;
}