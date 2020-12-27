#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>

typedef struct s_cell {
    int alive;
    sfVector2f position;
    sfRectangleShape *rectangle;
} cell_t;

typedef struct s_cells {
    int height;
    int width;
    sfVector2f size;
    int luck;
    sfVector2f color;
    cell_t **array;
    int *new_state;
} cells_t;

typedef struct s_all {
    sfRenderWindow *window;
    sfEvent event;
    cells_t cells;
    int pause;
} all_t;

void poll_event(all_t *s_all);
void create_cells_array(all_t *s_all, sfVector2f size, int luck);
void free_cells_array(all_t *s_all);
void draw_scene(all_t *s_all);
int change_life_cycle(all_t *s_all);
void change_cell_state_onclick(all_t *s_all);
int check_luck(int luck);
int check_size(sfVector2f size);