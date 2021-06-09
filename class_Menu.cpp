#include "class_Menu.h"

Tour * Menu::getFile(fstream &f, Tour *data){
    string tmp1;
    while (!f.eof()) {
      getline(f, tmp1);
      count++;
      }
    count--;
    f.clear();
    f.seekg(0, ios::beg);
    Tour *tmpData = new Tour[count];
    int i=0;
    while(!f.eof()){
      f >> tmpData[i];
      i++;
      }
    data = tmpData;
    tmpData = nullptr;
    return data;
    }

Tour * Menu::addition(Tour * data){
  Tour * tmpData = new Tour[count+1];
  for(int i=0; i<count; i++){
    tmpData[i] = data[i];
  }
  delete[] data;
  string name;
  string place;
  string date;
  string price;
  cout << "Введите Название, Место, Дату и Стоимость тура" << endl;
  cin >> tmpData[count];
  data = tmpData;
  tmpData = nullptr;
  count++;
  cout << "Тур успешно добавлен" << endl;
  return data;
}

void Menu::show_all_entries(Tour *data){
  for(int i=0; i<count; i++){
    cout << i+1 << ": " << data[i];
  }
}

void Menu::find_tour_by_name(Tour *data){
  bool label = false;
  string name;
  cout << "Введите название тура" << endl;
  cin >> name;
  for(int c =0; c<count; c++){
    if(name == data[c].getName()){
      cout << data[c];
      label = true;
      }
    }
  if(label == false){
    cout << "Не существует тура с заданным именем" << endl;
    }
  }

    void Menu::find_tour_by_place(Tour *data){
      bool label = false;
      string place;
      cout << "Введите место тура" << endl;
      cin >> place;
      for(int c =0; c<count; c++){
        if(place == data[c].getPlace()){
          cout << data[c];
          label = true;
        }
      }
      if(label == false){
        cout << "Не существует тура с заданным местом" << endl;
      }
    }

    void Menu::find_tour_by_date(Tour *data){
      bool label = false;
      string date;
      cout << "Введите дату тура" << endl;
      cin >> date;
      if(date.length() != 7){
        cout << "Неверный формат даты" << endl;
      }
      else{
        for(int c =0; c<count; c++){
          if(date == data[c].getDate()){
            cout << data[c];
            label = true;
          }
        }
        if(label == false){
          cout << "Не существует тура с заданной датой" << endl;
        }
      }
    }

    void Menu::find_tour_by_price(Tour *data){
      bool label = false;
      string price;
      cout << "Введите цену тура" << endl;
      cin >> price;
      for(int c =0; c<count; c++){
        if(price == data[c].getPrice()){
          cout << data[c];
          label = true;
          }
        }
      if(label == false){
          cout << "Не существует тура с заданной ценой" << endl;
        }
    }

Tour * Menu::removal(Tour *data){
  int num;
  int stopCounter;
  cout << "Введите номер удаляемого тура" << endl;
  cin >> num;
  Tour * tmpData = new Tour[count-1];
  for(int i=0; i<num-1; i++){
    tmpData[i] = data[i];
  }
  for(int i=num-1; i<count-1; i++){
    tmpData[i] = data[i+1];
  }
  delete[] data;
  data = tmpData;
  tmpData = nullptr;
  count--;
  cout << "Тур успешно удален" << endl;
  return data;
}

fstream& Menu::saveChanges(std::fstream& f, string link, Tour * data){
  f.close();
  f.open(link, std::fstream::out | std::fstream::trunc);
  for(int i=0; i<count; i++){
    f << data[i];
  }
  return f;
}