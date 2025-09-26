#include <game.h>

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
} SaveHeder;

typedef struct {
    // this whole thing might be a D_801E379C[6]
    /* 0x00 */ Unk80026448 D_801E379C[2];
    /* 0x24 */ u8 unk24[0x40];
    /* 0x64 */ s32 D_801E3800;
    /* 0x68 */ s32 D_801E3804;
    /* 0x6C */ Unk80026448 D_801E3808[2];
} Menus; // size: 0x90

extern const char D_801D018C[];
extern const char D_801D0194[];
extern s32 D_801D4EC4;
extern RECT D_801D4EC8;
extern RECT D_801D4ED0;
extern u8 D_801D4EDC[];
extern u8 D_801E2D20;
extern u8 D_801E2D44[]; // string
extern u8 D_801E2D68;
extern u8 D_801E2DF8;
extern u8 D_801E2E1C;
extern u8 D_801DEEDC;
extern s32 D_801DEEF4;
extern RECT D_801DEEFC;
extern u8 D_801E31A0;
extern u8 D_801E2EAC[];
extern const char* D_801E2C78[];
extern s32 D_801E2CB4;
extern const char* D_801E2CB8[];
extern s32 D_801E32C0;
extern s32 D_801E32F0;
extern u8 D_801E3320[][0x30];
extern s32 D_801E2CF4;
extern u32 D_801E2CF8;
extern s32 D_801E30EC;
extern u8 D_801E3380[]; // "No Memory card"
extern u8 D_801E33B0[]; // "No Memory card"
extern s32 D_801E3440;
extern s32 D_801E3530;
extern RECT D_801E3650[3];
extern s32 D_801E36A0;
extern s32 D_801E36A4;
extern s32 D_801E36A8;
extern s32 D_801E36AC;
extern s32 D_801E368C[];
extern u8 D_801E3684[]; // "Level" label
extern s32 D_801E3698;
extern s32 D_801E36B0;
extern s32 D_801E36B8;
extern s32 D_801E36B4;
extern s8 D_801E36BC[2][0x5C];
extern s8 D_801E3774[2][0x14];
extern Menus menus;
extern s32* D_801E3854;
extern s32 D_801E3858[2];
extern s32 D_801E3864[][0x54 / 4];
extern s32 D_801E3D50;
extern s32 D_801E3D54;
extern s32 D_801E3D58; // backbuffer id?
extern u8* D_801E3D5C; // maybe OT?
extern u8 D_801E3D60[][0x10];
extern Unk80026448 D_801E3DFE[2];
extern u8 D_801E3E34[][0x5C]; // list of primitives?
extern s8 D_801E3E90[];
extern u8 D_801E3EEC[][20];
extern s32 D_801E3F00;
extern s32 D_801E3F2C[];
extern s32 D_801E4538[];
extern u8 D_801E8F38[2][3];
extern s32 D_801E3850;
extern s32 D_801E3860;
extern u8 D_801E8F3B;
extern s32 D_801E8F44[];
extern u8 D_801E2CFC;
extern u8 D_801E2DD4;
extern u8 D_801E2E88;
extern u8 D_801E3158;
extern u8 D_801E317C[]; // "New game"
extern RECT D_801E3668;
extern s16 D_801E366A;
extern s16 D_801E366E;
extern Unk80026448 D_801E3D80[2];
extern s32 D_801E3F14;
extern s32 D_801E3F18;
extern s32 D_801E3F1C;
extern s32 D_801E3F20;
extern s32 D_801E3660;
extern u8 D_801E2E64[]; // "Continue?"

void func_801D19C4(void);
void func_801D1BA4(void);
s16 func_801D2A34(s32 save_id);
void func_801D3668(s32 arg0);
void func_801D370C(s32 x, s32 y, s32 slot_no);
