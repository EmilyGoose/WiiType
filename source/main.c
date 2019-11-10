#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

//#include "OnScreenKeyboard.h"
//#include "wiisprite.h"

static u32 *xfb;
static GXRModeObj *rmode;

// Wiimote IR
ir_t ir;

int* yeetList;
int* anothaOne;
int yeetListPos;


void Initialise() {
	
	yeetList = malloc(1000 * sizeof(int));
	anothaOne = malloc(1000 * sizeof(int));
	yeetListPos = 0;

	for (int i = 0; i < 1000; i++) {
		yeetList[i] = -1;
		anothaOne[i] = -1;
	}

	VIDEO_Init();
	WPAD_Init();
	WPAD_SetVRes(0, 640, 480);
	WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);

	rmode = VIDEO_GetPreferredMode(NULL);
	
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
}

void DrawHLine (int x1, int x2, int y, int color) {
	int i;
	y = 320 * y;
	x1 >>= 1;
	x2 >>= 1;
	for (i = x1; i <= x2; i++) {
		u32 *tmpfb = xfb;
		tmpfb[y+i] = color;
	}
}

void DrawVLine (int x, int y1, int y2, int color) {
	int i;
	x >>= 1;
	for (i = y1; i <= y2; i++) {
		u32 *tmpfb = xfb;
		tmpfb[x + (640 * i) / 2] = color;
	}
}

void DrawBox (int x1, int y1, int x2, int y2, int color) {
	DrawHLine (x1, x2, y1, color);
	DrawHLine (x1, x2, y2, color);
	DrawVLine (x1, y1, y2, color);
	DrawVLine (x2, y1, y2, color);
}

void lettA(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettB(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettC(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettD(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettE(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettF(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettG(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 10+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettH(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettI(int posx, int posy) {
    DrawVLine(5 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettJ(int posx, int posy) {
    DrawVLine(5 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 5+posx, 20+posy, COLOR_GREEN);
}
void lettK(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(5 + posx, 0 + posy, 10 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 10+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettL(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}

void lettM(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0+posy, 20+posy, COLOR_GREEN);
    DrawVLine(5 + posx, 0+posy, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
}

void lettN(int posx, int posy) {
	DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
	DrawVLine(10 + posx, 0+posy, 20+posy, COLOR_GREEN);
	DrawVLine(5 + posx, 0+posy, 20+posy, COLOR_GREEN);
	DrawHLine(0+posx, 5+posx, 0+posy, COLOR_GREEN);
	DrawHLine(5+posx, 10+posx, 20+posy, COLOR_GREEN);
}

void lettO(int posx, int posy) {
	DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
	DrawVLine(10 + posx, 0+posy, 20+posy, COLOR_GREEN);
	DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
	DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}

void lettP(int posx, int posy) {
	DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
	DrawVLine(10 + posx, 0+posy, 10+posy, COLOR_GREEN);
	DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
	DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettQ(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 15 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0 + posy, 15 + posy, COLOR_GREEN);
    DrawVLine(7 + posx, 10 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 15+posy, COLOR_GREEN);
}
void lettR(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(5 + posx, 0 + posy, 10 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 10+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 5+posx, 0+posy, COLOR_GREEN);
}
void lettS(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 10 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 10+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettT(int posx, int posy) {
    DrawVLine(5 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
}
void lettU(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettV(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}
void lettW(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(5 + posx, 0 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}

void lettX(int posx, int posy) {
    DrawVLine(0 + posx, 10 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0+posy, 10+posy, COLOR_GREEN);
    DrawVLine(5 + posx, 0+posy, 20+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettY(int posx, int posy) {
    DrawVLine(0 + posx, 0 + posy, 10 + posy, COLOR_GREEN);
    DrawVLine(0 + posx, 0 + posy, 10 + posy, COLOR_GREEN);
    DrawVLine(5 + posx, 10 + posy, 20 + posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
}
void lettZ(int posx, int posy) {
    DrawVLine(0 + posx, 10 + posy, 20 + posy, COLOR_GREEN);
    DrawVLine(10 + posx, 0+posy, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 0+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 10+posy, COLOR_GREEN);
    DrawHLine(0+posx, 10+posx, 20+posy, COLOR_GREEN);
}

void drawLetter(int x, int y, int letter) {
    if (letter == 1){
       lettA (x, y);
    } else if (letter == 2) {
        lettB(x, y);
    } else if (letter == 3) {
        lettC(x, y);
    } else if (letter == 4) {
        lettD(x, y);
    } else if(letter == 5){
        lettE(x, y);
    } else if(letter == 6){
        lettF(x, y);
    } else if(letter == 7){
        lettG(x, y);
    } else if(letter == 8){
        lettH(x, y);
    } else if(letter == 9){
        lettI(x, y);
    } else if(letter == 10){
        lettJ(x, y);
    } else if(letter == 11){
        lettK(x, y);
    } else if(letter == 12){
        lettL(x, y);
    } else if(letter == 13){
        lettM(x, y);
    } else if(letter == 14){
        lettN(x, y);
    } else if (letter == 15) {
        lettO(x, y);
    } else if (letter == 16) {
        lettP(x, y);
    } else if(letter == 17){
        lettQ(x, y);
    } else if(letter == 18){
        lettR(x, y);
    } else if(letter == 19){
        lettS(x, y);
    } else if(letter == 20){
        lettT(x, y);
    } else if(letter == 21){
        lettU(x, y);
    } else if(letter == 22){
        lettV(x, y);
    } else if(letter == 23){
        lettW(x, y);
    } else if(letter == 24){
        lettX(x, y);
    } else if(letter == 25){
        lettY(x, y);
    } else if(letter == 26){
        lettZ(x, y);
    }
}
void DrawGrid(int posx, int posy, int sizex, int sizey, int boxpx, int boxpy, int margin) {
	int letterToDraw = 1;

	for (int y = 0; y < sizey; y ++) {
			for (int x = 0; x < sizex; x++) {
			DrawBox(
					posx + x * boxpx + margin,
					posy + y * boxpy + margin,
					posx + posx + x * boxpx + boxpx - margin,
					posy + y * boxpy + boxpy - margin,
					COLOR_GREEN
					);
			drawLetter(posx + x * boxpx + margin + 5,posy + y * boxpy + margin + 5, letterToDraw);
			letterToDraw++;
		}
	}
}

int checkHit(int x, int y) {
	if (((x - 50) % 75 <= 70) && ((y - 300) % 75 <= 70)) {
	    return (x - 50) / 75 + 10 * (y - 300) / 75;
	} else {
		return -1;
	}
}

int main() {
	
	Initialise();
	
	while(1) {
		
		WPAD_ScanPads();
		u32 pressed = WPAD_ButtonsDown(0);
		
		// IR Movement
		WPAD_IR(0, &ir);
		
		if (pressed & WPAD_BUTTON_HOME) {
			exit(0);
		}
		

		VIDEO_ClearFrameBuffer (rmode, xfb, COLOR_BLACK);


		if (pressed & WPAD_BUTTON_B) {
			//yeetList[yeetListPos] = ir.x;
			yeetList[yeetListPos] = checkHit(ir.x, ir.y);
			if (yeetList[yeetListPos] > -1) {
				yeetListPos++;

				if (yeetListPos > 1000) {
					yeetListPos = 0;
				}
			}
		}

		for (int i = 0; i < 1000; i++) {
			if (yeetList[i] > -1) {
				drawLetter(i * 15, 100, yeetList[i]);
			}
		}

		DrawBox (ir.x, ir.y, ir.x + 5, ir.y + 5, COLOR_WHITE);
		

		// 640 by 480
		// Keyboard is 9 keys across
		// A B C D E F G H I
		// J K L M N O P Q R
		// S T U V W X Y Z _
		// Each key is 70 pixels by 70 pixels

		DrawGrid(50, 300, 9, 3, 40, 40, 5);

//		// Top left
//		DrawBox(0,0,50,50, COLOR_WHITE);
//		// Bottom Left
//		DrawBox(0,380, 50, 480, COLOR_RED);
//		// Top right
//		DrawBox(540, 0, 640, 100, COLOR_GREEN);
//		// Bottom right
//		DrawBox(540, 380, 640, 480, COLOR_BLUE);

		VIDEO_WaitVSync();

	}
	
	return 0;
}
