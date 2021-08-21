#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll(int x, int y, int mode){

 int count;
 int num = 0;

 srand((unsigned int)time(NULL));

 for(int i = 0; i < x; i++){
    num += rand() % (y + 1);
    printf("[%d回目] ... %d\n",i + 1,num);
    if(mode == 1){
       count++;
    }
 }
 return num;
}

int main(){

 int mode = 2,x,y;
 char d;

 puts("-----xdy-----\n x ... ダイスの個数\n y ... ダイスの面数\n-------------");
 while(mode != 0 && mode != 1){

    puts("モードを選んでください\n0 ... no mantion\n1 ... for DX3rd");
    scanf("%d",&mode);
    if(mode != 0 && mode != 1)
    puts("ERROR. PUT AGAIN.");
 }

 puts("xdyの形で入力してください");
 scanf("%*c%d %c %d",&x,&d,&y);

 printf("%d面ダイスを%d個振ります\n",y,x);
 printf("出目は%d\n",roll(x,y,mode));

 return 0;
}
