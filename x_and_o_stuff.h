#ifndef stuff
#define stuff

#include "x_and_o_everywhere.h"
#include "x_and_o_comm.h"

void clean(char* arr, const int* nums);

int enter(char* arr, int num, int co);

int chck_win(char* arr);

int coord_chck(int* co, X_Y* coord_kit, char* arr);

int coord_gameplay(char* arr, const int* nums);

int num_chck(int* co, int num, char* arr);

int easy_num_gameplay(char* arr, const int* nums);

#endif