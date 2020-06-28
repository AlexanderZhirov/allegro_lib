/* 
 * File:   common.h
 * Author: Alexander Zhirov
 * Connection with me (telegram messanger): @alexanderzhirov
 *
 * Created on 2020.06.02
 */

#ifndef client_common
#define client_common

#include "screen.h"
#include "timer.h"
#include "event.h"
#include "media.h"
#include "interface.h"
#include "instance.h"

typedef struct cl_resource
{
    CLIENT_SCREEN screen;
    CLIENT_TIMER timer;
    CLIENT_EVENT event;
    CLIENT_MEDIA media;
    CLIENT_PAIRING pairing;
    CLIENT_SOUND sound;
    bool done;
    bool render;
} CLIENT_RESOURCE;

typedef struct cl_parametrs
{
    bool fullscreen;
    bool resolution;
    float scale_factor;
    int width;
    int height;
    int num_adapter;
    int FPS;
    int bitmaps_size;
    int fonts_size;
    int samples_size;
    int pairing_size;
    int sound_size;
} CLIENT_PARAMETRS;

void cl_load_allegro_resources();
CLIENT_RESOURCE* cl_create_resource(CLIENT_RESOURCE* res, CLIENT_PARAMETRS parametrs);
void cl_destroy_resource(CLIENT_RESOURCE* res);

#endif
