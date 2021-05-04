#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "struct.h"


void addition(FILE *f, int *count, struct Tour *data){
  data = realloc(data, (*count+1)*sizeof(Tour));
  printf("Введите Название, Место, Дату и Стоимость тура \n");
  scanf("%s", data[*count].name);
  scanf("%s", data[*count].place);
  scanf("%s", data[*count].date);
  scanf("%d", &data[*count].price);
  fprintf(f, "%s ", data[*count].name);
  fprintf(f, "%s ", data[*count].place);
  fprintf(f, "%s ", data[*count].date);
  fprintf(f, "%d \n", data[*count].price);
  *count = *count + 1;
  printf("Тур успешно добавлен\n");
  
}
void show_all_entries(FILE *f, int count, struct Tour *data){
  for(int c =0; c<count; c++){
    printf("%d. %s %s %s $%d \n", c+1, data[c].name, data[c].place,\
    data[c].date, data[c].price);
  }
}
void find_tour_by_name(FILE *f, int count, struct Tour *data){
  int label = 0;
  char name[20];
  printf("Введите название тура \n");
  scanf("%s", name);
  for(int c =0; c<count; c++){
    if(strcmp(name, data[c].name)==0){
      printf("%s %s %s $%d \n", data[c].name, data[c].place,\
      data[c].date, data[c].price);
      label = 1;
    }
  }
  if(label==0){
    printf("Не существует тура с заданным именем \n");
  }
}
void find_tour_by_place(FILE *f, int count, struct Tour *data){
  int label = 0;
  char place[20];
  printf("Введите место тура \n");
  scanf("%s", place);
  for(int c =0; c<count; c++){
    if(strcmp(place, data[c].place)==0){
      printf("%s %s %s $%d \n", data[c].name, data[c].place,\
      data[c].date, data[c].price);
      label = 1;
    }
  }
  if(label==0){
    printf("Не существует тура с заданным местом \n");
  }
}
void find_tour_by_date(FILE *f, int count, struct Tour *data){
  int label = 0;
  char date[7];
  printf("Введите дату тура \n");
  scanf("%s", date);
  for(int c =0; c<count; c++){
    if(strcmp(date, data[c].date)==0){
      printf("%s %s %s $%d \n", data[c].name, data[c].place,\
      data[c].date, data[c].price);
      label = 1;
    }
  }
  if(label==0){
    printf("Не существует тура с заданной датой \n");
  }
}
void find_tour_by_price(FILE *f, int count, struct Tour *data){
  int label = 0;
  int minPrice;
  int maxPrice;
  printf("Введите границы цены \n");
  scanf("%d", &minPrice);
  scanf("%d", &maxPrice);
  for(int c =0; c<count; c++){
    if(data[c].price >= minPrice && data[c].price <= maxPrice){
      printf("%s %s %s $%d \n", data[c].name, data[c].place,\
      data[c].date, data[c].price);
      label = 1;
    }
  }
  if(label==0){
    printf("Не существует тура с заданным ценовым диапазоном \n");
  }
}
void removal(FILE *f, int *count, struct Tour *data){
  int num;
  char tmp[60];
  printf("Введите номер удаляемого тура \n");
      scanf("%d", &num);
      if(num>0 && num<=*count){
        for(int c=num-1; c<*count; c++){
          data[c] = data[c+1];
          *count= *count-1;
        }
        fseek(f, 0, SEEK_SET);
        for(int c=0; c<num-1; c++){
          fgets(tmp, 62, f);
        }
        while(num-1<*count){
          fprintf(f, "%s ", data[num-1].name);
          fprintf(f, "%s ", data[num-1].place);
          fprintf(f, "%s ", data[num-1].date);
          fprintf(f, "%d \n", data[num-1].price);
          num++;
        }
        for(int c=0; c<62; c++){
          fprintf(f, "%s ", "\0");
        }
        fprintf(f, "%s \n", "\0");
        printf("Тyр успешно удален \n");
        printf("========================\n");
      }
      else printf("Неверный номер тура\n");
}