#ifndef support_everywhere
#define support_everywhere

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int clear_buf();

int enter_int_num(int* koeff);

int enter_double_num(double* koeff);

enum Errors
{
    unknown_error           = -10,
    EOF_error               = EOF,
    arg_function_is_nullptr = 0,
    no_error                = 1
};

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
