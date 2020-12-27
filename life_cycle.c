#include "my.h"

int count_living_neighbors(all_t *s_all, int i, int j)
{
    int count = 0;
    if (j - 1 >= 0 && s_all->cells.array[i][j - 1].alive == 1)
        count++;
    if (j - 1 >= 0 && i - 1 >= 0 && s_all->cells.array[i - 1][j - 1].alive == 1)
        count++;
    if (i - 1 >= 0 && s_all->cells.array[i - 1][j].alive == 1)
        count++;
    if (i - 1 >= 0 && j + 1 < s_all->cells.width && s_all->cells.array[i - 1][j + 1].alive == 1)
        count++;
    if (j + 1 < s_all->cells.width && s_all->cells.array[i][j + 1].alive == 1)
        count++;
    if (i + 1 < s_all->cells.height && j + 1 < s_all->cells.width && s_all->cells.array[i + 1][j + 1].alive == 1)
        count++;
    if (i + 1 < s_all->cells.height && s_all->cells.array[i + 1][j].alive == 1)
        count++;
    if (i + 1 < s_all->cells.height && j - 1 >= 0 && s_all->cells.array[i + 1][j - 1].alive == 1)
        count++;
    return (count);
}

int change_life_cycle(all_t *s_all)
{
    for (int i = 0, index = 0; i < s_all->cells.height; i++) {
        for (int j = 0, count = 0; j < s_all->cells.width; j++, index++) {
            count = count_living_neighbors(s_all, i, j);
            if (s_all->cells.array[i][j].alive == 1)
                if (count == 3 || count == 2)
                    s_all->cells.new_state[index] = 1;
                else
                    s_all->cells.new_state[index] = 0;
            else if (s_all->cells.array[i][j].alive == 0) {
                if (count == 3)
                    s_all->cells.new_state[index] = 1;
                else
                    s_all->cells.new_state[index] = 0;
            }
        }
    }
    for (int i = 0, index = 0; i < s_all->cells.height; i++) {
        for (int j = 0; j < s_all->cells.width; j++, index++) {
            s_all->cells.array[i][j].alive = s_all->cells.new_state[index];
        }
    }
    return (0);
}