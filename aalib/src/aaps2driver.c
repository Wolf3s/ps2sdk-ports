#include "config.h"
#include <stdio.h>
#include "aalib.h"
#include <debug.h>

static int ps2scr_init(__AA_CONST struct aa_hardware_params *p, __AA_CONST void *none, struct aa_hardware_params *dest, void **n)
{
    (void)p;
    (void)none;
    (void)n;
    static struct aa_hardware_params def={NULL, AA_NORMAL_MASK | AA_EXTENDED};
    *dest=def;
    init_scr();
    scr_clear();
    return 1;
}
static void ps2scr_uninit(aa_context * c)
{
    (void)c;
    scr_clear();
}
static void ps2scr_getsize(aa_context * c, int *width, int *height)
{
    (void)c;
    width = (int*)scr_getX();
    height = (int*)scr_getY();
}

static void ps2scr_flush(aa_context * c)
{
    (void)c;
    int x, y;
    for (y = 0; y < aa_scrheight(c); y++) {
	for (x = 0; x < aa_scrwidth(c)-2; x++) {
	    scr_printf("%c",c->textbuffer[x + y * aa_scrwidth(c)]);
	}
	scr_printf(" \n");
    }
    scr_printf(" \n");
    scr_clear();
}
static void ps2scr_gotoxy(aa_context * c, int x, int y)
{
    (void)c;
    scr_setXY(x, y);
}

static void ps2scr_cursormode(struct aa_context *c, int enable)
{
    (void)c;
    scr_setCursor(enable);
}

__AA_CONST struct aa_driver playstation2_d =
{
    "ps2_scr", "ps2 screen debug driver",
    ps2scr_init,
    ps2scr_uninit,
    ps2scr_getsize,
    NULL,
    NULL,
    ps2scr_gotoxy,
    ps2scr_flush,
    ps2scr_cursormode
};