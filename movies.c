#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "movies.h"
void podmenu ()
{  
    system ("clear");
    printf ("1: По названию\n2: По жанру\n3: По просмотрам\n0: Отмена\n");
}
//Вывод данных по поиску 
void forone (movie zapis)
{
    printf ("Название фильма: %s\n",zapis.name);
    printf ("Продолжительность: %s\n", zapis.time);
    printf ("Режиссер: %s\n", zapis.produsser);
    printf ("Просмотры: %s\n", zapis.views);
    printf ("Жанр: %s\n", zapis.genre);
}
//Вывод всего каталога
void prosmotrall (movie *catalog, int number)
{
    system("clear");
    int i;
    if (number==0)
    {
	printf ("Каталог пуст\n");
	return;
    }
    else
    {
        for (i=0; i<number; i++)
        {
	    printf ("Фильм № %d\n", i+1);
	    forone (catalog[i]);
	    printf ("\n");
        }
    }
    getchar ();
}
//Добавление нового фильма в каталог
void dobavlenie (movie *zapis)
{
    system ("clear");
    printf ("---ДОБАВЛЕНИЕ НОВОЙ ЗАПИСИ---\n");
    printf ("Название фильма: ");
    gets(zapis->name);
    printf ("Продолжительность: ");
    gets(zapis->time);
    printf ("Режиссер: ");
    gets(zapis->produsser);
    printf ("Просмотры: ");
    gets(zapis->views);
    printf ("Жанр: ");
    gets(zapis->genre);
    fflush (stdin);
    system ("clear");
    printf ("Запись добавлена\n\n");
    getchar ();
}
//Удаление записи из каталога
void udalenie (movie *catalog, int *number)
{
    system ("clear");
    printf ("---УДАЛЕНИЕ ЗАПИСИ---\n");
    int i,x;
    printf ("Введите номер фильма для удаления: ");
    scanf ("%d", &x);
    x--;
    if (x<0 || x>=*number)
    {
	system ("clear");
	printf ("Записи с таким номером не существует\n");
        getchar ();
	return;
    }
    for (i=x; i<*number-1; i++)
	catalog[i]=catalog[i+1];
    (*number)--;
    system ("clear");
    printf ("Запись удалена\n");
}
//Сохранение каталога в файл
void sohranenie (movie *catalog, int number, char *file)
{
    system ("clear");
    FILE *fp = fopen (file, "wb");
    int i;
    system ("clear");
    if (fp==0)
    {
	printf ("Не удалось сохранить данные в файл");
	return;
    }
    for(i=0; i<number; i++)
    {
	fwrite (&catalog[i].name, sizeof(char), 30, fp);
	fwrite (&catalog[i].time, sizeof(char), 10, fp);
	fwrite (&catalog[i].produsser, sizeof(char), 30, fp);
	fwrite (&catalog[i].views, sizeof(char), 10, fp);
	fwrite (&catalog[i].genre, sizeof(char), 30, fp);
    }
    fflush (stdin);
    printf ("Данные сохранены в файл %s", file);
    getchar ();
    fclose (fp);
}

//Загрузка каталога из файла 
movie* zagruzka (movie *catalog, int *number, char *file)
{
    catalog=(movie*)malloc(sizeof(movie));
    system ("clear");
    printf ("Имя файла с данными: ");
    gets (file);
    FILE* fp = fopen(file, "rb");
    int size_catalog = 0;
    system ("clear");
    if (fp==0)
    {
	printf ("Не удалось открыть файл");
	return 0;
    }
    while (!feof(fp))
    {		
	(*number)++;
	catalog=(movie*)realloc(catalog, sizeof(movie)*(*number));
	fread (catalog[(*number) - 1].name, sizeof(char), 30, fp);
	fread (catalog[(*number) - 1].time, sizeof(char), 10, fp);
	fread (catalog[(*number) - 1].produsser, sizeof(char), 30, fp);
	fread (catalog[(*number) - 1].views, sizeof(char), 10, fp);
	fread (catalog[(*number) - 1].genre, sizeof(char), 30, fp);
    }
    catalog[(*number)-1]=catalog[*number];
    (*number)--;
    printf ("Данные загружены\n");
    fclose (fp);
    getchar ();
    return catalog;
}

//Поиск музыки 
void poisk (movie *catalog, int number, int podpoisk)
{
    system ("clear");
    int i,j;
    int flag;
    movie zapis;
    movie buffer;
    switch (podpoisk)
    {
	case 1://по названию
		printf ("Введите имя фильма для поиска: ");
                gets (zapis.name);
		break;
        case 2: //по жанру
		printf ("Введите жанр фильма для поиска: ");
		gets (zapis.genre);
		break;
        case 3: //по просмотрам
		printf ("Введите колличество просмотров для поиска: ");
		gets (zapis.views);
		break;
    }
    system ("clear");
    for (i=0; i<number; i++)
    {
	flag=0;
	switch (podpoisk)
	{
	        case 1: if (strcmp(catalog[i].name, zapis.name)==0) 
                        flag = 1; 
                        break; 
		case 2: if (strcmp(catalog[i].genre, zapis.genre)==0) 
                        flag = 1; 
                        break;
		case 3: if (strcmp(catalog[i].views, zapis.views)==0) 
                        flag = 1; 
                        break;
	}
	if (flag==1)
	{
   	    printf ("*");
	    forone (catalog[i]);
	    printf ("\n");
	}
    }
    getchar();
}

