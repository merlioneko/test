#include<stdio.h>
#include<math.h>

int main(){
 FILE *fp,*fp2,*fp3;
 int N;
 int Nmax = 10000 + 1;

 fp = fopen("SD_data.txt","w");
 fp2 = fopen("Ave_date.txt","w");
 fp3 = fopen("Vr_date.txt","w");
 if(fp == NULL){
    puts("ERROR. Can't create \"ND_data.txt\"");
    fclose(fp);
    return -1;
 }
 if(fp2 == NULL){
    puts("ERROR. Can't create \"Ave_data.txt\"");
    fclose(fp2);
    return -1;
 }
 if(fp3 == NULL){
    puts("ERROR. Can't create \"Vr_data.txt\"");
    fclose(fp3);
    return -1;
 }

 for(N = 1; N < Nmax; N++){

    double num[N];
    double ave = 0, vr = 0, sd = 0, sd2 = 0;

    num[0] = 100;

    for(int i = 1; i < N; i++){
       num[i] = 0;
    }

//average
    ave = 100 / N;
    fprintf(fp2,"%d,%f\n",N, ave);

//variance
    for(int i = 0; i < N; i++){
      vr += pow((num[i] - ave),2);
    }
    vr /= N;
    fprintf(fp3,"%d,%f\n",N, vr);
//standard devition
    sd = sqrt(vr);

    sd2 = 50 + (10 * (100 - ave)) / sd;

    fprintf(fp,"%d,%f\n", N, sd2);
   }
 fclose(fp);
 fclose(fp2);
 fclose(fp3);

 return 0;

}
