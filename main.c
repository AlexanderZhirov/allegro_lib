#include <stdio.h>
#include <allegro5/allegro_primitives.h>

#include "lib/common.h"

int main(int argc, char** argv)
{
    cl_load_allegro_resources();
    
    CLIENT_PARAMETRS parametrs =
    {
        .fullscreen = false,
        .resolution = false,
        .scale_factor = 0.5,
        .width = 800,
        .height = 400,
        .num_adapter = 0,
        .FPS = 60,
        .bitmaps_size = 8,
        .fonts_size = 4,
        .samples_size = 6,
        .pairing_size = 13,
        .sound_size = 2
    };
    
    CLIENT_RESOURCE* data = cl_create_resource(NULL, parametrs);

    al_start_timer(data->timer.al_timer);
    data->timer.time = al_current_time();
    
    srand(time(NULL));
    
    while(!data->done)
    {
        al_wait_for_event(data->event.queue, &data->event.current);
        
        if(data->event.current.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (data->event.current.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:
                    data->done = true;
            }
        }
        else if(data->event.current.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (data->event.current.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:
                    data->done = true;
                    break;
            }
        }
        else if(data->event.current.type == ALLEGRO_EVENT_TIMER)
            data->render = true;

        if(data->render && al_is_event_queue_empty(data->event.queue))
        {
            data->render = false;
            cl_pre_draw();
            
            al_draw_filled_rectangle(5, 5, 100, 100, al_map_rgba_f(0.4, 0.4, 0.0, 0.2));
            
            cl_post_draw();
        }
    }
    
    cl_destroy_resource(data);
    
    return EXIT_SUCCESS;
}
