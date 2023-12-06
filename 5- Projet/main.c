#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"

int main()
{
    printf("*********************************************************************************\n");
    printf("*******************       Bienvenue  ********************************************\n");
    printf("*********************************************************************************\n");
    initializeArrays();
    Menu();

    // Produit newProduit;

    // InitProduit(&newProduit);

    // printf("Produit ID: %d\n", newProduit.id);
    // printf("Produit Nom: %s\n", newProduit.Nom);
    // printf("Type ID: %d\n", newProduit.Typ.idType);
    // printf("Type Nom: %s\n", newProduit.Typ.NomType);
    // printf("Categorie ID: %d\n", newProduit.Typ.Cat.idCat);
    // printf("Categorie Nom: %s\n", newProduit.Typ.Cat.NomCat);
    // printf("Date d'expiration : %d/%d/%d\n", newProduit.Date_Ex.JJ, newProduit.Date_Ex.MM, newProduit.Date_Ex.AA);

    // printf("Press Enter to close the program...");
    // while (getchar() != '\n')
    //     ;
    // getchar();

    return 0;
}