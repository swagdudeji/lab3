  
#include "class_Tour.h"

std::ostream& operator<< (std::ostream &out, const Tour tour){
  out << tour.getName() << " " << tour.getPlace() << " " << tour.getDate() << " " << tour.getPrice() << "\n";
  return out;
}

std::istream& operator>> (std::istream &in, Tour &tour){
  string name;
  string place;
  string date;
  string price;
  in >> name;
  in >> place;
  in >> date;
  in >> price;
  tour.setName(name);
  tour.setPlace(place);
  tour.setDate(date);
  tour.setPrice(price);
  return in;
}