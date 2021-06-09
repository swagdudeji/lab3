#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tour{

  private:

    string name;
    string place;
    string date;
    string price;

  public:

    friend std::ostream& operator<< (std::ostream &out, const Tour tour);
    friend std::istream& operator>> (std::istream &in, Tour &tour);

    const string getName() const {return name;};
    const string getPlace() const {return place;};
    const string getDate() const {return date;};
    const string getPrice() const {return price;};
    
    void setName(std::string tmpName){name = tmpName;};
    void setPlace(std::string tmpPlace){place = tmpPlace;};
    void setDate(std::string tmpDate){date = tmpDate;};
    void setPrice(std::string tmpPrice){price = tmpPrice;};
};