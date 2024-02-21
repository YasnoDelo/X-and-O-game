#ifndef support_everywhere
#define support_everywhere

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <cstdio>
#include "x_and_o_stuff.h"
#include "x_and_o_comm.h"

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
};

extern struct X_Y x_y;

//Constants using too controle game mode
const int COORD_FLAG_ON  = 1;
const int COORD_FLAG_OFF = 0;

extern const int nums[];
extern char arr[];

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
#define YELLOW(b) "\033[33m" b "\033[39m"
#define BLUE(b) "\033[36m" b "\033[39m"

#endif
