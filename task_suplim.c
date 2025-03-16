#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Gradinita {
	int id;
	char* denumire;
	int nrElevi;
	char* numeDirector;
	float fonduri;
};

//Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul construit de
//voi.Funcția returnează obiectul citit.

struct Gradinita citire()
{
	struct Gradinita gradinita;
	char buffer[100];

	printf("Id: ");
	scanf("%d", &gradinita.id);
	printf("Numele gradinitei: ");
	getchar();
	fgets(buffer,sizeof(buffer),stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	gradinita.denumire = (char*)malloc(strlen(buffer) + 1);  
	strcpy(gradinita.denumire, buffer);
	printf("Numarul de elevi: ");
	scanf("%d", &gradinita.nrElevi);
	printf("Numele directorului: ");
	getchar();
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0'; 
	gradinita.numeDirector = (char*)malloc(strlen(buffer) + 1);  
	strcpy(gradinita.numeDirector, buffer);
	printf("Fonduri accesate (mil EUR): ");
	scanf("%.2f", &gradinita.fonduri);
	return gradinita;
}

void afisare(struct Gradinita g) {
	printf("\nID: %d\n", g.id);
	printf("Denumirea: %s\n", g.denumire);
	printf("Numarul de elevi: %d\n", g.nrElevi);
	printf("Directorul este: %s\n", g.numeDirector);
	printf("Fonduri accesate: %f \n", g.fonduri);
}

int main()
{
	struct Gradinita unitate = citire();
	afisare(unitate);
	return 0;
}