#ifndef GAME_H
#define GAME_H

#include <common.h>
#include <libgpu.h>

#ifndef FF7_STR
#define _S(x) x       // check the usage of 'bin/str' to see how this works
#define _SL(len, x) x // same as _S, but for fixed-length strings with padding
#endif

typedef unsigned char ff7s[];

typedef enum {
    LABEL_TIME,
    LABEL_GIL,
} Labels;

typedef struct {
    s16 unk0;
    s16 unk2; // current page
    s16 unk4;
    s16 unk6; // total item count
    s16 unk8;
    s8 unkA;
    s8 unkB; // selected element
    s8 unkC;
    s8 unkD; // elements per page
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;  // scroll type: 0=no wrap, 1/2:wrap, 3>:infinite
} Unk80026448; // size: 0x12

typedef union {
    void* poly;
    POLY_FT4* ft4;
    SPRT* sprt;
    TILE* tile;
    TILE_1* tile1;
    BLK_FILL* blk_fill;
} Gpu;

extern u8 D_800492F0[][12]; // see Labels enum
extern u16 D_80062D7C;      // pressed button?
extern u16 D_80062D7E;      // pressed button?
extern u16 D_80062D80;      // tapped button
extern u16 D_80062D82;      // repeated button
extern s8 D_80062D99;
extern s32 D_80062DCC;
extern Gpu D_80062F24;
extern u16 D_80062F3C;
extern s32 D_80062F58;
extern u_long* D_80062FC4;
extern DRAWENV D_800706A4[2];
extern s32 D_800756F8[];
extern s8 D_80077F64[2][0x3400]; // polygon buffer
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern s32 D_8009A024[8];
extern s32 D_8009C6E4[0x54 / 4]; // memcard slot header?
extern u16 D_8009D7BE;
extern u8 D_8009CBDC[];
extern u8 D_8009C778[];
extern u8 D_8009C798[];

void func_80021044(DRAWENV* draw_env, DISPENV* disp_env);
void func_80026448(Unk80026448* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10,
                   s32 arg11, s32 arg12, u16 arg13);

// from overlays
extern s32 D_8019DAA0;
extern u_long* D_8019D5E8; // otag array

#endif
