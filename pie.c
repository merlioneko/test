#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define PI 3.141592f

int r_calc(double place_x, double place_y){
 if(sqrt(pow(place_x,2) + pow(place_y,2)) <= 100){
	return 1;
 }else{
	return 0;
 }
}

double plc_xy(int N){
 double place_x,place_y,X = 0;
 int i;
 for(i = 0; i < N; i++){

    place_x = rand() % 101;

    place_y = rand() % 101;

    X += r_calc(place_x, place_y);
 }
 return (4 * X / N);
}

int main(void){
 int N = 1;
 int i,j;
 int num = 10;
 double place_x, place_y;
 double ave,error;
 double max = 0.0005, min = 0;
 double ans_s[num];

 srand((unsigned int)time(NULL));


 do{

    error = 0;
    ave = 0;

    for(j = 0; j < num; j++){
	ans_s[j] = plc_xy(N);
	ave += ans_s[j];
   }
    ave /= num;

    for(j = 0; j < num; j++){
   	error += pow(ans_s[j] - ave,2);
   }

    error /= num;
    printf("[N = %d]	answer ... %f	pie ... %f	error ... %f\n", N, ave, PI, error);

    N *= 10;

 }while(!((error <= max) && (error >= min)));


 return 0;
}
