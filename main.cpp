
#include <iostream>
#include <fstream>
#include <string>
#include "class_Menu.h"
#define DIV cout << menu.div << endl;

using namespace std;

int Menu::count = 1;

int main(/*int argc, char* argv[]*/){

  #if 0
  if(argc<2){return 1;}
  #endif

  fstream out(/*argv[1]*/"inputFile.txt", ios::in | ios::out);
    if(!out) {
        cout << "Файл не открылся";
        return 0;}
  string link = "inputFile.txt";
  Menu menu;

  cout << menu.menu << endl;
  cout << menu.div <<endl;

  int i = 1;
  int id;
  int arr_size = 1;
  Tour *data = new Tour[Menu::count];
  data = menu.getFile(out, data);

  while(i == 1){
    cin >> id;
    if(id == 1){
      data = menu.addition(data);
      menu.saveChanges(out, link, data);
      DIV
    }
    else if(id == 2){
      menu.show_all_entries(data);
      DIV
    }
    else if(id == 3){
      menu.find_tour_by_name(data);
      DIV
    }
    else if(id == 4){
      menu.find_tour_by_place(data);
      DIV
    }
    else if(id == 5){
      menu.find_tour_by_date(data);
      DIV
    }
    else if(id == 6){
      menu.find_tour_by_price(data);
      DIV
    }
    else if(id == 7){
      data = menu.removal(data);
      menu.saveChanges(out, link, data);
      DIV
    }
    else if(id == 8){
      break;
    }
    else if(id == 9){
      cout << menu.menu << endl;
      DIV
    }
    else{
      cout << "Неверный id команды\n" << endl;
      DIV
    }
  }
  out.close();
}