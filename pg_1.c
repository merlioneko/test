#include<stdio.h>

void changebit(int d){

 int end = 0,i = 0, range = 8;
 int x[range];

 for(int j = 0; j < range; j++){
   x[j] = 0;
 }

 while(end != 1){
  if(d < 2){
   x[i] = 1;
   end = 1;
  }
  if(d >= 2){
   x[i] = d%2;
   d /= 2;
   i++;
  }
 }
 for(int j = range - 1; j > -1; j--){
  printf("%d",x[j]);
 }
 puts("");
}

int main(){

 int a[] = {1,2,3,4,5,6,7,8};

 for(int i = 0; i < 8; i++){
     printf("%d : bit ... ",a[i]);
     changebit(a[i]);
 }
 printf("10 : bit .... ");
 changebit(10);


 printf("4 << 1 |(2&3) answer = %d\n",4 << 1 | (2&3));
 changebit(4<<1 | (2&3));
 
 return 0;
}
