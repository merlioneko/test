#include<stdio.h>
#include<math.h>

void numclear(int *array, int len){

 for(int i = 0; i < len; i++){
   array[i] = 0;
 }

}

int pownum(int *numarray, int digit){

 int cash_digit = digit;
 int num,k,head;
 int count = 1, len = 64;
 int sample_array[len];

 numclear(sample_array, len);

 for(int i = 0; i < digit; i++){
   sample_array[i + len - digit] = numarray[i];
   printf("%d", sample_array[i + len - digit]);
 }
 puts("");

   while(count < 6){
   count++;
//cashの設定・クリア
    cash_digit += digit;
    head = len - cash_digit + digit;
    int cash[cash_digit - digit][cash_digit];
    for(int i = 0; i < cash_digit - digit; i++){
        for(int j = 0; j < cash_digit; j++){
           cash[i][j] = 0;
           printf("%d ",cash[i][j]);
        }
        puts("");
    }
  puts("clear cash");


//前部計算部
    for(int i = 0; i < digit; i++){//かける桁を右から左にずらしていく
       num = numarray[i];
       printf("num ... %d\n", num);

       for(int j = 0 ; j < cash_digit - digit; j++){
          k = j + i + 1;
          cash[i][k] = sample_array[j + head] * num;//一旦ぶち込む
          printf("cash[%d][%d] = %d * %d\n",i,k,sample_array[j+head],num);
       }

    }

    puts("//-------------****----------------------------------------------------");
    printf("//  digit = %d, cach_digit = %d\n",digit,cash_digit);
    for(int i = 0; i < digit; i++){
      printf("[i%d]",i);
      for(int j = 0; j < cash_digit; j++){
        printf("	%d|",cash[i][j]);
      }
      puts("");
    }
//各計算の合計
    for(int j = cash_digit - 1; j > -1; j--){
      for(int i = 1; i < digit; i++){
        cash[0][j] += cash[i][j];
      }
      if(cash[0][j] >= 10){
        cash[0][j-1] += cash[0][j] / 10;
        cash[0][j] %= 10;
      }
   }

   puts("//-------------****----------------------------------------------------");
   for(int j = 0; j < cash_digit; j++){
      printf("	[%d]",cash[0][j]);
   }
   puts("");

 for(int i = 0; i < cash_digit; i++){
      sample_array[len - 1 - i] = cash[0][cash_digit - 1 - i];
 }
 for(int i = 0; i < len; i++){
    printf("%d",sample_array[i]);
 }
 puts("");
 }

 for(int i = 1; i < len; i++){
    sample_array[0] += sample_array[i];
 }

 return sample_array[0];
}

int main(){

 int num = 20000810;
 double dbnum = num;
 int numdigit = log10(dbnum) + 1;
 int numarray[] = {2,0,0,0,0,8,1,0};
 int ansdigit;

 puts("START");
 printf("answer is ... %d\n",pownum(numarray,numdigit));


return 0;
}
