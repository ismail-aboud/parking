#include <stdio.h>
#include <stdlib.h>
#define nbreEtage 2
#define nbreVelo 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void PriseEnCharge(int tab[nbreEtage][nbreVelo]);
void SituationParking(int tab[nbreEtage][nbreVelo]);
void DisponibiliteParEtage(int tab[nbreEtage][nbreVelo], int tabD[nbreEtage]);
void DisponibiliteParPlace(int tab[nbreEtage][nbreVelo], int tabP[nbreVelo]);
int EtageProche(int tabD[nbreEtage]);
int main(int argc, char *argv[]) {
	int parking[nbreEtage][nbreVelo];
	int disponibles[nbreEtage];
	int places[nbreVelo];
	PriseEnCharge(parking);
	SituationParking(parking);
	DisponibiliteParEtage(parking, disponibles);
	
	int i;
	printf("Places disponibles par etage \n");
	for(i=0; i<nbreEtage; i++){
		printf("A l etage: %d, il y a %d places disponibles\n", i+1, disponibles[i]);
	}
	
	DisponibiliteParPlace(parking, places);
	
	printf("Places occupees \n");
	for(i=0; i<nbreVelo; i++){
		printf("La place %d est occupee dans %d etages\n", i+1, places[i]);
	}
	int etage;
	etage=EtageProche(disponibles);
	

	
	return 0;
}

void PriseEnCharge(int tab[nbreEtage][nbreVelo]){
	int i,j;
	printf("Entrez O pr place vide 1 pour occupee \n");
	for(i=0; i<nbreEtage; i++){
		for(j=0; j<nbreVelo; j++){
			printf("Etage: %d place: %d \n", i+1, j+1);
		    scanf("%d", &tab[i][j]);
		}
	}
}

void SituationParking(int tab[nbreEtage][nbreVelo]){
	int i,j;
	int c=0;
    for(i=0; i<nbreEtage; i++){
		for(j=0; j<nbreVelo; j++){
			if(tab[i][j]==0){
				c++;
			}
			}
}

if (c==0) printf("Le parking est complet \n");
else printf("Le parking contient des places vides \n");
}

void DisponibiliteParEtage(int tab[nbreEtage][nbreVelo], int tabD[nbreEtage]){
	int i,j;
	int disponible;
	for(i=0; i<nbreEtage; i++){
		disponible =0;
		for(j=0; j<nbreVelo; j++){
			if(tab[i][j]==0)
			{
			disponible++;
		}
		}
		tabD[i]=disponible;
	}
}

void DisponibiliteParPlace(int tab[nbreEtage][nbreVelo], int tabP[nbreVelo]){
	int i,j;
	int occupee;
	for(j=0; j<nbreVelo; j++){
		occupee =0;
		for(i=0; i<nbreEtage; i++){
			if(tab[i][j]==1){
			occupee++;
		}
		}
		tabP[j]=occupee;
	}
}

int EtageProche(int tabD[nbreEtage]){
	int i, j, pos, etage=0;
	printf("Vous etes dans quel etage \n");
	scanf("%d", &pos);
	printf("tabD[%d]=%d\n", pos-1, tabD[pos-1]);
	if(tabD[pos-1]==0){
		for(i=pos; i<nbreEtage; i++){
			printf("tabD[%d]=%d\n", i, tabD[i]);
			if(tabD[i]!=0){
				etage=(i+1);
				printf("etage : %d \n", etage);
			}
		}
	
	}
	if(etage==0) printf("La parking est totalement plein\n");
	else printf("L etage %d est le plus proche contenant des places libres \n",etage);
	return etage;
	
}
