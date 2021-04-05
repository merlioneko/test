#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void roll(int pttn){

  char lts[6][256];

  if(pttn == 0){
    char lts[][256] = {
    "22口径ショート・オートマチック",
    "30-06口径セミオート・ライフル",
    "20ゲージ・二連式ショットガン",
    "AK47",
    "手榴弾",
    "催涙ガス"
   };
  }else if(pttn == 1){
    char lts[][256] = {
    "治療薬（小）",
    "精神安定剤（小）",
    "火傷治療薬",
    "弾薬 x 10",
    "厚皮ジャケット",
    "防弾ヘルメット"
   };
  }else if(pttn == 2){
    char lts[][256] = {
    "IMIデザート・イーグル",
    "444口径マリーン・ライフル",
    "12ゲージ・ポンプショットガン",
    "M16A2",
    "イングラムMAC11",
    "ブローニング・オートライフルM1918"
    };
  }else if(pttn == 3){
    char lts[][256] = {
    "治療薬（大）",
    "精神安定剤（大）",
    "幻覚剤",
    "魔水晶",
    "防弾ベスト",
    "バイオ装甲"
    };
  }
  printf("%s\n",lts[ rand() % 6]);
}

//flg初期化用
void flgclear(int flg[], int skn){
 for(int i = 0; i < skn; i++){
    flg[i] = 0;
 }
}

int main(void){

 int rnd,num;
 int lp;

 while(1){

 puts("put the luck point");
 scanf("%d",&lp);

 srand((unsigned int)time(NULL));
 rnd = rand() % 100;

 if(rnd > lp){
          num = 3;
          puts("<COMMON BOX>");
 }else if(rnd < lp){
          num = 5;
          puts("<RERA BOX>");
 }

 for(int i = 0; i < num; i++){
  rnd = rand() % 100;
  if(rnd < lp){
     switch(rand() % 2){ // 0 ... arms 1 ... items
       case 0:roll(0);break;
       case 1:roll(1);break;
     }
   }else if(rnd > lp){
     switch(rand() % 2){
       case 0:roll(2);break;
       case 1:roll(3);break;
    }
   }
  }
 puts("----------------");
 }


 return 0;
}
