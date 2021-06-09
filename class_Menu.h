#include "class_Tour.h"

class Menu{
  public:

    std::string menu = "Туры для альпинистов \n \
    1 - добавить тур \n \
    2 - посмотреть все туры \n \
    3 - найти тур по названию \n \
    4 - найти тур по месту \n \
    5 - найти тур по дате \n \
    6 - найти тур по цене \n \
    7 - удалить тур \n \
    8 - выход \n \
    9 - повторный вызов меню \n";
    std::string div ="========================";

    static int count;

    Tour * addition(Tour *data);
    void show_all_entries(Tour *data);
    void find_tour_by_name(Tour *data);
    void find_tour_by_place(Tour *data);
    void find_tour_by_date(Tour *data);
    void find_tour_by_price(Tour *data);
    Tour * removal(Tour *data);
    Tour* getFile(fstream& f, Tour* data);
    fstream & saveChanges(std::fstream& f, string link, Tour * data);
};