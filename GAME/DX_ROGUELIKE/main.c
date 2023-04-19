#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void title(double version){
	printf("	//////////////////////////////////\n");
	printf("	////////////Doble Cross///////////\n");
	printf("	////////ROGUE-LIKE ADVENTURE//////\n");
	printf("	//////// version ... %g ///////////\n", version);
	printf("	//////////////////////////////////\n");
	
}

/*
 sex : 0 ... male 1 ... female
syndrome :{
	0 : NO SYNDROME
	1 : ANGEL HALO
	2 : BAROL
	3 : BLACK DOG
	4 : BRAM STOKER
	5 : CHIMAERA}
	6 : EXILE}
	7 : HANUMAN}
	8 : MORPHEUS}
	9 : NEUMAN}
	10: ORCUS}
	11: SALAMANDRA}
	12: SOLARIS
	64: NO EFFECT
	}
 */

struct STATUS{
	char *name;
	int sex;
	int LV;
	int SYND[3];
	int PHYS; int SENS; int MENT; int SCIE;
	int MEL; int EVD; int DRV[3];
	int SHT; int FEL; int ART[3];
	int RC; int POW; int KNW[3];
	int NGT; int PRC; int INF[3];
	int HP; int MONEY; int MOV;
	int DECK[30];
	
};

struct CARD{
	char card_name[2][256];
};

void ccreate(char *name){
	char ok_name = 'n';
	puts("Create you're character!");
	while(ok_name == 'n'){
		printf("What's your name? ... ");
		scanf("%s",name);
		getchar();
		ok_name = 'a';
		while(ok_name == 'a' ){
			printf("\"%s\"\nOK?(y/n) ...  " , name);
			ok_name = getchar();
			switch(ok_name){
				case 'y': puts("OK!"); break;
				case 'Y': puts("OK!"); break;
				case 'n': puts("Sure"); ok_name = 'n'; break;
				case 'N': puts("Sure"); ok_name = 'n'; break;
				default : puts("Answer y or n!"); ok_name = 'a'; break;
			}
		}
	}

}

int main(){
	char name[64];
	double version = 0.0;
	title(version);
	ccreate(name);	
	printf("%s\n", name);
	return 0;
}
