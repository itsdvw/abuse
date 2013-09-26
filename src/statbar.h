/*
 *  Abuse - dark 2D side-scrolling platform game
 *  Copyright (c) 1995 Crack dot Com
 *  Copyright (c) 2005-2013 Sam Hocevar <sam@hocevar.net>
 *
 *  This software was released into the Public Domain. As with most public
 *  domain software, no warranty is made or implied by Crack dot Com, by
 *  Jonathan Clark, or by Sam Hocevar.
 */

#ifndef __STAT_BAR_H_
#define __STAT_BAR_H_

#include "imlib/image.h"

class view;

#define TOTAL_WEAPONS 8

class status_bar
{
public:
  status_bar();
  void associate(view *V) { v=V; }
  void load();                     // load graphics into cache
  void redraw(AImage *screen);

  void step();
  void draw_health(AImage *screen,int amount);
  void draw_ammo(AImage *screen, int weapon_num, int amount, int light);
  void need_refresh() { need_rf=1; }
  void draw_update();

private:
  view *v;
  char need_rf,changed_cursor;
  int icon_in_selection,currently_selected_weapon;

  int bweap[TOTAL_WEAPONS],   // bright weap image
      dweap[TOTAL_WEAPONS],   // dark
      sbar,
      sbar_select,
      sbar_numpad,
      bnum[30];

  ibox2 GetArea();
  void draw_num(AImage *screen, int x, int y, int num, int *offset);
  int mouse_in_area();
};

extern status_bar sbar;

#endif
