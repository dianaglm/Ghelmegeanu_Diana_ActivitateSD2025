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
typedef struct Gradinita Gradinita;

void adaugaUnitate(struct Gradinita** gr, int* nr, struct Gradinita gradinitaNoua)
{
	struct Gradinita* aux = (struct Gradinita*)malloc(sizeof(gradinitaNoua) * ((*nr) + 1));
	for (int i = 0; i < *nr; i++) {
		aux[i] = (*gr)[i];
	}
	aux[(*nr)] = gradinitaNoua;
	free(*gr);
	(*gr) = aux;
	(*nr)++;
}

struct Gradinita citire(Gradinita* unitati, int* nr)
{
	Gradinita gradinita;
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
	adaugaUnitate(unitati,nr,gradinita);
	return gradinita;
}

void afisare(struct Gradinita g) {
	printf("\nID: %d\n", g.id);
	printf("Denumirea: %s\n", g.denumire);
	printf("Numarul de elevi: %d\n", g.nrElevi);
	printf("Directorul este: %s\n", g.numeDirector);
	printf("Fonduri accesate: %f \n", g.fonduri);
}

void afisareVectorUnitati(Gradinita* gr, int nr) {
	for (int i = 0; i < nr; i++) {
		afisare(gr[i]);
	}
}

// Realizati o functie care calculeaza ceva pentru un obiect de tipul implementat de voi.
// (o medie sau o suma, un maxim, un minim...sau orice altceva)


//Realizati o functie care modifica pentru un obiect primit ca parametru, un anumit camp.
//noua valoare este primita ca parametru.

int main()
{
	int nr = 0;
	struct Gradinita* unitati = NULL;
	struct Gradinita unitate = citire(unitati,nr);
	afisareVectorUnitati(unitati, nr);
	return 0;
}