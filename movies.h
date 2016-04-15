typedef struct 
{
    char name[30]; 
    char time[10];
    char produsser[30];
    char views[10];
    char genre[30];
}movie;
void podmenu();
void forone(movie zapis);
void prosmotrall(movie *catalog, int number);
void dobavlenie(movie *entry);
void udalenie(movie *catalog, int *number);
void sohranenie(movie *catalog, int number, char *file);
movie* zagruzka(movie *catalog, int *number, char *file);
void poisk(movie *catalog, int number, int podpoisk);

