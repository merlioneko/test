#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define VIRSION "0.0.1"

int roll(int d_sd, int d_num){

 int num,sum;
 sum = 0;
 for(int i = 0; i < d_num; i++){
    num = (rand() % d_sd) + 1;
    sum += num;
 }
 return sum;
}

struct CHR{
 int num;
 int STR; int CON; int SIZ;
 int DEX; int APP; int POW;
 int INT; int EDU;
 int HP; int MP; int SAN;
 int LUCK; int IDE; int KNW;
 int JOBP; int HOBP;
 int HG; int SM; int SG; int MG; int LI;
 int FB[2][8];   //[0][] ... 技能番号 [1][] .... 数値
};

//flg初期化用
void flgclear(int flg[], int skn){
 for(int i = 0; i < skn; i++){
    flg[i] = 0;
 }
}

int main(void){

 printf("////////////////////\n\n全自動CoCキャラシート作成機\n");
 printf("ver.%s\n\n",VIRSION);
 printf("///////////////////\n\n");
 srand((unsigned int)time(NULL));

 while(1){

   int skn = 58, point, pts;
   int flg[skn], flg2;
   int n;

//message
   printf("How many people(s) do you want? ... ");
   scanf("%d",&n);
   printf("Creat %d people(s).\n\n", n);
   printf("////-----------------////\n\n");
   for(int i = 0; i < n; i++){

     struct CHR chr[n];
     flgclear(flg,skn);

     chr[i].num = i + 1;
     chr[i].STR = roll(6,3);
     chr[i].CON = roll(6,3);
     chr[i].SIZ = roll(6,2) + 6; 
     chr[i].DEX = roll(6,3);
     chr[i].APP = roll(6,3);
     chr[i].POW = roll(6,3);
     chr[i].INT = roll(2,6) + 6;
     chr[i].EDU = roll(3,6) + 3;
     chr[i].HP = (chr[i].CON + chr[i].SIZ + 1) / 2;
     chr[i].MP = chr[i].POW;
     chr[i].SAN = chr[i].POW * 5;
     chr[i].LUCK = chr[i].POW * 5;
     chr[i].IDE = chr[i].INT * 5;
     chr[i].KNW = chr[i].EDU * 5;
     chr[i].JOBP = chr[i].EDU * 20;
     chr[i].HOBP = chr[i].INT * 10;

     char slist[][32] = {

"言いくるめ"	,"経理"			,"生物学"	,"値切り"	,"拳銃",
"医学" 		,"考古学"		,"説得" 	,"博物学" 	,"サブマシンガン",
"運転"		,"コンピューター"	,"操縦"		,"物理学" 	,"ショットガン",
"応急手当"	,"忍び歩き"		,"法律" 	,"変装"		,"マシンガン",
"オカルト"	,"写真術"		,"地質学"	,"ナビゲート"	,"ライフル",
"回避"		,"重機械操作"		,"跳躍"		,"歴史"		,"キック",
"化学"		,"乗馬"			,"追跡"		,"母国語"	,"組みつき",
"鍵開け"	,"信用"			,"電気修理"	,"マーシャルアーツ","こぶし",
"隠す"		,"心理学"		,"電気工学"	,"目星"		,"頭突き",
"隠れる"	,"人類学"		,"天文学"	,"薬学",
"機械修理"	,"水泳"			,"投擲",
"聞き耳"	,"製作"			,"登攀",
"芸術"		,"精神分析"		,"図書館"

};

     int slist2[] = {

5	,10		,1		,5		,20,
5	,1		,15		,10		,15,
20	,1		,1		,1		,30,
30	,10		,5		,1		,15,
5	,10		,1		,10		,25,
chr[i].DEX*2	,1		,25		,20		,25,
1	,5		,10		,chr[i].EDU*5		,25,
1	,15		,10		,1		,50,
15	,5		,1		,25		,10,
10	,1		,1		,1,
20	,25		,25,
25	,5		,40,
5	,1		,25

};

     for(int j = 0; j < 8; j++){
        flg2 = 0;
        while(flg2 == 0){
           chr[i].FB[0][j] = rand() % skn;
           if( flg[ chr[i].FB[0][j] ] == 0){
             flg[ chr[i].FB[0][j] ]++;
             chr[i].FB[1][j] = slist2[ chr[i].FB[0][j] ];
             flg2++;
           }
        }
     }

     point = chr[i].HOBP + chr[i].JOBP;
     while(point > 0){
        pts = rand() % 8;
        if(chr[i].FB[1][pts] < 99){
           chr[i].FB[1][pts] ++;
           point --;
        }
     }

     if(i > 0 && i < n){
        puts("---------***--------");
        }
     printf("number %d\n",chr[i].num);
     printf("STR %d	CON %d	SIZ %d\n",chr[i].STR, chr[i].CON, chr[i].SIZ);
     printf("DEX %d	APP %d	POW %d\n",chr[i].DEX, chr[i].APP, chr[i].POW);
     printf("INT %d	EDU %d\n",chr[i].INT, chr[i].EDU);
     printf("HP %d	MP %d	SAN %d\n",chr[i].HP, chr[i].MP, chr[i].SAN);
     printf("幸運 %d   アイデア %d   知識 %d\n",chr[i].LUCK, chr[i].IDE, chr[i].KNW);
     printf("趣味ポイント %d	職業ポイント %d\n",chr[i].HOBP, chr[i].JOBP);
     puts("技能一覧");
     for(int j = 0; j < 8; j++){
        printf("	%s：%d(%d)\n",slist[ chr[i].FB[0][j] ], chr[i].FB[1][j], slist2[chr[i].FB[0][j]]);
     }
     puts(" ");
  }

  printf("////-----------------////\n\n\n");
}
 return 0;
}
