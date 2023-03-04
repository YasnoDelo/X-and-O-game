#include "support_everywhere.h"

//Array, contains of playfield symbols
char arr[41] = {' ', '_', '_', '_', '_', '_',' ', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                ' ', '*', '*', '*', '*', '*',' ', '\n', '\0',};

//Array, contains of variable place.It can't be changed
const int nums[9]  = {9, 11, 13, 17, 19, 21, 25, 27, 29};

//Struct including coordinates
struct X_Y
{
    int x = 0;
    int y = 0;
}x_y;

//Constants using too controle game mode
const int COORD_FLAG_ON  = 1;
const int COORD_FLAG_OFF = 0;


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

//Cleaner of dirty playing field
void clean(char* arr, const int* nums)
{
    char buf = '1';

    for(int co = 0; co < 9; co++)
    {
        arr[nums[co]] = buf++;
    }
}

//Enter of player's turn
int enter(char* arr, int num, int co)
{
    if(arr[num] == 'x' || arr[num] == 'o')
    {
        return 1;
    }

    if(co % 2 == 0)
    {
        arr[num] = 'x';
    }
    else
    {
        arr[num] = 'o';
    }

    return 0;
}

//Check of victory
int chck(char* arr)
{
    for(int co = 0; co < 3; co++)
    {
        if((arr[9 + co*2*4] == arr[9 + 2 + co*2*4]) && (arr[9 + co*2*4] == arr[9 + 4 + co*2*4]))
            return 1;
    }

    for(int co = 0; co < 3; co++)
    {
        if((arr[9 + co*2] == arr[9 + 8 + co*2]) && (arr[9 + co*2] == arr[9 + 16 + co*2]))
            return 1;
    }

    if((arr[9] == arr[19]) && (arr[9] == arr[29]))
        return 1;
    
    if((arr[13] == arr[19]) && (arr[13] == arr[25]))
        return 1;

    return 0;
}

//Checker of correct coordinate enter
int coord_chck(int* co, X_Y* coord_kit, char* arr)
{
    if(coord_kit->x < 1 || coord_kit->x > 3)
    {
        system("clear");
        (*co)--;

        printf(RED("Wrong coordinate x\nReturned previous step. Try to be more attentive\n"));

        DUMP(arr);

        return 1;
    }

    if(coord_kit->y < 1 || coord_kit->y > 3)
    {
        system("clear");
        (*co)--;

        printf(RED("Wrong coordinate y\nReturned previous step. Try to be more attentive\n"));

        DUMP(arr);

        return 1;
    }

    return 0;
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

//Gameplay with complex coordinate enter
int coord_gameplay(char* arr, const int* nums)
{
    X_Y var = {0, 0};
    int buf = 0;

    for(int co = 0; co < 9; co++)
        {
            printf("Turn #%d\n", co + 1);

            printf("Enter x coordinate of enterring symbol (1, 2 or 3)\n");
            enter_int_num(&var.x);

            printf("Enter y coordinate of enterring symbol (1, 2 or 3)\n");
            enter_int_num(&var.y);

            if(coord_chck(&co, &var, arr))
            {
                continue;
            }

            buf = (--var.x) + 3*(--var.y);

            system("clear");

            if(enter(arr, nums[buf] ,co))
            {
                symb_gump_dump(&co, arr, COORD_FLAG_ON);
                continue;
            }


            coord_DUMP(arr, nums, buf);

            if (chck(arr) == 1)
            {
                printf(GREEN("Player #%d won!\n"), 1 + co%2);
                return 1;

                break;
            }
        }

    return 0;
}

//Checker of correct value enretting
int num_chck(int* co, int num, char* arr)
{
    if(num < 1 || num > 9)
    {
        printf(RED("Wrong number!\nReturned previous step. Try to be more attentive\n"));

        (*co)--;

        return 1;
    }

    return 0;
}

//Gameplay with easy-enter
int easy_num_gameplay(char* arr, const int* nums)
{
    int num = 0;

    for(int co = 0; co < 9; co++)
    {
        printf("Turn #%d\n", co + 1);

        printf("Enter num of place, where you eant to see your symbol (1, 2,.. , 9)\n");
        enter_int_num(&num);

        if(num_chck(&co, num, arr))
        {
            continue;
        }

        system("clear");

        if(enter(arr, nums[num - 1] ,co))
        {
            symb_gump_dump(&co, arr, COORD_FLAG_OFF);
            continue;
        }


        DUMP(arr, nums, num - 1);

        if (chck(arr) == 1)
        {
            printf(GREEN("Player #%d won!\n"), 1 + co%2);
            return 1;

            break;
        }
    }

return 0;
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

int main()
{
    int go_flag    = 1;
    int coord_flag = 0;
    int won        = 0;

    printf("###################\nLETS GET IT STARTED\n###################\n");

    asker(&coord_flag, &go_flag);

    while(go_flag)
    {
        clean(arr, nums);

        system("clear");

        printf("###################\nLETS GET IT STARTED\n      AGAIN\n###################\n");

        switch (coord_flag)
        {
            case COORD_FLAG_ON:
            {
                coord_DUMP(arr);

                won = coord_gameplay(arr, nums);
                break;
            }
            case COORD_FLAG_OFF:
            {
                DUMP(arr);

                won = easy_num_gameplay(arr, nums);
                break;
            }
            default:
            {
                break;
            }
        }

        if(won == 0)
        {
            printf(GREEN("Pat! Both lost\nXOXOXXOXXOOXXOOXOXOXOXOXOXOX\n"));
        }

        printf(RED("Do you want to play one more time?\n"));
        printf(GREEN("Enter 0 if you want to stop this shit\n"));
        printf(RED("Or any other number to continue\n"));

        enter_int_num(&go_flag);
    }

    printf("#################\nLETS GET IT ENDED\n#################\n");

    return 0;
}
