//Menu
int getChoice();
int Menu();
void gestionStock();
void gestionCategories();
void gestionTypes();
void gestionProduits();
void affichageStock();
void VenteStatistiques();
void venteProduits();
void Statistiques();
void StatistiquesMois();
void StatistiquesAnnee();

typedef struct Categorie
{
    int idCat;
    char NomCat[20];
} Categorie;
typedef struct MaDate
{
    int JJ;
    int MM;
    int AA;
} MaDate;
typedef struct Type
{
    int idType;
    char NomType[20];
    Categorie Cat;
} Type;
typedef struct Produit
{
    int id;
    char Nom[20];
    Type Typ;
    MaDate Date_Ex;
} Produit;

extern Categorie *TabCat;
extern Type *TabType;
extern Produit **Stock;
extern int *TabQte;
extern int NbCat;
extern int NbTyp;

void initializeArrays();

void InitCat(Categorie *categorie);
void InitDate(MaDate *date);
void InitType(Type *type);
void InitProduit(Produit *produit);

void affichStock();

void ajoutCat();
void ajoutType();
void ajoutPdt();

void suppCat();
void suppType();
void suppPdt();

void VendrePdt();
void StatMois();
void StatAnnee();

void affichCat();
void affichType();

