#ifndef support_everywhere
#define support_everywhere

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <cstdio>

int clear_buf();

int enter_int_num(int* koeff);

enum Errors
{
    unknown_error           = -10,
    EOF_error               = EOF,
    arg_function_is_nullptr = 0,
    no_error                = 1
};

//Struct including coordinates
struct X_Y
{
    int x = 0;
    int y = 0;
}x_y;

//Constants using too controle game mode
const int COORD_FLAG_ON  = 1;
const int COORD_FLAG_OFF = 0;

//Array, contains of playfield symbols
char arr[41] = {' ', '_', '_', '_', '_', '_',' ', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                ' ', '*', '*', '*', '*', '*',' ', '\n', '\0',};

//Array, contains of variable place.It can't be changed
const int nums[9]  = {9, 11, 13, 17, 19, 21, 25, 27, 29};

#define check(condition, type_error)      				        														                   		     \
    if (!(condition))                                                                                                                                \
    {                                                                                                                                                \
		printf("\033[91mОшибка в условии %s в строке %d в файле %s в функции %s \n\033[39m", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__ ); \
        return type_error;                                                                                                                           \
    }

#define hard_check(condition)           				        														                   		     \
    if (!(condition))                                                                                                                                \
    {                                                                                                                                                \
		printf("\033[91mОшибка в условии %s в строке %d в файле %s в функции %s \n\033[39m", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__ ); \
        abort();                                                                                                                                     \
    }

#define RED(b) "\033[91m" b "\033[39m"
#define GREEN(b) "\033[32m" b "\033[39m"

#endif
