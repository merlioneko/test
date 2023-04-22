#include<stdio.h>
#define PIE = 3.14
#define G = 9.81
#define D = 0.5

struct space{
 double x = 640;
 double y = 480;
 //右上が(0,0)とする。
};

struct ball{
 int mode;	//下向き…0 上向き…1
 double x, y, v;
 double r = 1;
 double S = r*r*PIE
};

double fallv(double ballv, int mode){
 double v;
 switch(mode){
	 case 0: v = G * t;break;
	 case 1: v = - G * t + ballv;break;
 }
 return v;
}

double fally(double spacey, double bally, double S, int t, int mode){
 double y =  fallv(mode) * t / 2;
 if(spacey < y + bally + S / 2)
	 y = spacey - bally - S / 2;
 return y;
}


int main(){
 int t = 0,flg = 0;
 struct space space;
 struct ball ball;

 ball.x = space.x / 2;
 ball.y = 0;
 ball.v = 0;
 ball.mode = 0;

 while(flg == 0){
   ball.v = fallv(ball.mode);
   ball.y = fally(space.x, ball.y, ball.S, t, ball.mode);
   printf("(x,y) = (%lf,%lf)\n", ball.x, ball.y);
   if(v == 0)flg++;
}

 return 0;
}
