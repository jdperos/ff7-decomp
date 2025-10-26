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

typedef struct {
    u32 checksum;
    u8 leader_level;
    u8 party[3];
    s8 leader_name[0x10];
    s32 unk18;
    s32 unk1C;
    s32 gil;
    s32 time;
    s8 place_name[0x20];
    s32 menu_color[3];
} SaveHeder; // size: 0x54

typedef struct {
    SaveHeder header;
    /* 0x54 */ u8 save1[0xB28];
    /* 0xB7C */ s32 D_8009D260;
    /* 0xB80 */ u8 D_8009D264[0x3C];
    /* 0xBBC */ u16 D_8009D2A0;
    /* 0xBBE */ u8 D_8009D2A2;
    /* 0xBBF */ u8 D_8009D2A3;
    /* 0xBC0 */ u8 save2[0x518];
    /* 0x10D8 */ u8 battle_speed;
    /* 0x10D9 */ u8 battle_msg_speed;
    /* 0x10DA */ u16 config; // settings
    /* 0x10DC */ u8 button_config[16];
    /* 0x10EC */ u8 field_msg_speed;
    /* 0x10ED */ u8 D_8009D7D1;  // ??
    /* 0x10EE */ u16 D_8009D7D2; // ??
    /* 0x10F0 */ u32 D_8009D7D4;
} SaveWork; // size: 0x10F4

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    s32 unkCC;
    u8 unkD0[8];
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    s32 unkE4;
    s32 unkE8;
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
    s32 unkFC;
    s32 unk100[0x40];
    s32 unk200;
    s32 unk204;
    s32 unk208;
    s32 unk20C;
    s32 unk210;
    s32 unk214;
    s32 unk218;
    s32 unk21C;
    s32 unk220;
    s32 unk224;
    s32 unk228;
    s32 unk22C;
    s32 unk230;
    s32 unk234;
    s32 unk238;
    s32 unk23C;
    s32 unk240;
    s32 unk244;
} Unk800A8D04; // size: ???

extern u8 D_80049208[12];   // window colors maybe??
extern u8 D_800492F0[][12]; // see Labels enum
extern u16 D_80062D78;      // pressed button?
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
extern Unk800A8D04* D_80063014;
extern DRAWENV D_800706A4[2];
extern s32 D_800756F8[];
extern s8 D_80077F64[2][0x3400]; // polygon buffer
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
extern s32 D_8009A024[8];
extern SaveWork _work; // 0x8009C6E4
extern s8 D_8009D6F7;  // part of _work?
extern u8 D_8009CBDC[];

extern u8 D_8009C778[];  // big struct at least 0x1014 long, array of 0x84
extern u8 D_8009C798[];  // part of D_8009C778
extern s32 D_8009CE60[]; // very likely part of D_8009C778

s32 func_80014B70(void);
s32 func_80014BA8(s32 arg0);
void func_8001726C(s16, u16);
void func_80021044(DRAWENV* draw_env, DISPENV* disp_env);
void func_80026448(Unk80026448* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                   s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10,
                   s32 arg11, s32 arg12, u16 arg13);
void func_800269C0(void* poly);
s32 func_80026B70(unsigned char* str);
s32 func_80034B44();

// from overlays
extern s32 D_8019DAA0;
extern u_long* D_8019D5E8; // otag array

#endif
