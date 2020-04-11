#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "wili9340.h"
//#include "ili9340.h"

#define _DEBUG_ 0

FontxFile fx32G[2];
FontxFile fx24G[2];
FontxFile fx16G[2];

FontxFile fx32M[2];
FontxFile fx24M[2];
FontxFile fx16M[2];


void load_fonts(){
  Fontx_init(fx32G,"./fontx/ILGH32XB.FNT","./fontx/ILGZ32XB.FNT"); // 16x32Dot Gothic
  Fontx_init(fx24G,"./fontx/ILGH24XB.FNT","./fontx/ILGZ24XB.FNT"); // 12x24Dot Gothic
  Fontx_init(fx16G,"./fontx/ILGH16XB.FNT","./fontx/ILGZ16XB.FNT"); // 8x16Dot Gothic
  Fontx_init(fx32M,"./fontx/ILMH32XF.FNT","./fontx/ILMZ32XF.FNT"); // 16x32Dot Mincyo
  Fontx_init(fx24M,"./fontx/ILMH24XF.FNT","./fontx/ILMZ24XF.FNT"); // 12x24Dot Mincyo
  Fontx_init(fx16M,"./fontx/ILMH16XB.FNT","./fontx/ILMZ16XF.FNT"); // 8x16Dot Mincyo
}

int main(int argc, char **argv)
{
    struct LcdWindow *mainWindow;
    struct LcdWindow *subWindow;
    int screenWidth = 320;
    int screenHeight = 240;
    int offsetx = 0;
    int offsety = 0;
    load_fonts();
    //mainWindow=lcdInit(screenWidth, screenHeight, offsetx, offsety);
    lcdInit(screenWidth, screenHeight, offsetx, offsety);
    lcdReset();
    lcdSetup();

    //subWindow=lcdWindowInit(30,30,100,100,false,0);

    uint16_t colour;
    unsigned char utf8[64];
    uint16_t xpos = 200;
    uint16_t ypos =20;
    lcdFillScreen( BLACK);
    colour = WHITE;

    strncpy((char *)utf8, "main main main", sizeof(utf8));
    //lcdDrawUTF8String(mainWindow,fx16G, 100,200, utf8, RED);

    //strncpy((char *)utf8, "small small small", sizeof(utf8));
    //lcdDrawUTF8String(mainWindow,fx16G, 100,200, utf8, RED);
/*
    uint16_t colour;
    unsigned char utf8[64];
    uint16_t xpos = 200;
    uint16_t ypos =20;
    lcdFillScreen( BLACK);
    colour = WHITE;

    lcdSetFontDirection(DIRECTION90);

    strncpy((char *)utf8, "100,100", sizeof(utf8));
    hlcdDrawUTF8String(fx16G, 100,100, utf8, colour);

    strncpy((char *)utf8, "100,200", sizeof(utf8));
    hlcdDrawUTF8String(fx16G, 100,200, utf8, colour);

    strncpy((char *)utf8, "200,100", sizeof(utf8));
    hlcdDrawUTF8String(fx16G, 200,100, utf8, colour);

    strncpy((char *)utf8, "200,200", sizeof(utf8));
    hlcdDrawUTF8String(fx16G, 200,200, utf8, colour);

    hlcdDrawPixel(310,230,RED);
    hlcdDrawFillRect(7,150,1,200,BLUE);
   //lcdDrawFillRect(40,45,50,55,BLUE);
   hlcdDrawLine(200,200,100,100,RED);

   printf("Width is %i ",hlcdUTF8Width(fx32G, "ii"));
*/
    return 0;
}
