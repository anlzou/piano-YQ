#include "myhead.h"

void show_piano() {
    int i;

    // show background
    lcd_draw_jpg(0, 0, "./jpg/background.jpg", NULL, 0, 0);

    // show bar
    lcd_draw_jpg(0, 0, "./jpg/bar.jpg", NULL, 0, 0);

    // show keyboard
    for (i = 0; i < 12; i++) {
        lcd_draw_jpg(10 + 65 * i, 47, "./jpg/key_off.jpg", NULL, 0, 0);
    }

    // show logo
    lcd_draw_jpg(229, 335, "./jpg/logo.jpg", NULL, 0, 0);
}

int main(void) {
    int ts_x, ts_y;
    char music[12][30] = {
        {"madplay -Q ./mp3/d1.mp3 &"},  {"madplay -Q ./mp3/d2.mp3 &"},
        {"madplay -Q ./mp3/d3.mp3 &"},  {"madplay -Q ./mp3/d4.mp3 &"},
        {"madplay -Q ./mp3/d5.mp3 &"},  {"madplay -Q ./mp3/d6.mp3 &"},
        {"madplay -Q ./mp3/d7.mp3 &"},  {"madplay -Q ./mp3/d8.mp3 &"},
        {"madplay -Q ./mp3/d9.mp3 &"},  {"madplay -Q ./mp3/d10.mp3 &"},
        {"madplay -Q ./mp3/d11.mp3 &"}, {"madplay -Q ./mp3/d12.mp3 &"}};

    show_piano();

    while (1) {
        // get touch coordinate
        ts(&ts_x, &ts_y);

        int keynum = (ts_x - 10) / 65;
        if (ts_x > 10 && ts_x < 800 - 10) {
            // close madplay
            system("killall madplay");

            // play music
            system(music[keynum]);

            lcd_draw_jpg(10 + keynum * 65, 47, "./jpg/key_on.jpg", NULL, 0, 0);
            lcd_draw_jpg(10 + keynum * 65, 47, "./jpg/key_off.jpg", NULL, 0, 0);
        }
    }

    return 0;
}