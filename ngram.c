#include<stdio.h>
#include<string.h>

int main(){

 char str[] = "The_early_bird_catches_the_worm.";
 int num = strlen(str);

 printf("%s\n",str);

 for(int j = 0; j < 3; j++){

    printf("\n////////////\nN = %d\n", j+1);
    for(int i = j; i < num ; i++){
        if(j == 0)
           printf(" \" %c \" ",str[i]);
        if(j == 1)
           printf(" \" %c%c \" ",str[i-1], str[i]);
        if(j == 2)
           printf(" \" %c%c%c \" ",str[i-2],str[i-1],str[i]);
        if(i < (strlen(str) - 1))
           printf(",");
    }
    puts("");
 }
 return 0;
}
