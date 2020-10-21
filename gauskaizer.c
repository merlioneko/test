#include<stdio.h>

void rekkyo(int x,int y,double num1[][x], double *ans){
 printf("\n/////////////////////////////////////\n\n");
 printf("matlix\n");
 for(int i = 0; i < x; i++){
	for(int j = 0; j < y; j++){
		 printf("	%g ",num1[i][j]);
	}
	printf("\n");
	}
 printf("\n/////////////////////////////////////\n\n");
 printf("answer matlix\n");
 for(int i = 0; i < x; i++){
		 printf("	%g\n",ans[i]);
	}
 printf("\n/////////////////////////////////////\n\n");
}


double get_x1(double x2,double x3){

return ((10.0 - x2 - x3) / 5.0);

}

double get_x2(double x1,double x3){

return ((12.0 - x1 - x3) / 4.0);

}

double get_x3(double x1,double x2){

return ((13.0 - 2 * x1 - x2) / 3.0);

}


int main(){
 double a[3][3] = {{5,1,1},{1,4,1},{2,1,3}};
 double ans[3] = {10,12,13};
 double x1,x2,x3,x01 = 0,x02 = 0,x03 = 0;
 double min = 0.99999999999, max = 1.00000000001;
 int in = 0,okx1 = 0,okx2 = 0,okx3 = 0,ok = 0;
 int i,j;

 x1 = x2 = x3 = 1.0;	//initial values

 rekkyo(3,3,a,ans);

 while(ok == 0){

  x1 = get_x1(x2,x3);
  x2 = get_x2(x1,x2);
  x3 = get_x3(x1,x2);
  printf("[in = %d] x1 = %.10f, x2 = %.10f, x3 = %.10f\n",in,x1,x2,x3);
  if(x1 >= min * x01 && x1<= max * x01){
   okx1++;
  }
  if(x2 >= min * x02 && x2<= max * x02){
   okx2++;
  }
  if(x3 >= min * x03 && x3<= max * x03){
   okx3++;
  }
  if(okx1 == okx2 == okx3 == 1){
   ok++;
  }else{
    okx1 = okx2 = okx3 = 0;
}
 x01 = x1;
 x02 = x2;
 x03 = x3;

 in++;
}
return 0;
}
