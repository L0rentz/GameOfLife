#include "my.h"

void allocate_cells(all_t *s_all)
{
    s_all->cells.array = malloc(sizeof(cell_t *) * s_all->cells.height);
    for (int i = 0; i < s_all->cells.height; i++)
        s_all->cells.array[i] = malloc(sizeof(cell_t) * s_all->cells.width);
}

void fill_cells(all_t *s_all)
{
    for (int i = 0; i < s_all->cells.height; i++) {
        for (int j = 0; j < s_all->cells.width; j++) {
            s_all->cells.array[i][j].alive = (rand() % s_all->cells.luck == 0) ? 1 : 0;
            s_all->cells.array[i][j].position = (sfVector2f){j * s_all->cells.size.x, i * s_all->cells.size.y};
            s_all->cells.array[i][j].rectangle = sfRectangleShape_create();
            sfRectangleShape_setPosition(s_all->cells.array[i][j].rectangle, s_all->cells.array[i][j].position);
            sfRectangleShape_setSize(s_all->cells.array[i][j].rectangle, s_all->cells.size);
            sfRectangleShape_setFillColor(s_all->cells.array[i][j].rectangle, sfWhite);
        }
    }
}

void create_cells_array(all_t *s_all, sfVector2f size, int luck)
{
    s_all->cells.luck = luck;
    s_all->cells.size = size;
    s_all->cells.height = 1080 / s_all->cells.size.y;
    s_all->cells.width = 1920 / s_all->cells.size.x;
    s_all->cells.new_state = malloc(sizeof(int) * (s_all->cells.height * s_all->cells.width));
    allocate_cells(s_all);
    fill_cells(s_all);
}

void free_cells_array(all_t *s_all)
{
    for (int i = 0; i < s_all->cells.height; i++) {
        for (int j = 0; j < s_all->cells.width; j++) {
            sfRectangleShape_destroy(s_all->cells.array[i][j].rectangle);
            s_all->cells.array[i][j].rectangle = NULL;
        }
        free(s_all->cells.array[i]);
        s_all->cells.array[i] = NULL;
    }
    free(s_all->cells.array);
    s_all->cells.array = NULL;
    free(s_all->cells.new_state);
    s_all->cells.new_state = NULL;
}