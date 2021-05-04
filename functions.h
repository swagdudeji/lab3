#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void addition(FILE *f, int *count, struct Tour *data);

void show_all_entries(FILE *f, int count, struct Tour *data);

void find_tour_by_name(FILE *f, int count, struct Tour *data);

void find_tour_by_place(FILE *f, int count, struct Tour *data);

void find_tour_by_date(FILE *f, int count, struct Tour *data);

void find_tour_by_price(FILE *f, int count, struct Tour *data);

void removal(FILE *f, int *count, struct Tour *data);

#endif