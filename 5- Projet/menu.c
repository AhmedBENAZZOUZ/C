#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

int getChoice()
{
    int choice;
    while (1)
    {
        printf("* >> Tapez votre Choix :\t\t\t\t\t\t\t* ");
        if (scanf("%d", &choice) == 1)
        {
            getchar();
            return choice;
        }
        else
        {
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            while (getchar() != '\n')
                ;
        }
    }
}

int Menu()
{
    int choice;
    while (1)
    {
        printf("* Veuillez Choisir une option :\t\t\t\t\t\t\t*\n");
        printf("*  0- Quitter\t\t\t\t\t\t\t\t\t*\n");
        printf("*  1- Gestion du Stock\t\t\t\t\t\t\t\t*\n");
        printf("*  2- Vente et Statistiques\t\t\t\t\t\t\t*\n");
        choice = getChoice();
        switch (choice)
        {
        case 0:
            printf("* ----------------------------------------------------------------------------- *\n");
            printf("* -----------------      Au revoir!  ------------------------------------------ *\n");
            printf("* ----------------------------------------------------------------------------- *\n");
            exit(0);
            break;
        case 1:
            gestionStock();
            break;
        case 2:
            VenteStatistiques();
            break;

        default:
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            break;
        }
    }
}

void gestionStock()
{
    int choice;
    while (1)
    {
        printf("*  Menu Gestion du Stock\t\t\t\t\t\t\t*\n");
        printf("*  0- Menu Principale\t\t\t\t\t\t\t\t*\n");
        printf("*  1- Gestion des Categories\t\t\t\t\t\t\t*\n");
        printf("*  2- Gestion des Types\t\t\t\t\t\t\t\t*\n");
        printf("*  3- Gestion des Produits\t\t\t\t\t\t\t*\n");
        printf("*  4- Affichage du Stock\t\t\t\t\t\t\t*\n");
        choice = getChoice();
        switch (choice)
        {
        case 0:
            Menu();
            break;
        case 1:
            gestionCategories();
            break;
        case 2:
            gestionTypes();
            break;
        case 3:
            gestionProduits();
            break;
        case 4:
            affichageStock();
            gestionStock();
            break;
        default:
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            break;
        }
    }
}

void gestionCategories()
{
    for (int i = 0; i < NbCat; i++)
    {
        printf("%d\t", TabCat[i].idCat);
        printf("%s\n", TabCat[i].NomCat);
    }
    printf("%d\n", NbCat);
    int choice;
    while (1)
    {
        printf("*  Gestion du Stock/Gestion des Categories\t\t\t\t\t*\n");
        printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
        printf("*  1- Retour au Menu Gestion du Stock\t\t\t\t\t\t*\n");
        printf("*  2- Ajout d'une nouvelle Categorie\t\t\t\t\t\t*\n");
        printf("*  3- Suppression d'une Categorie\t\t\t\t\t\t*\n");
        choice = getChoice();
        switch (choice)
        {
        case 0:
            Menu();
            break;
        case 1:
            gestionStock();
            break;
        case 2:
            ajoutCat();
            gestionCategories();
            break;
        case 3:
            suppCat();
            // printf("* Appuyez sur Entree pour revenir au menu de gestion des categories ...\t\t*");
            // while (getchar() != '\n')
            //     ;
            gestionCategories();
            break;

        default:
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            break;
        }
    }
}

void gestionTypes()
{
    for (int i = 0; i < NbTyp; i++)
    {
        printf("%d\t", TabType[i].idType);
        printf("%s\t", TabType[i].NomType);
        printf("%d\t", TabType[i].Cat.idCat);
        printf("%s\n", TabType[i].Cat.NomCat);
    }
    printf("%d\n", NbTyp);
    int choice;
    while (1)
    {
        printf("*  Gestion du Stock/Gestion des Types\t\t\t\t\t\t*\n");
        printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
        printf("*  1- Retour au Menu Gestion du Stock\t\t\t\t\t\t*\n");
        printf("*  2- Ajout d'un nouveau Type\t\t\t\t\t\t\t*\n");
        printf("*  3- Suppression d'un Type\t\t\t\t\t\t\t*\n");
        choice = getChoice();
        switch (choice)
        {
        case 0:
            Menu();
            break;
        case 1:
            gestionStock();
            break;
        case 2:
            ajoutType();
            gestionTypes();
            break;
        case 3:
            suppType();
            gestionTypes();
            break;

        default:
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            break;
        }
    }
}

void gestionProduits()
{
    int maxQte = 0;
    for (int i = 0; i < NbTyp; i++)
    {
        printf(" %2d | ", TabQte[i]);
        if (TabQte[i] > maxQte)
        {
            maxQte = TabQte[i];
        }
    }
    printf("\n");
    // for (int i = 0; i < NbTyp; i++)
    // {
    //     printf("\n");
    //     for (int j = 0; j < TabQte[i]; j++)
    //     {
    //         printf("%2d | ", Stock[j][i].id);
    //         printf("%s                       \n", Stock[j][i].Nom);
    //     }
    // }
    for (int j = 0; j < maxQte; ++j)
    {
        for (int i = 0; i < NbTyp; ++i)
        {
            if (j < TabQte[i])
            {
                printf("%2d | %-15s\t", Stock[j][i].id, Stock[j][i].Nom);
            }
            else
            {
                printf("%-24s",""); // Adjust spaces if needed
            }
        }
        printf("\n");
    }
    printf("\n");
    int choice;
    while (1)
    {
        printf("*  Gestion du Stock/Gestion des Produits\t\t\t\t\t*\n");
        printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
        printf("*  1- Retour au Menu Gestion du Stock\t\t\t\t\t\t*\n");
        printf("*  2- Ajout d'un nouveau Produit\t\t\t\t\t\t*\n");
        printf("*  3- Suppression d'un Produit\t\t\t\t\t\t\t*\n");
        choice = getChoice();
        switch (choice)
        {
        case 0:
            Menu();
            break;
        case 1:
            gestionStock();
            break;
        case 2:
            ajoutPdt();
            gestionProduits();
            break;
        case 3:
            suppPdt();
            gestionProduits();
            break;

        default:
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
            printf("*\t\t\t\t\t\t\t\t\t\t*\n");
            break;
        }
    }
}
void affichageStock()
{
    affichStock();
    printf("* Appuyez sur Entree pour revenir au menu de gestion du Stock ...\t\t*");
    while (getchar() != '\n')
        ;
    gestionStock();
    // while (1)
    // {
    //     printf("*  Gestion du Stock/Affichage du Stock\t\t\t\t*\n");
    //     printf("*  0- Retour au Menu Principale\t\t\t\t\t*\n");
    //     printf("*  1- Retour au Menu Gestion du Stock\t\t\t\t*\n");
    //     choice = getChoice();
    //     switch (choice)
    //     {
    //     case 0:
    //         Menu();
    //         break;
    //     case 1:
    //         gestionStock();
    //         break;
    //     default:
    //                     printf("*\t\t\t\t\t\t\t\t\t\t*\n");
    // printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
    // printf("*\t\t\t\t\t\t\t\t\t\t*\n");
    //         break;
    //     }
    // }
}
void VenteStatistiques()
{
    int choice;
    printf("*  Vente et Statistiques\t\t\t\t\t\t\t*\n");
    printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
    printf("*  1- Vente de Produits\t\t\t\t\t\t\t\t*\n");
    printf("*  2- Statistiques\t\t\t\t\t\t\t\t*\n");
    choice = getChoice();
    switch (choice)
    {
    case 0:
        Menu();
        break;
    case 1:
        venteProduits();
        break;
    case 2:
        Statistiques();
        break;

    default:
        printf("*\t\t\t\t\t\t\t\t\t\t*\n");
        printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t\t\t*\n");
        break;
    }
}
void venteProduits()
{
    int choice;
    printf("*  Vente et Statistiques/Vente de Produits\t\t\t\t\t*\n");
    printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
    printf("*  1- Retour au Menu Vente et Statistiques\t\t\t\t\t*\n");
    printf("*  2- Vendre un Produit\t\t\t\t\t\t\t\t*\n");
    choice = getChoice();
    switch (choice)
    {
    case 0:
        Menu();
        break;
    case 1:
        VenteStatistiques();
        break;
    case 2:
        VendrePdt();
        venteProduits();
        break;

    default:
        printf("*\t\t\t\t\t\t\t\t\t\t*\n");
        printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t\t\t*\n");
        break;
    }
}
void Statistiques()
{
    int choice;
    printf("*  Vente et Statistiques/Statistiques\t\t\t\t\t\t*\n");
    printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
    printf("*  1- Retour au Menu Vente et Statistiques\t\t\t\t\t*\n");
    printf("*  2- Statistiques Par Mois\t\t\t\t\t\t\t*\n");
    printf("*  3- Statistiques Par Annee\t\t\t\t\t\t\t*\n");
    choice = getChoice();
    switch (choice)
    {
    case 0:
        Menu();
        break;
    case 1:
        VenteStatistiques();
        break;
    case 2:
        StatistiquesMois();
        break;
    case 3:
        StatistiquesAnnee();
        break;

    default:
        printf("*\t\t\t\t\t\t\t\t\t\t*\n");
        printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t\t\t*\n");
        break;
    }
}
void StatistiquesMois()
{
    StatMois();
    printf("* Appuyez sur Entree pour revenir au menu du statistiques ...\t\t\t*");
    while (getchar() != '\n')
        ;
    getchar();
    Statistiques();

    // int choice;
    // printf("*  Vente et Statistiques/Statistiques par Mois\t\t\t\t\t*\n");
    // printf("*  0- Retour au Menu Principale\t\t\t\t\t\t\t*\n");
    // printf("*  1- Retour au Menu Statistiques\t\t\t\t\t\t*\n");
    // printf("*  2- Statistiques du mois\t\t\t\t\t\t\t*\n");
    // choice = getChoice();
    // switch (choice)
    // {
    // case 0:
    //     Menu();
    //     break;
    // case 1:
    //     Statistiques();
    //     break;
    // case 2:
    //     StatMois();
    //     StatistiquesMois();
    //     break;
    // default:
    //     printf("*\t\t\t\t\t\t\t\t\t\t*\n");
    //     printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
    //     printf("*\t\t\t\t\t\t\t\t\t\t*\n");
    //     break;
    // }
}
void StatistiquesAnnee()
{
    StatAnnee();
    printf("* Appuyez sur Entree pour revenir au menu du statistiques ...\t\t\t*");
    while (getchar() != '\n')
        ;
    getchar();
    Statistiques();
    // int choice;
    // printf("*  Vente et Statistiques/Statistiques par Annee     *\n");
    // printf("*  0- Retour au Menu Principale                     *\n");
    // printf("*  1- Retour au Menu Statistiques                   *\n");
    // printf("*  2 -        Statistiques  annee                   *\n");
    // choice = getChoice();
    // switch (choice)
    // {
    // case 0:
    //     Menu();
    //     break;
    // case 1:
    //     Statistiques();
    //     break;
    // case 2:
    //     StatAnnee();
    //     StatistiquesAnnee();
    //     break;
    // default:
    //     printf("*\t\t\t\t\t\t\t\t\t\t*\n");
    //     printf("* Choix invalide. Veuillez entrer un nombre entier.\t\t\t\t*\n");
    //     printf("*\t\t\t\t\t\t\t\t\t\t*\n");
    //     break;
    // }
}