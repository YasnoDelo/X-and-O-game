#include "../include/x_and_o_everywhere.h"

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
int chck_win(char* arr)
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
int coord_chck(int* co, struct X_Y* coord_kit, char* arr)
{
    if(coord_kit->x < 1 || coord_kit->x > 3)
    {
        system("clear");
        (*co)--;

        printf(RED("Wrong coordinate x\nReturned previous step. Try to be more attentive\n"));

        coord_DUMP(arr);

        return 1;
    }

    if(coord_kit->y < 1 || coord_kit->y > 3)
    {
        system("clear");
        (*co)--;

        printf(RED("Wrong coordinate y\nReturned previous step. Try to be more attentive\n"));

        coord_DUMP(arr);

        return 1;
    }

    return 0;
}


//Gameplay with complex coordinate enter
int coord_gameplay(char* arr, const int* nums)
{
    struct X_Y var = {0, 0};
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

            if (chck_win(arr) == 1)
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

        if (chck_win(arr) == 1)
        {
            printf(GREEN("Player #%d won!\n"), 1 + co%2);
            return 1;

            break;
        }
    }

return 0;
}
