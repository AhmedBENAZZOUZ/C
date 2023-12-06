#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"

// Declaration des variables Globales
Categorie *TabCat = NULL;
Type *TabType = NULL;
Produit **Stock = NULL;
int *TabQte = NULL;
int NbCat = 0;
int NbTyp = 0;

// Initialization des variables Globales et affecter des donnees
void initializeArrays()
{
    TabCat = (Categorie *)malloc(20 * sizeof(Categorie));
    TabType = (Type *)malloc(50 * sizeof(Type));
    Stock = (Produit **)malloc(100 * sizeof(Produit *));
    for (int i = 0; i < 100; i++)
    {
        Stock[i] = (Produit *)malloc(50 * sizeof(Produit));
    }
    TabQte = (int *)malloc(50 * sizeof(int));

    // Donnee Categories
    TabCat[0] = (Categorie){1, "Conserve"};
    TabCat[1] = (Categorie){2, "Boisson"};
    TabCat[2] = (Categorie){3, "Epice"};
    TabCat[3] = (Categorie){4, "Electromenager"};

    NbCat = 4;

    // Donnee Types

    // Ajout des types de la categorie 0
    TabType[0] = (Type){1, "Tomate", TabCat[0]};
    TabType[1] = (Type){2, "Mais", TabCat[0]};

    // // Ajout des types de la categorie 1
    TabType[2] = (Type){3, "Jus", TabCat[1]};
    TabType[3] = (Type){4, "Cafes", TabCat[1]};

    // Ajout des types de la categorie 2
    TabType[4] = (Type){5, "Curcuma", TabCat[2]};

    // Ajout des types de la categorie 3
    TabType[5] = (Type){6, "Refrigerateur", TabCat[3]};
    TabType[6] = (Type){7, "Machine_a_Laver", TabCat[3]};

    NbTyp = 7;

    // Donnee Matrice Produits

    // Ajout des produits du Type 0
    Stock[0][0] = (Produit){1, "Sticap", TabType[0], {25, 12, 2023}};
    Stock[1][0] = (Produit){2, "Sicam", TabType[0], {8, 2, 2024}};
    Stock[2][0] = (Produit){3, "Jouda", TabType[0], {12, 1, 2025}};

    TabQte[0] = 3;

    // Ajout des produits du Type 1
    Stock[0][1] = (Produit){4, "Mais_1", TabType[1], {1, 1, 2028}};
    Stock[1][1] = (Produit){5, "Mais_2", TabType[1], {14, 6, 2027}};

    TabQte[1] = 2;

    // Ajout des produits du Type 2
    Stock[0][2] = (Produit){6, "Tropico", TabType[2], {14, 6, 2026}};
    Stock[1][2] = (Produit){7, "Oh!", TabType[2], {12, 12, 2025}};

    TabQte[2] = 2;

    // Ajout des produits du Type 3
    Stock[0][3] = (Produit){8, "Bondin", TabType[3], {8, 7, 2027}};
    Stock[1][3] = (Produit){9, "Ben_Yedder", TabType[3], {15, 12, 2029}};
    Stock[2][3] = (Produit){10, "Ellouze", TabType[3], {16, 2, 2026}};

    TabQte[3] = 3;

    // Ajout des produits du Type 4
    Stock[0][4] = (Produit){11, "Epika", TabType[4], {4, 3, 2029}};
    Stock[1][4] = (Produit){12, "El_Khabia", TabType[4], {3, 5, 2028}};

    TabQte[4] = 2;

    // Ajout des produits du Type 5
    Stock[0][5] = (Produit){13, "Beko", TabType[5], {14, 8, 2034}};
    Stock[1][5] = (Produit){14, "Whirlpool", TabType[5], {18, 11, 2036}};

    TabQte[5] = 2;

    // Ajout des produits du Type 6
    Stock[0][6] = (Produit){15, "Samsung", TabType[6], {12, 9, 2030}};
    Stock[1][6] = (Produit){16, "LG", TabType[6], {8, 6, 2036}};
    Stock[2][6] = (Produit){17, "Electrolux", TabType[6], {28, 10, 2034}};

    TabQte[6] = 3;
}

// Fonction qui retourne l'annee courante
int getCurrentYear()
{
    time_t now;
    struct tm *timeinfo;
    time(&now);
    timeinfo = localtime(&now);
    return 1900 + timeinfo->tm_year;
}

// Fonction qui retourne le mois courant
int getCurrentMonth()
{
    time_t now;
    struct tm *timeinfo;
    time(&now);
    timeinfo = localtime(&now);
    return 1 + timeinfo->tm_mon;
}

// Fonction qui retourne le numero d'aujourd'hui
int getCurrentDay()
{
    time_t now;
    struct tm *timeinfo;
    time(&now);
    timeinfo = localtime(&now);
    return timeinfo->tm_mday;
}

// Fonction pour verifie si l'année est bissextile (pour fevrier 28 ou 29 jour)
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Initialization du date avec toutes les verifications
void InitDate(MaDate *date)
{
    int currentYear = getCurrentYear();
    int currentMonth = getCurrentMonth();
    int currentDay = getCurrentDay();

    do
    {
        printf("Entrez l'annee : ");
        scanf("%d", &(date->AA));
    } while (date->AA < currentYear);
    if (date->AA == currentYear)
    {
        do
        {
            printf("Entrez le Mois : ");
            scanf("%d", &(date->MM));
        } while ((date->MM < currentMonth || date->MM > 12));
        if (date->MM == 4 || date->MM == 6 || date->MM == 9 || date->MM == 11)
        {
            do
            {
                printf("Entrez le Jour : ");
                scanf("%d", &(date->JJ));
            } while (date->JJ < currentDay + 1 || date->JJ > 30);
        }
        else if (date->MM == 1 || date->MM == 3 || date->MM == 5 || date->MM == 7 || date->MM == 8 || date->MM == 10 || date->MM == 12)
        {
            do
            {
                printf("Entrez le Jour : ");
                scanf("%d", &(date->JJ));
            } while (date->JJ < currentDay + 1 || date->JJ > 31);
        }
        else
        {
            if (isLeapYear(date->AA))
            {
                do
                {
                    printf("Entrez le Jour : ");
                    scanf("%d", &(date->JJ));
                } while (date->JJ < currentDay + 1 || date->JJ > 29);
            }
            else
            {
                do
                {
                    printf("Entrez le Jour : ");
                    scanf("%d", &(date->JJ));
                } while (date->JJ < currentDay + 1 || date->JJ > 28);
            }
        }
    }
    else
    {
        do
        {
            printf("Entrez le Mois : ");
            scanf("%d", &(date->MM));
        } while ((date->MM < 1 || date->MM > 12));
        if (date->MM == 4 || date->MM == 6 || date->MM == 9 || date->MM == 11)
        {
            do
            {
                printf("Entrez le Jour : ");
                scanf("%d", &(date->JJ));
            } while (date->JJ < 1 || date->JJ > 30);
        }
        else if (date->MM == 1 || date->MM == 3 || date->MM == 5 || date->MM == 7 || date->MM == 8 || date->MM == 10 || date->MM == 12)
        {
            do
            {
                printf("Entrez le Jour : ");
                scanf("%d", &(date->JJ));
            } while (date->JJ < 1 || date->JJ > 31);
        }
        else
        {
            if (isLeapYear(date->AA))
            {
                do
                {
                    printf("Entrez le Jour : ");
                    scanf("%d", &(date->JJ));
                } while (date->JJ < 1 || date->JJ > 29);
            }
            else
            {
                do
                {
                    printf("Entrez le Jour : ");
                    scanf("%d", &(date->JJ));
                } while (date->JJ < 1 || date->JJ > 28);
            }
        }
    }
}

void affichCat()
{
    printf("Les Categories : ");
    for (int i = 0; i < NbCat; i++)
    {
        printf("%d\t%s", TabCat[i].idCat, TabCat[i].NomCat);
        if (i != NbCat - 1)
        {
            printf(" | ");
        }
    }
    printf("\n");
}

void affichType()
{
    printf("Les Types : ");
    for (int i = 0; i < NbTyp; i++)
    {
        printf("%d\t%s", TabType[i].idType, TabType[i].NomType);
        if (i != NbTyp - 1)
        {
            printf(" | ");
        }
    }
    printf("\n");
}

// Initialization de la categorie
void InitCat(Categorie *categorie)
{
    printf("Entrez le code d'identification (ID) de la categorie : ");
    scanf("%d", &(categorie->idCat));

    printf("Entrez le nom de la categorie : ");
    scanf("%s", categorie->NomCat);
}

// Initialization du type
void InitType(Type *Type)
{
    if (NbCat <= 0)
    {
        printf("L'ajout d'un type est impossible en l'absence des categories\n");
        return;
    }
    else
    {
        printf("Entrez le code d'identification (ID) du Type : ");
        scanf("%d", &(Type->idType));

        printf("Entrez le nom du Type : ");
        scanf("%s", Type->NomType);

        printf("[Ajout Type] Le choix de la categorie se fait avec L'ID.\n");
        affichCat();
        int choixCat;
        bool CatExists = false, firstIteration = true;
        do
        {
            if (!firstIteration)
            {
                printf("Erreur : Categorie non valide. Veuillez reessayer.\n");
                // If it's not the first iteration, print an error message
            }
            printf("Entrez L'ID de la categorie : ");
            scanf("%d", &choixCat);

            for (int i = 0; i < NbCat; i++)
            {
                if (choixCat == TabCat[i].idCat)
                {
                    Type->Cat.idCat = TabCat[i].idCat;
                    strcpy(Type->Cat.NomCat, TabCat[i].NomCat);
                    CatExists = true;
                    break;
                }
            }
            firstIteration = false;
        } while (!CatExists);
    }
}

// Initialization du produit
void InitProduit(Produit *produit)
{
    if (NbTyp <= 0)
    {
        printf("L'ajout d'un produit est impossible en l'absence des types\n");
        return;
    }
    else
    {
        printf("Entrez le code d'identification (ID) du produit : ");
        scanf("%d", &(produit->id));

        printf("Entrez le nom du produit : ");
        scanf("%s", produit->Nom);

        printf("[Ajout Produit] Le choix du type se fait avec L'ID.\n");
        affichType();

        int choixType;
        bool typeExists = false, firstIteration = true;
        do
        {
            if (!firstIteration)
            {
                printf("Erreur : Type non valide. Veuillez reessayer.\n");
                // If it's not the first iteration, print an error message
            }
            printf("Entrez L'ID du type : ");
            scanf("%d", &choixType);

            for (int i = 0; i < NbTyp; i++)
            {
                if (choixType == TabType[i].idType)
                {
                    produit->Typ.idType = TabType[i].idType;
                    strcpy(produit->Typ.NomType, TabType[i].NomType);
                    typeExists = true;
                    break;
                }
            }
            firstIteration = false;
        } while (!typeExists);
        InitDate(&(produit->Date_Ex));
    }
}

// Fonction qui affiche le stock de la maniere demandé
void affichStock()
{
    printf("*********************************************************************************\n");
    printf("* Etat du stock : ***************************************************************\n");
    printf("*                                                                               *\n");
    printf("* Categorie\t\tType\t\t\tQte\tid-Pdt\tdate_exp\t*\n");
    printf("* ----------------------------------------------------------------------------- *\n");
    int flagPdt = 1;
    int flagType = 1;

    for (int i = 0; i < NbCat; i++)
    {
        bool catfound = false, typefound = false;
        for (int l = 0; l < NbTyp; l++)
        {
            if (TabType[l].Cat.idCat == TabCat[i].idCat)
            {
                catfound = true;
                if (TabQte[l] > 0)
                {
                    typefound = true;
                }
                break;
            }
        }
        if (!catfound || !typefound)
        {
            continue;
        }
        printf("* %-21s ", TabCat[i].NomCat);
        for (int j = 0; j < NbTyp; j++)
        {
            if (TabType[j].Cat.idCat == TabCat[i].idCat)
            {
                if (TabQte[j] <= 0)
                {
                    continue;
                }
                if (flagType == 0)
                {
                    printf("* %-22s", "");
                }
                printf("%-24s", TabType[j].NomType);
                printf("%-8d", TabQte[j]);
                flagType = 0;
                for (int k = 0; k < TabQte[j]; k++)
                {
                    if (flagPdt == 0)
                    {
                        printf("* %-54s", "");
                    }
                    printf("%-8d", Stock[k][j].id);
                    printf("%2d / %2d / %d  *\n", Stock[k][j].Date_Ex.JJ, Stock[k][j].Date_Ex.MM, Stock[k][j].Date_Ex.AA);
                    flagPdt = 0;
                }
                flagPdt = 1;
            }
        }
        flagType = 1;
    }
    printf("* ----------------------------------------------------------------------------- *\n");
}

// Fonction qui ajoute une categorie dans la table des categories
void ajoutCat()
{
    if (NbCat > 20)
    {
        printf("*\t\tErreur : Categorie Plein!\t\t\t*\n");
    }
    else
    {
        affichCat();
        Categorie newCat;
        InitCat(&newCat);
        for (int i = 0; i < NbCat; i++)
        {
            if (TabCat[i].idCat == newCat.idCat || strcmp(TabCat[i].NomCat, newCat.NomCat) == 0)
            {
                printf("*\t\tErreur : Categorie deja existante!\t\t*\n");
                return;
            }
        }
        TabCat[NbCat] = newCat;
        NbCat++;
        printf("*\tCategorie ajoutee avec succes\t\t\t\t*\n");
    }
}

// Fonction qui ajoute un type dans la table des types
void ajoutType()
{
    if (NbTyp > 50)
    {
        printf("*\t\tErreur : Type Plein!\t\t\t*\n");
    }
    else
    {
        affichType();

        Type newType;
        InitType(&newType);
        for (int i = 0; i < NbTyp; i++)
        {
            if (TabType[i].idType == newType.idType || strcmp(TabType[i].NomType, newType.NomType) == 0)
            {
                printf("*\t\tErreur : Type deja existant!\t\t\t*\n");
                return;
            }
        }
        TabType[NbTyp] = newType;
        TabQte[NbTyp] = 0;
        NbTyp++;
        printf("*\tType ajoute avec succes\t\t\t\t\t*\n");
    }
}

// Fonction qui ajoute un produit dans la matrice des produits
void ajoutPdt()
{
    //     for (int i = 0; i < quantity; i++)
    // {
    //     printf("%2d | ", Stock[i][index].id);
    //     printf("%s                       \n", Stock[i][index].Nom);
    // }
    int index = -1;
    Produit newPdt;
    InitProduit(&newPdt);
    for (int i = 0; i < NbTyp; i++)
    {
        if (TabType[i].idType == newPdt.Typ.idType && strcmp(TabType[i].NomType, newPdt.Typ.NomType) == 0)
        {
            index = i;
            break;
        }
    }
    int quantity = TabQte[index];
    if (quantity > 100)
    {
        printf("Erreur : Produit Plein!\n");
    }
    else
    {
        for (int i = 0; i < quantity; i++)
        {
            if (Stock[i][index].id == newPdt.id || strcmp(Stock[i][index].Nom, newPdt.Nom) == 0)
            {
                printf("Erreur : Produit deja existant!\n");
                return;
            }
        }
        Stock[quantity][index] = newPdt;
        TabQte[index]++;
        printf("Produit ajoute avec succes\n");
    }
}

// Fonction qui supprime une categorie dans la table des categories
void suppCat()
{
    int y = 0, index = -1, idsupp;
    bool catExists = false;
    printf("le choix de la categorie se fait avec L'ID.\n");
    affichCat();
    do
    {
        printf("Entrez l'ID du categorie a supprimer : ");
        scanf("%d", &idsupp);
        for (int i = 0; i < NbCat; i++)
        {
            if (TabCat[i].idCat == idsupp)
            {
                index = i;
                catExists = true;
                break;
            }
        }
    } while (!catExists);

    for (int i = 0; i < NbTyp; i++)
    {
        if (TabType[i].Cat.idCat == idsupp)
        {
            y = 1;
            break;
        }
    }
    if (y == 1)
    {
        printf("Erreur : La categorie existe dans un Type!\n");
        return;
    }
    else
    {
        for (int i = index; i < NbCat - 1; i++)
        {
            TabCat[i] = TabCat[i + 1];
        }
        NbCat--;
        printf("Categorie supprimer avec success\n");
    }
}

// Fonction qui supprime un type dans la table des types
void suppType()
{
    int y = 0, index = -1, idsupp;
    printf("Entrez l'ID du type a supprimer : ");
    scanf("%d", &idsupp);
    for (int i = 0; i < NbTyp; i++)
    {
        if (TabType[i].idType == idsupp)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Erreur : Le Type n'existe pas!");
    }
    else
    {
        for (int i = 0; i < TabQte[index]; i++)
        {
            if (Stock[i][index].Typ.idType == idsupp)
            {
                y = 1;
                break;
            }
        }
        if (y == 1)
        {
            printf("Erreur : Le Type existe dans un produit!\n");
        }
        else
        {
            for (int i = index; i < NbTyp - 1; i++)
            {
                TabType[i] = TabType[i + 1];
            }
            NbTyp--;
            printf("Type supprimer avec success\n");
        }
    }
}

// Fonction qui supprime un produit dans la matrice des produits
void suppPdt()
{
    int indexI = -1, indexJ = -1, idsupp;
    bool PdtExists = false;
    do
    {
        printf("Entrez l'ID du produit a supprimer : ");
        scanf("%d", &idsupp);
        for (int i = 0; i < NbTyp; i++)
        {
            for (int j = 0; j < TabQte[i]; j++)
            {
                if (Stock[j][i].id == idsupp)
                {
                    indexI = i;
                    indexJ = j;
                    PdtExists = true;
                    break;
                }
            }
        }
    } while (!PdtExists);

    int quantity = TabQte[indexI];
    if (quantity <= 2)
    {
        printf("Erreur : La quantite est minimale!\n");
    }
    else
    {
        for (int i = indexJ; i < quantity - 1; i++)
        {
            Stock[i][indexI] = Stock[i + 1][indexI];
        }
        TabQte[indexI]--;
        printf("Produit supprimer avec success\n");
    }
}

// Vente et statistiques

// Vente
// Fonction pour vendre un produit avec des conditions bien determinee
void VendrePdt()
{
    int indextype = -1, idtype, indexPdt = -1;
    Produit p, p1;
    bool typeExists = false;
    printf("le choix du type se fait avec L'ID.\n");
    printf("Les Types (Quantite) : ");
    for (int i = 0; i < NbTyp; i++)
    {
        printf("%d\t%s (%d)", TabType[i].idType, TabType[i].NomType, TabQte[i]);
        if (i != NbTyp - 1)
        {
            printf(" | ");
        }
    }
    printf("\n");
    do
    {
        printf("Entrez le type du produit a vendre : ");
        scanf("%d", &idtype);
        for (int i = 0; i < NbTyp; i++)
        {
            if (TabType[i].idType == idtype)
            {
                indextype = i;
                typeExists = true;
                break;
            }
        }
    } while (!typeExists);

    int quantity = TabQte[indextype];
    if (quantity <= 2)
    {
        printf("Erreur : La quantite est minimale!\n");
        return;
    }
    else
    {
        p1 = Stock[0][indextype];
        indexPdt = 0;
        for (int i = 1; i < quantity; i++)
        {
            if (p1.Date_Ex.AA > Stock[i][indextype].Date_Ex.AA)
            {
                p = Stock[i][indextype];
                indexPdt = i;
            }
            else if (p1.Date_Ex.AA < Stock[i][indextype].Date_Ex.AA)
            {
                p = p1;
            }
            else
            {
                if (p1.Date_Ex.MM > Stock[i][indextype].Date_Ex.MM)
                {
                    p = Stock[i][indextype];
                    indexPdt = i;
                }
                else if (p1.Date_Ex.MM < Stock[i][indextype].Date_Ex.MM)
                {
                    p = p1;
                }
                else
                {
                    if (p1.Date_Ex.JJ > Stock[i][indextype].Date_Ex.JJ)
                    {
                        p = Stock[i][indextype];
                        indexPdt = i;
                    }
                    else if (p1.Date_Ex.JJ < Stock[i][indextype].Date_Ex.JJ)
                    {
                        p = p1;
                    }
                    else
                    {
                        p = Stock[i][indextype];
                        indexPdt = i;
                    }
                }
            }
        }
    }
    FILE *trace;
    trace = fopen("Trace.txt", "a");
    fprintf(trace, "%d %s %d %s %d %s %d/%d/%d\n", p.id, p.Nom, p.Typ.idType, p.Typ.NomType, p.Typ.Cat.idCat, p.Typ.Cat.NomCat, getCurrentDay(), getCurrentMonth(), getCurrentYear());
    fclose(trace);
    for (int i = indexPdt; i < quantity - 1; i++)
    {
        Stock[i][indextype] = Stock[i + 1][indextype];
    }
    TabQte[indextype]--;
}

void StatMois()
{
    MaDate date;
    Produit p;
    int salesTotal = 0, salesMonth = 0, salesCat[20] = {0};

    do
    {
        printf("Entrez l'annee : ");
        scanf("%d", &(date.AA));
    } while (date.AA < 2000 || date.AA > 2200);
    do
    {
        printf("Entrez le Mois : ");
        scanf("%d", &(date.MM));
    } while ((date.MM < 1 || date.MM > 12));

    FILE *trace;
    trace = fopen("Trace.txt", "r");

    if (trace == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    while (fscanf(trace, "%d %s %d %s %d %s %d/%d/%d\n", &p.id, p.Nom, &p.Typ.idType, p.Typ.NomType, &p.Typ.Cat.idCat, p.Typ.Cat.NomCat, &p.Date_Ex.JJ, &p.Date_Ex.MM, &p.Date_Ex.AA) == 9)
    {
        if (p.Date_Ex.AA == date.AA)
        {
            salesTotal++;
            if (p.Date_Ex.MM == date.MM)
            {
                salesMonth++;
                int i = 0;
                while (i < NbCat && p.Typ.Cat.idCat != TabCat[i].idCat)
                {
                    i++;
                }
                if (i < NbCat)
                {
                    salesCat[i]++;
                }
            }
        }
    }

    fclose(trace);

    printf("\n");
    printf("Vente total de l'annee %d : %d\n", date.AA, salesTotal);
    printf("Vente total du mois %d is : %d\n", date.MM, salesMonth);
    printf("Les ventes par categorie en %d/%d : ", date.MM, date.AA);
    int flagaff = 1;
    for (int i = 0; i < NbCat; i++)
    {
        if (salesCat[i] > 0)
        {
            if (flagaff == 0)
            {
                printf(" %-37s", "");
            }
            printf("-%-15s %d produits\n", TabCat[i].NomCat, salesCat[i]);
            flagaff = 0;
        }
    }
    flagaff = 1;
}

void StatAnnee()
{
    Produit p;
    int salesTotal = 0, salesMonth = 0, salesCat[20] = {0}, thisYear;

    do
    {
        printf("Entrez l'annee : ");
        scanf("%d", &thisYear);
    } while (thisYear < 2000 || thisYear > 2200);

    FILE *trace;
    trace = fopen("Trace.txt", "r");

    if (trace == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    while (fscanf(trace, "%d %s %d %s %d %s %d/%d/%d\n", &p.id, p.Nom, &p.Typ.idType, p.Typ.NomType, &p.Typ.Cat.idCat, p.Typ.Cat.NomCat, &p.Date_Ex.JJ, &p.Date_Ex.MM, &p.Date_Ex.AA) == 9)
    {
        if (p.Date_Ex.AA == thisYear)
        {
            salesTotal++;
            int i = 0;
            while (i < NbCat && p.Typ.Cat.idCat != TabCat[i].idCat)
            {
                i++;
            }
            if (i < NbCat)
            {
                salesCat[i]++;
            }
        }
    }

    fclose(trace);

    printf("\n");
    printf("Vente total de l'annee %d : %d\n", thisYear, salesTotal);
    printf("Les ventes par categorie en %d : ", thisYear);
    int flagaff = 1;
    for (int i = 0; i < NbCat; i++)
    {
        if (salesCat[i] > 0)
        {
            if (flagaff == 0)
            {
                printf(" %-34s", "");
            }
            printf("-%-15s %d produits\n", TabCat[i].NomCat, salesCat[i]);
            flagaff = 0;
        }
    }
    flagaff = 1;
}