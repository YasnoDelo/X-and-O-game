#include "../include/x_and_o_everywhere.h"

//Clean enter buffer
int clear_buf()
{
	while (getchar() != '\n');

    return no_error;
}

//Correct enter of integer number
int enter_int_num(int* koeff)
{
	while ( (scanf("%d", koeff)) != 1 )
	{
			printf(RED("Введено нецелое число. А должно быть введено целое число. Попробуйте ввести его ещё раз. \n"));
			clear_buf();
	}
	clear_buf();

    return no_error;
}