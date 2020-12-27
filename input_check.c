#include "my.h"

int check_luck(int luck)
{
    if (luck == 0) {
        printf("luck cannot be 0\n");
        return (1);
    }
    return (0);
}

int check_size(sfVector2f size)
{
    if (size.x == 0) {
        printf("SizeX cannot be 0\n");
        return (1);
    }
    if (size.y == 0) {
        printf("SizeY cannot be 0\n");
        return (1);
    }
    return (0);
}