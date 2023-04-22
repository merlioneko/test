#include<stdio.h>
#include<math.h>

int main(){
 int birthnum = 20000810;
 int birtharray[] = {2,0,0,0,0,8,1,0};
 double K = birthnum / 10000000;
 double a = 1.0;
 double v = a, t, S;
 int second;

 printf("K = %0.1lf\n",K);
 t = 3.2;
 second = t;

 for(int i = 0; i < second; i++){//v = a*K^t
    v *= K;
 }
 printf("%lf second later ... speed ... %g\n ", t, v);

 //S=∫[0,3.2]a*k^sds = [(a*k^(s+1))/(s+1)][0,3.2]

 S = a * pow(K, t+1) / (t+1) - a * K;
 
 printf("%g second later ...distance  ... %0.2lf\n ", t, S);

 return 0;
}
