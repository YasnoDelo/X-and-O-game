#include "../include/x_and_o_everywhere.h"

//Array, contains of playfield symbols
char arr[41] = {' ', '_', '_', '_', '_', '_',' ', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                '|', '1', '|', '2', '|', '3','|', '\n',
                ' ', '*', '*', '*', '*', '*',' ', '\n', '\0',};

//Array, contains of variable place.It can't be changed
const int nums[9]  = {9, 11, 13, 17, 19, 21, 25, 27, 29};

//Struct including coordinates
struct X_Y x_y;

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

