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



int _width;
int _height;

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

    int screenWidth = 320;
    int screenHeight = 240;
    int offsetx = 0;
    int offsety = 0;
    load_fonts();
    struct  LcdWindow* mainWindow = lcdInit(offsetx, offsety, screenWidth, screenHeight, false);
    lcdReset();
    lcdSetup();


    uint16_t colour;
    unsigned char utf8[64];
    uint16_t xpos = 200;
    uint16_t ypos =20;
    lcdFillScreen( mainWindow, RED);
    colour = WHITE;

    lcdSetFontDirection(DIRECTION0);

    strncpy((char *)utf8, "10,10", sizeof(utf8));
    lcdDrawUTF8String(mainWindow,fx16G, 10,10, utf8, colour);

    strncpy((char *)utf8, "10,200", sizeof(utf8));
    lcdDrawUTF8String(mainWindow,fx16G, 10,200, utf8, colour);

    strncpy((char *)utf8, "100,100", sizeof(utf8));
    lcdDrawUTF8String(mainWindow,fx16G, 100,100, utf8, colour);

    strncpy((char *)utf8, "100,200", sizeof(utf8));
    lcdDrawUTF8String(mainWindow,fx16G, 100,200, utf8, colour);

    lcdDrawPixel(mainWindow,310,230,RED);
    //lcdDrawFillRect(mainWindow,100,100,200,200,BLUE);


   struct LcdWindow* subWindow = lcdWindowInit(100,100,95,50);
   lcdDrawLine(subWindow,1,1,200,200,BLUE);
   strncpy((char *)utf8, "subsubsub123456789012345678901234567890", sizeof(utf8));
   lcdDrawUTF8String(subWindow,fx16G, 10,10, utf8, GREEN);
   //lcdDrawFillRect(mainWindow,0,0,50,51,CYAN);
   lcdDrawFillRect(mainWindow,0,0,50,51,GREEN);

   //lcdDrawFillCircle(subWindow,10,10,30,CYAN);

    return 0;
}
