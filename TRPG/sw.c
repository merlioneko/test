#include<stdio.h>
#include<string.h>

struct STW{

 int STR; int CON; int SIZ;
 int DEX; int POW;int INT;
 int HP; int MP;

};

void DB_calc(int ,int);
void ABI(int);

int main(){
 int level,flg = 0;
 char str[128],str2[2][1024];
 FILE *fp;
 puts("   ///////////////////////   ");
 puts("     STAR WARRIOR MAKING     ");
 puts("   ///////////////////////   \n\n\n\n\n");

 struct STW STW;

 while(flg == 0){
  puts("------------******------------");
  printf("LEVEL ....");
  scanf("%d",&level);

  switch (level){
     case 1:
           STW.STR = 22;STW.CON = 18;STW.SIZ = 19;flg++;break;
     case 2:
           STW.STR = 30;STW.CON = 24;STW.SIZ = 36;flg++;break;
     case 3:
           STW.STR = 45;STW.CON = 36;STW.SIZ = 54;flg++;break;
     case 4:
           STW.STR = 60;STW.CON = 48;STW.SIZ = 62;flg++;break;
     case 5:
           STW.STR = 70;STW.CON = 52;STW.SIZ = 80;flg++;break;
     default:
           puts("WRONG LEVEL! ENTER 1-5 !\n\n\n\n");break;
  }
}

 sprintf(str,"stawarrior_level%d", level);
 fp = fprintf("str","w");
 STW.DEX = 20; STW.POW = 21; STW.INT = 21;
 STW.HP = (STW.CON + STW.SIZ)/2; STW.MP = STW.POW;
 
 printf("STR %d	CON %d	SIZ %d\n",STW.STR, STW.CON, STW.SIZ);
 printf("DEX %d	POW %d	INT %d\n",STW.DEX, STW.POW, STW.INT);
 printf("HP %d	MP %d	LV.%d\n",STW.HP, STW.MP, level);
 DB_calc(STW.STR,STW.SIZ);
 



 puts("------------******------------");
 fclose(fp);
return 0;
}

void DB_calc(int STR, int SIZ){
 int db = STR+SIZ;

 printf("DB ");
 if(db < 13)
   puts("-1D6");

 if(db >= 13 && db <= 16)
   puts("-1D4");

 if(db >= 17 && db <= 24)
   puts("0");

 if(db >= 25 && db <= 32)
   puts("+1D4");

 if(db >= 33 && db <= 40)
   puts("+1D6");

 if(db >= 41){
   printf("+%dD6\n",(db - 41) / 16 + 2);
 }
}
