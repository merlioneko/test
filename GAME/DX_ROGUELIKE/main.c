#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void title(double version){
	printf("	//////////////////////////////////\n");
	printf("	////////////Doble Cross///////////\n");
	printf("	////////ROGUE-LIKE ADVENTURE//////\n");
	printf("	//////// version ... %g ///////////\n", version);
	printf("	//////////////////////////////////\n");
	
}

int mode = 4; // 4: BASIC 3: ADD RULE 2: ADD CC

/*
 sex : 0 ... male 1 ... female
syndrome :{
	"ANGEL HALO", 
	"BAROL",
	"BLACK DOG",
	"BRAM STOKER",
	"CHIMAERA",
	"EXILE",
	"HANUMAN",
	"MORPHEUS",
	"NEUMAN",
	"ORCUS",
	"SALAMANDRA",
	"SOLARIS",
	"UROBOROS",
	"AZATOTH",
	"NO SYNDROME",
	"NO EFFECT"
	}
 */

char SYNDROME_LIST[][32] = {
	"ANGEL HALO", 
	"BAROL",
	"BLACK DOG",
	"BRAM STOKER",
	"CHIMAERA",
	"EXILE",
	"HANUMAN",
	"MORPHEUS",
	"NEUMAN",
	"ORCUS",
	"SALAMANDRA",
	"SOLARIS",
	"UROBOROS",
	"AZATOTH",
	"NO SYNDROME",
	"NO EFFECT"
};

int syndrome_element = sizeof SYNDROME_LIST / sizeof SYNDROME_LIST[0][0]/32;

struct STATUS{
	char *name;
	int sex;
	int LV;	int SYND[3];
	int PHYS; int SENS; int MENT; int SCIE;
	int MEL; int EVD; int DRV[3];
	int SHT; int FEL; int ART[3];
	int RC; int POW; int KNW[3];
	int NGT; int PRC; int INF[3];
	int HP; int HP_max; int ERS_orgn; int ERS; int MONEY; int MOV;

	int having[2][16];
	int DECK[30];
};

void ccreate(char *name){
	char ok_name = 'n', ok_syndrome = 'n';
	int syndrome;
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
	while(ok_syndrome == 'n'){
		puts("Select your Syndrome ... ");
		for(int j = 0; syndrome_element - mode; j++){
			printf("%s\n", SYNDROME_LIST[j]);
		}
		scanf("%d", &syndrome);
		
	}
}

int main(){
	struct STATUS plyr;
	char *name;
	double version = 0.0;
	title(version);
	ccreate(name);	
	plyr.name = name;
	printf("player name .... %s\n", plyr.name);
	return 0;
}
