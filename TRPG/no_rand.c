#include<stdio.h>

int main(){
 char TABLE[256];
 FILE *fp;
 fp = fopen("LIST.txt", "r");
 if(fp == NULL){
	 puts("ERROR!!!!---CAN'T OPEN \"LIST.txt\"---");//リストデータをひけないとき
	 fclose(fp);
	 return -1;
 }
}
