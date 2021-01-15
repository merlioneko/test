#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define PI 3.1415926535f

int r_calc(double place_x, double place_y){
 puts("start r_clc");
 if(sqrt(pow(place_x,2) + pow(place_y,2)) <= 100){
	return 1;
 }else{
	return 0;
 }
}

 double plc_xy(int N){

     double place_x,place_y,X;

     puts("start plc_xy");
     for(int i = 0; i < N; i++){
	printf("%d\n",i);
	puts("calc place_x");
    	place_x = rand() % 101;
	puts("calc place_y");
	place_y = rand() % 101;
	puts("calc place ave");
	X += r_calc(place_x, place_y);
	printf("%f\n",X);
 }

 return (4 * X / N);
}

int main(void){
 int N = 1;
 int i,j;
 double place_x, place_y;
 double ave,error;
 double max = 120, min = 80;

 srand((unsigned int)time(NULL));
 puts("start");
 printf("%d\n",N);

 do{
    puts("set");
    double ans_s[N];
    error = 0;
    ave = 0;

    puts("calc ave");
    for(j = 0; j < 10; j++){
	ans_s[j] = plc_xy(N);
	ave += ans_s[j];
   }
    puts("calc ave 2");
    ave /= 10;


    puts("calc error");
    for(j = 0; j < 10; j++){
   	error += pow(ans_s[j] - ave,2);
    }

    puts("calc error 2");
    error /= 10;
    printf("[N = %d]	answer ... %f	pie ... %f	error ... %f\n", N, ave, PI, error);

    N *= 10;

 }while(!((error <= max) && (error >= min)));


 return 0;
}
