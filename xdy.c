#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int getMax(int *dices, int x){
 int max;
 max = dices[0];
 for(int i = 1; i < x; i ++){
   if(dices[i] > max)max = dices[i];
 }
 return max;
}

int roll(int x, int y, int mode, int cn){

 int num,x2,count2,dices[x];
 int sum = 0, flg = 0, count = 1;

 srand((unsigned int)time(NULL));
 if(mode == 0){
    for(int i = 0; i < x; i ++){
       num = rand() % y + 1;
       printf("[%d回目] ... %d\n",i + 1, num);
       sum += num;
    }
    flg++;
 }

 if(mode == 1){
    x2 = x;
    count2 = 1;
    while(count != 0){
       puts("");
       printf("{");//描写文
       count = 0;
       for(int i = 0; i < x2; i++){
          dices[i] = rand() % y + 1;
 
         if(dices[i] >= cn){count++;}

          printf("%d", dices[i]);//描写文

          if(i < (x2-1)){printf(", ");}//描写文
       }
       puts("}");

       num = getMax(dices,x2);
       if(num >= cn){num = 10;}
       printf("[%d回目] ... %d\n",count2, num);
       sum += num;
       x2 = count;
       count2++;
    }
   flg++;
 }

 if(flg == 0){
    puts("ERROR ... Wrong parameter \"mode\"");
    return -1;
 }
 return sum;
}

int main(){

 int mode = 2,x,y,cn = 10;
 char d;

 puts("-----xdy-----\n x ... ダイスの個数\n y ... ダイスの面数\n-------------");

 while(mode != 0 && mode != 1){

    puts("モードを選んでください\n0 ... no mantion\n1 ... for DX3rd");
    scanf("%d",&mode);

    if(mode != 0 && mode != 1)
	puts("ERROR. PUT AGAIN.");
    }

 while(1){
    switch (mode){
        case 0:puts("xdyの形で入力してください");
               scanf("%*c%d %c %d",&x,&d,&y);
               break;
        case 1:puts("クリティカル値を設定してください");
               scanf("%*c%d",&cn);
               printf("クリティカル値 ... %d\n",cn);
               puts("xdの形で入力してください");
               scanf("%*c%d %c",&x,&d);
               y = 10;
               break;
    }

    printf("%d面ダイスを%d個振ります\n",y,x);
    printf("出目は%d\n",roll(x,y,mode,cn));
 }
 return 0;
}
