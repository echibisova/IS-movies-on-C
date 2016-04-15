#include"movies.h"
int main() 
{
    int number=0;                   // количество записей
    int catalog_size=0;      	    // размер каталога
    movie *catalog=0;	            // каталог
    int i;			    // индекс
    int x;		            // выбранный пункт меню
    char file[30];                  // имя файла
//Загрузка информации о фильмах из файла        
        free(catalog);                            
	catalog=zagruzka(catalog, &number, file);
	catalog_size=number;
while(1){
    system ("clear");
    printf ("1: Просмотр каталога\n2: Добавление фильма\n3: Удаление фильма\n4: Сохранение данных\n5: Поиск фильмов\n0: Выход\n");
    printf ("\nВаш выбор: ");
    scanf ("%d", &x);  
    getchar ();
    switch (x)
    {
        case 1://просмотр каталога фильмов
                prosmotrall (catalog, number);
                break;
        case 2://добавление музыки
                number++;
                if (catalog_size<=number)
                {
                    catalog_size++;
                    catalog=(movie*)realloc(catalog, sizeof(movie) * catalog_size);
                }
                dobavlenie (&catalog[number-1]);
                break;
        case 3://удаление
                udalenie (catalog, &number);
                getchar ();
                break;
        case 4://Сохранение данных
                sohranenie (catalog, number, file);
                break;
        case 5://поиск
		podmenu ();
		scanf ("%d",&x);
		getchar ();
		switch (x)
		{
	            case 1: poisk (catalog, number, 1);
                            break;
	            case 2: poisk (catalog, number, 2);
                            break;
	            case 3: poisk (catalog, number, 3);
                            break;	            
                    case 0: break;
	            default: printf ("Неверный параметр поиска");
                             getchar ();
                             break;
                }
                break;
	case 0://Выход
		system ("clear");
	        free (catalog);
		return 0;
       default: 
               printf ("ОШИБКА\n");
    }
}  }
