#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll(int x, int y, int mode, int cn){

 int num,count;
 int x2 = x;
 int sum = 0,flg = 0,fc = 1;

 srand((unsigned int)time(NULL));
 while(flg == 0){
  count = 0;
  if(mode == 1)
     printf("////%d times///\n",fc);
  for(int i = 0; i < x2; i++){
     num = rand() % y + 1;
     printf("[%d times] ... %d\n",i + 1,num);
     sum += num;
     if(mode == 1 && cn <= num){
        count++;
        puts("critical!");
     }
  }
  if(mode == 0){
     flg++;
  }
  if(mode == 1){
     x2 = count;
     fc++;
     if(count == 0){
       flg++;
     }
  }
 }
 return sum;
}

int main(){

 int mode,x,y,cn = 10;
 char d;

 puts("-----xdy-----\n x ... number of dice(s)\n y ... number of face(s)\n-------------");

 while(mode != 0 && mode != 1){

    puts("Choise a mode\n0 ... no mantion\n1 ... for DX3rd");
    scanf("%d",&mode);

    if(mode != 0 && mode != 1)
	puts("ERROR. PUT AGAIN.");
    }

 while(1){
    switch (mode){
        case 0:puts("Enter in the form of xdy");
               scanf("%*c%d %c %d",&x,&d,&y);
               break;
        case 1:puts("Set the critical number");
               scanf("%d",&cn);
               printf("critical number is ... %d\n",cn);
               puts("Enter in the form of xd");
               scanf("%*c%d %c",&x,&d);
               y = 10;
               break;
    }

    printf("Roll %d %d-sided dice\n",x,y);
    printf("Roll is ... %d\n",roll(x,y,mode,cn));
 }
 return 0;
}
