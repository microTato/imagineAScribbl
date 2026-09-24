#include <stdio.h>
#include <string.h>
#include <citro2d.h>
#include <3ds.h>
#include <stdlib.h>
#include <inttypes.h>
#define SCREEN_WIDTH  400 //50 printf chars for top, 40 for bottom
#define SCREEN_HEIGHT 240
float x = 200, y = 120, radius = 10;
int positions[18];
int lastPush;
int main()
{
	// ------------------ INIT STUFF ------------------
	// Create screens
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	PrintConsole bottomScreen;
	consoleInit(GFX_BOTTOM, &bottomScreen);
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	touchPosition touch;
	printf("Press A for a simple shape\nPress B for two simple shapes");
	u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);u32 clrClear = C2D_Color32(0x00, 0x00, 0x00, 0xFF);
	//gfxSet3D(true); //Uncomment if using stereoscopic 3D
	// ---- Main loop (use for things that refresh) ---
	while (aptMainLoop())
	{
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, clrClear);
		C2D_SceneBegin(top);
		//real fun starts here
		C2D_DrawLine(positions[0],positions[1], clrWhite,positions[2],positions[3], clrWhite, 5, 0);
		C2D_DrawLine(positions[2],positions[3], clrWhite,positions[4],positions[5], clrWhite, 5, 0);
		C2D_DrawLine(positions[4],positions[5], clrWhite,positions[6],positions[7], clrWhite, 5, 0);
		C2D_DrawLine(positions[6],positions[7], clrWhite,positions[8],positions[9], clrWhite, 5, 0);
		if (lastPush>0){
		C2D_DrawLine(positions[10],positions[11], clrWhite,positions[12],positions[13], clrWhite, 5, 0);
		C2D_DrawLine(positions[12],positions[13], clrWhite,positions[14],positions[15], clrWhite, 5, 0);
		C2D_DrawLine(positions[14],positions[15], clrWhite,positions[16],positions[17], clrWhite, 5, 0);
		}
		C3D_FrameEnd(0);
		//Get input
		hidScanInput();
        hidTouchRead(&touch);
		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		//REAL Code Starts Here
		if (kDown & KEY_A){
			lastPush=0;
			positions[1] = rand() % SCREEN_HEIGHT; //Optimisaiton? TF is that?
			positions[3] = rand() % SCREEN_HEIGHT;
			positions[5] = rand() % SCREEN_HEIGHT;
			positions[7] = rand() % SCREEN_HEIGHT;
			positions[9] = rand() % SCREEN_HEIGHT;
			positions[0] = rand() % SCREEN_WIDTH;
			positions[2] = rand() % SCREEN_WIDTH;
			positions[4] = rand() % SCREEN_WIDTH;
			positions[6] = rand() % SCREEN_WIDTH;
			positions[8] = rand() % SCREEN_WIDTH;
		}
		if (kDown & KEY_B){
			lastPush=1;
			positions[1] = rand() % SCREEN_HEIGHT;
			positions[3] = rand() % SCREEN_HEIGHT;
			positions[5] = rand() % SCREEN_HEIGHT;
			positions[7] = rand() % SCREEN_HEIGHT;
			positions[9] = rand() % SCREEN_HEIGHT;
			positions[11] = rand() % SCREEN_HEIGHT;
			positions[13] = rand() % SCREEN_HEIGHT;
			positions[15] = rand() % SCREEN_HEIGHT;
			positions[17] = rand() % SCREEN_HEIGHT;
			positions[0] = rand() % SCREEN_WIDTH;
			positions[2] = rand() % SCREEN_WIDTH;
			positions[4] = rand() % SCREEN_WIDTH;
			positions[6] = rand() % SCREEN_WIDTH;
			positions[8] = rand() % SCREEN_WIDTH;
			positions[10] = rand() % SCREEN_WIDTH;
			positions[12] = rand() % SCREEN_WIDTH;
			positions[14] = rand() % SCREEN_WIDTH;
			positions[16] = rand() % SCREEN_WIDTH;
		}
		if (kDown & KEY_X){
			lastPush=67;
		}
		if (kDown & KEY_START){
			break;} //Break in order to return to hbmenu
	}
	// ------------------------------------------------
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
