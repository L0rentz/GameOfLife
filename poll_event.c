#include "my.h"

void poll_event(all_t *s_all)
{
    while (sfRenderWindow_pollEvent(s_all->window, &s_all->event)) {
        if (s_all->event.type == sfEvtClosed)
            sfRenderWindow_close(s_all->window);
        if (s_all->event.type == sfEvtKeyReleased && s_all->event.key.code == sfKeySpace)
            s_all->pause = !s_all->pause;
        if (sfMouse_isButtonPressed(s_all->event.mouseButton.button) && s_all->event.mouseButton.button == sfMouseLeft) {
            change_cell_state_onclick(s_all);
        }
    }
}