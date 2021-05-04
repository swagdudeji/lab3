#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "struct.h"
#include "functions.h"
#define DIV printf("%s\n", div);

int main(int argc, char* argv[]){
  if(argc<2){
    return 1;
  }
  FILE *f;
  if((f = fopen(argv[1], "r+")) == NULL){
    return 1;
  }
  
  char menu[] = "Туры для альпинистов \n \
    1 - добавить тур \n \
    2 - посмотреть все туры \n \
    3 - найти тур по названию \n \
    4 - найти тур по месту \n \
    5 - найти тур по дате \n \
    6 - найти тур по цене \n \
    7 - удалить тур \n \
    8 - выход \n \
    9 - повторный вызов меню \n";
  char div[] ="========================";

  printf("%s", menu);
  printf("%s\n", div);
  int count =0;
  int t =0;
  int i = 1;
  int id;
  char tmp1[60];

  while(!feof(f)){
    fgets(tmp1, 62, f);
    count++;
  }
  count = count-1;
  fseek(f, 0, SEEK_SET);
  
  Tour *data = malloc(count*sizeof(Tour));

  while(!feof(f) && t<=count){
    fscanf(f, "%s", data[t].name);
    fscanf(f, "%s", data[t].place);
    fscanf(f, "%s", data[t].date);
    fscanf(f, "%d", &data[t].price);
    t++;
  }

  while(i == 1){
    scanf("%d", &id);
    if(id == 1){
      addition(f, &count, data);
      DIV
    }
    else if(id == 2){
      show_all_entries(f, count, data);
      DIV
    }
    else if(id == 3){
      find_tour_by_name(f, count, data);
      DIV
    }
    else if(id == 4){
      find_tour_by_place(f, count, data);
      DIV
    }
    else if(id == 5){
      find_tour_by_date(f, count, data);
      DIV
    }
    else if(id == 6){
      find_tour_by_price(f, count, data);
      DIV
    }
    else if(id == 7){
      removal(f, &count, data);
    }
    else if(id == 8){
      break;
    }
    else if(id == 9){
      printf("%s", menu);
      DIV
    }
    else{
      printf("Неверный id команды\n");
      DIV
    }
  }
  fclose(f);
}