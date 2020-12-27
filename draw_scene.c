#include "my.h"

void change_cell_state_onclick(all_t *s_all)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(s_all->window);
    sfVector2f mouse_pos = (sfVector2f){tmp.x, tmp.y};
    for (int i = 0; i < s_all->cells.height; i++) {
        for (int j = 0; j < s_all->cells.width; j++) {
            sfFloatRect rect = sfRectangleShape_getGlobalBounds(s_all->cells.array[i][j].rectangle);
            if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
                s_all->cells.array[i][j].alive = !s_all->cells.array[i][j].alive;
                return;
            }
        }
    }
}

void draw_cells(all_t *s_all)
{
    for (int i = 0; i < s_all->cells.height; i++) {
        for (int j = 0; j < s_all->cells.width; j++) {
            if (s_all->cells.array[i][j].alive == 1)
                sfRenderWindow_drawRectangleShape(s_all->window, s_all->cells.array[i][j].rectangle, NULL);
        }
    }
}

void draw_scene(all_t *s_all)
{
    sfRenderWindow_clear(s_all->window, sfBlack);
    draw_cells(s_all);
    sfRenderWindow_display(s_all->window);
}