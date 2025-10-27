#include <game.h>

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s8 unkC;
    u8 unkD;
    s8 unkE;
    s8 unkF;
    s8 unk10;
    s8 unk11;
    s16 unk12;
    s8 unk14;
    s8 unk15;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s32 unk24;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s32 unk30;
    u32 unk34[4];
    u32 unk44[9];
} Unk800F83E0; // size:0x68
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s32 unkC;
} UnkStruct; // size:0x10
typedef struct {
    s16 unk0;
    u8 unk2;
    u8 unk3;
    /* 0x04 */ u8 unk4[0x30];
    /* 0x34 */ UnkStruct unk34[6];
    /* 0x94 */ u8 unk94[6][0x10];
} Unk801B2308;

extern u16 D_800F5BBC[10][0x22];
extern u8 D_800F5E66[3][0x34];
extern s8 D_800F6936[0x40][8];
extern u16 D_800F7DA6[4];
extern u8 D_800F83A8;
extern s16 D_800F83AE[10][0x34]; // overlaps with D_800F83E0
extern s16 D_800F83CC;           // overlaps with D_800F83AE
extern Unk800F83E0 D_800F83E0[3];
