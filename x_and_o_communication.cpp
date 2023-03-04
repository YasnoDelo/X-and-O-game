#include "x_and_o_comm.h"

//Dump of playing field. Using coordinates
void coord_DUMP(char* arr)
{   
    for(int co = 0; co < 10; co++)
        putchar('-');
    putchar('>');
    putchar('x');
    putchar('\n');

    for(int co = 0; co < 5; co++)
        {
            putchar('|');
            putchar('\n');
        }
    putchar('$');
    putchar('y');
    putchar('\n');

    printf(GREEN("%s"), arr);
}

//Dump of playing field. No coordinates
void DUMP(char* arr)
{
    printf(GREEN("%s"), arr);
}

//Dump of playing field with information about the newest added element. Using coordinates
void coord_DUMP(char* arr,const int* nums, int num)
{   
    for(int co = 0; co < 10; co++)
        putchar('-');
    putchar('>');
    putchar('x');
    putchar('\n');

    for(int co = 0; co < 5; co++)
        {
            putchar('|');
            putchar('\n');
        }
    putchar('$');
    putchar('y');
    putchar('\n');

    for(int co = 0; co < 40; co++)
    {
        if(co == nums[num])
        {
            printf(RED("%c"), arr[co]);
        }
        else
        {
            printf(GREEN("%c"), arr[co]);
        }
    }
}

//Dump of playing field with information about the newest added element. No coordinates
void DUMP(char* arr, const int* nums, int num)
{
    for(int co = 0; co < 40; co++)
    {
        if(co == nums[num])
        {
            printf(RED("%c"), arr[co]);
        }
        else
        {
            printf(GREEN("%c"), arr[co]);
        }
    }
}

//Dump in case of tring replace earlier added symbol
void symb_gump_dump(int* co, char* arr, int coord_flag)
{                
    (*co)--;

    printf(RED("Error! Symbol was entered onto busy place.\nReturned previous step and try to be more attentive\n"));

    if(coord_flag)
        coord_DUMP(arr);
    else
        DUMP(arr);
}

//Let's give some varianty to players
void asker(int* coord_flag, int* go_flag)
{
    printf(GREEN("Do you want to play using coordinates?(y/n)\n"));

    char letter = getchar();

    switch (letter)
    {
        case 'y':
        {
            *coord_flag = 1;
            break;
        }
        
        case 'n':
        {
            *coord_flag = 0;
            break;
        }

        default:
        {
            printf(RED("Than good buy. You are too stupid to play in so smart game(\n"));

            *go_flag = 0;
            break;
        }
    }
}
