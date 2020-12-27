#include "my.h"

all_t *init_all(sfVector2f size, int luck)
{
    all_t *s_all = malloc(sizeof(all_t));
    sfVideoMode mode = {1920, 1080, 32};
    s_all->window = sfRenderWindow_create(mode, "Game Of Life", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(s_all->window, 144);
    srand(time(NULL));
    s_all->pause = 0;
    create_cells_array(s_all, size, luck);
    return (s_all);
}

void free_all(all_t *s_all)
{
    free_cells_array(s_all);
    sfRenderWindow_destroy(s_all->window);
    free(s_all);
    s_all = NULL;
}

int main(int ac, char **av)
{
    if (ac != 5) {
        printf("Usage: ./GameOfLife sizeX sizeY luck speed\n");
        return (84);
    }
    sfVector2f size = (sfVector2f){atoi(av[1]), atoi(av[2])};
    int luck = atoi(av[3]);
    if (check_size(size) == 1 || check_luck(luck) == 1)
        return (84);
    all_t *s_all = init_all(size, luck);

    int change = 0, speed = atoi(av[4]);
    while (sfRenderWindow_isOpen(s_all->window)) {
        poll_event(s_all);
        if (s_all->pause == 0 && change > speed)
            change = change_life_cycle(s_all);
        draw_scene(s_all);
        change++;
    }
    free_all(s_all);
    return (0);
}