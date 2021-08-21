#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void setting(int x,int person, int count,char *address, char *filename, char *str){
 int names[3];
 names[0] = x / 100;//3桁目
 names[1] =(x % 100) / 10;//2桁目
 names[2] =x % 10;//1桁目
 
 sprintf(address,"city0%d%d",person,count);
 sprintf(filename,"%d%d%d",names[0],names[1],names[2]);
 sprintf(str,"%s/%s_%s.txt",address,address,filename);
}

int sfr(FILE *temp, char sute[][128]){
 int frame;
 for(int i = 0; i < 3; i++){
    fgets(sute[i],32,temp);
 }
 sscanf(sute[2],"%d",&frame);
 return frame;
}

void input(FILE *temp, int frame, char sute[][128], double data[][15]){
 for(int i = 0; i < 3; i++){
   printf("%s",sute[i]);
 }
 printf("frame = %d\n",frame);
 for(int i = 0; i < frame; i++){
   for(int j = 0; j < 15; j++){
      fscanf(temp,"%lf",&(data[i][j]));
   }
 }
}

double dnode(int i, int j, int frame1, int frame2, double data1[][15], double data2[][15]){
 double ans = 0;
 for(int n = 0; n < 15; n++){
    ans += pow(data1[i][n] - data2[j][n], 2);
 }
 ans = sqrt(ans);
 return ans;
}

double min(int i, int j, int frame1, int frame2, double g[][j], double d[][j]){
 double ans[3] = {g[i][j-1] + d[i][j],
                  g[i-1][j-1] + 2 * d[i][j],
                  g[i-1][j] + d[i][j]
                 };
 double minval = ans[2];
 if(minval > ans[0]) minval = ans[0];
 if(minval > ans[1]) minval = ans[1];
 return minval;
}

int main(){

 int frame1, frame2, number[2], person, count, names[3];
 FILE *temp,*ent,*logs;
 char str[100],str2[100],address[7],filename[3];
 char sute[3][128];
 double T[100];

    int tmpn = 1;
 for(person = 1; person < 3; person++){
    count = 1;
    setting(tmpn,person,count,address,filename,str);//テンプレート作成
    temp = fopen(str,"r");
    puts("----------------------");
    if(temp == NULL){
       puts("TEMPLATE FILE OPEN ERROR!");
       return -1;
    }
    frame1 = sfr(temp,sute);
    double data1[frame1][15];
    puts("Template File loading");
    input(temp,frame1,sute,data1);
    printf("Template file loading clear ... %s\n",str);
    puts("");
    fclose(temp);

    sprintf(str,"log%d.txt",person);
    logs = fopen(str,"w");
    if(logs == NULL){
       puts("LOG FILE OPEN ERROR!");
       return -1;
    }
    for(int x = 1; x < 101; x++){
       count = 2;
       setting(x,person,count,address,filename,str);//サンプル作成
       ent = fopen(str,"r");
       if(ent == NULL){
          puts("SAMPLE FILE OPEN ERROR!");
          return -1;
       }
       frame2 = sfr(ent,sute);
       double data2[frame2][15];
       puts("Sample file loading");
       input(ent,frame2,sute,data2);
       printf("Sample file loading clear ... %s\n",str);
       puts("----------------------\n");
       fclose(ent);
       double g[frame1][frame2], d[frame1][frame2];
 
       for(int i = 0; i < frame1; i++){
          for(int j = 0; j < frame2; j++){
              d[i][j] = dnode(i,j,frame1,frame2,data1,data2);
          }
       }
       g[0][0] = d[0][0];
       for(int i = 1; i < frame1; i++){
          g[i][0] = g[i-1][0] + d[i][0];
       }
       for(int j = 1; j < frame1; j++){
          g[0][j] = g[0][j-1] + d[0][j];
       }
       for(int i = 1; i < frame1; i++){
          for(int j = 1; j < frame2; j++){
              g[i][j] = min(i,j,frame1,frame2,g,d);
          }
       }
       T[x] = g[(frame1-1)][(frame2-1)] / (frame1 + frame2);
       fprintf(logs,"[%d]T ... %lf\n",x,T[x]);
    }
    fclose(logs);
 }
// }

 return 0;
}
