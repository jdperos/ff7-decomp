#ifndef GAME_H
#define GAME_H

#include <common.h>
#include <libgpu.h>

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    s8 unkA;
    s8 unkB;
    s8 unkC;
    s8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
} Unk80026448;

typedef union {
    void* poly;
    POLY_FT4* ft4;
    SPRT* sprt;
    TILE* tile;
    TILE_1* tile1;
    BLK_FILL* blk_fill;
} Gpu;

extern u16 D_80062D7E;
extern s32 D_80062DCC;
extern Gpu D_80062F24;
extern s32 D_80062F58;
extern u_long* D_80062FC4;
extern s32 D_800756F8[];
extern s8 D_80077F64[][0x3400];
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern s32 D_8009A024[8];
extern s32 D_8009C6E4[0x54 / 4]; // memcard slot header?
extern u8 D_8009C778[];
extern u8 D_8009C798[];

void func_80026448(Unk80026448* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10,
                   s32 arg11, s32 arg12, u16 arg13);

// from overlays
extern s32 D_8019DAA0;
extern s32 D_8019D5E8;

#endif
