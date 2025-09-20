#include "common.h"

typedef struct {
    s32 unk0;
    s8 unk4;
} Unk8002C5A8;

typedef struct {
    u8* unk0;
    s32 unk4;
    s8 unk8[0x20];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s8 unk3C[0x24];
    s16 unk60;
    s16 unk62;
    s16 unk64;
    u16 unk66;
    u32 unk68;
    u32 unk6C;
    u8 unk70[0x20];
    s16 unk90;
    s16 unk92;
    s16 unk94;
    s16 unk96;
    s16 unk98;
    s16 unk9A;
    s16 unk9C;
    s16 unk9E;
    s16 unkA0;
    s16 unkA2;
    s16 unkA4;
    s16 unkA6;
    s16 unkA8;
    s16 unkAA;
    s16 unkAC;
    s16 unkAE;
    u8 unkB0[0x10];
    u8 unkC0[0xC];
    s16 unkCC;
    s16 unkCE;
    s32 unkD0;
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
    s32 unkDC;
    s32 unkE0;
} Unk80031FC0;

typedef struct {
    u8 unk0[0x54];
    s16 unk54;
} Unk800335CC; // might be the same as Unk80031FC0

typedef struct {
    u8 unk0[0x6C];
    s16 unk6C;
} Unk800325B8;

typedef struct {
    u8 unk0[0x6C];
    s16 unk6C;
    s16 unk6E;
} Unk80032D44;

typedef struct {
    u8 unk0[0x38];
    s32 unk38;
} Unk80033788;

extern s16 D_80062F40;
extern s16 D_80062F48;
extern s32 D_80062FE4;
extern s32 D_80062FE8;
extern s16 D_8008337E;
extern s16 D_800833DE;
extern s32 D_80099788;
extern s32 D_80099998;
extern u8 D_80099BA8[];
extern s32 D_80099DB8;

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800293D0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800293F4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029424);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029464);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800294A4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800294BC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800297A4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029818);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002988C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029998);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800299C8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029A50);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029AF0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029B78);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029BAC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029C48);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029E98);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80029F44);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A094);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A28C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A43C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A510);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A6C4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A748);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A798);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A7E8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002A958);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002AABC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002AFB8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B1A8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B1F8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B2F8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B3B4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B5A8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B608);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B668);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B6AC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B730);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B7E0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B8B4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B904);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B958);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002B9AC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BA08);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BA5C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BA98);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BB20);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BBB4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BBEC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BC58);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BCCC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BD04);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BDCC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BE2C);

void func_8002BE8C(s32 arg0) { func_8002BCCC(arg0, D_80099BA8); }

void func_8002BEB4(s32 arg0) { func_8002BD04(arg0, D_80099BA8); }

void func_8002BEDC(s32 arg0) { func_8002BCCC(arg0, &D_80099998); }

void func_8002BF04(s32 arg0) { func_8002BD04(arg0, &D_80099998); }

void func_8002BF2C(s32 arg0) { func_8002BCCC(arg0, &D_80099788); }

void func_8002BF54(s32 arg0) { func_8002BD04(arg0, &D_80099788); }

void func_8002BF7C(s32 arg0) { func_8002BCCC(arg0, &D_80099DB8); }

void func_8002BFA4(s32 arg0) { func_8002BD04(arg0, &D_80099DB8); }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002BFCC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C004);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C0CC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C12C);

void func_8002C18C(s32 arg0) { func_8002BFCC(arg0, D_80099BA8); }

void func_8002C1B4(s32 arg0) { func_8002C004(arg0, D_80099BA8); }

void func_8002C1DC(s32 arg0) { func_8002BFCC(arg0, &D_80099998); }

void func_8002C204(s32 arg0) { func_8002C004(arg0, &D_80099998); }

void func_8002C22C(s32 arg0) { func_8002BFCC(arg0, &D_80099788); }

void func_8002C254(s32 arg0) { func_8002C004(arg0, &D_80099788); }

void func_8002C27C(s32 arg0) { func_8002BFCC(arg0, &D_80099DB8); }

void func_8002C2A4(s32 arg0) { func_8002C004(arg0, &D_80099DB8); }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C2CC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C300);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C3A8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C408);

void func_8002C468(s32 arg0) { func_8002C2CC(arg0, D_80099BA8); }

void func_8002C490(s32 arg0) { func_8002C300(arg0, D_80099BA8); }

void func_8002C4B8(s32 arg0) { func_8002C2CC(arg0, &D_80099998); }

void func_8002C4E0(s32 arg0) { func_8002C300(arg0, &D_80099998); }

void func_8002C508(s32 arg0) { func_8002C2CC(arg0, &D_80099788); }

void func_8002C530(s32 arg0) { func_8002C300(arg0, &D_80099788); }

void func_8002C558(s32 arg0) { func_8002C2CC(arg0, &D_80099DB8); }

void func_8002C580(s32 arg0) { func_8002C300(arg0, &D_80099DB8); }

void func_8002C5A8(Unk8002C5A8* arg0) {
    s32 n = arg0->unk4;
    D_80062F48 = 0;
    D_80062FE8 = n << 0x10;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C5C8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C634);

void func_8002C6A8(Unk8002C5A8* arg0) {
    s32 n = arg0->unk4;
    D_80062F40 = 0;
    D_80062FE4 = n << 0x10;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C6C8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C734);

void func_8002C7A8(void) { func_80029F44(); }

void func_8002C7C8(void) { func_8002A43C(); }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C7E8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C81C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C850);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C884);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C8C4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C8DC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002C9E4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CA84);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CB78);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CC18);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CC44);

void func_8002CCBC(void) { D_8008337E = 0; }

void func_8002CCCC(void) { D_800833DE = 0; }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CCDC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CDD0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CEC0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CF1C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CF78);

void func_8002CF98(void) {}

void func_8002CFA0() { func_80038FEC(0); }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002CFC0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D1E4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D2D4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D410);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D4A0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D530);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D668);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D7A0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002D8E8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002DA30);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002DA7C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002DF88);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002E1A8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002E23C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002E428);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002E478);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002E954);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002ED34);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002F24C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002F738);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002F848);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002FDA0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002FE48);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8002FF4C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80030038);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80030148);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80030234);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80030380);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800308D4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80030E7C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031820);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800318BC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031A70);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031AB0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031AFC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031BA0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031BE4);

void func_80031C88(Unk80031FC0* arg0) {
    arg0->unk2C = *arg0->unk0++;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031CB0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031CE0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031D6C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031E98);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031EEC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031F30);

void func_80031FC0(Unk80031FC0* arg0) {
    arg0->unk60 = *arg0->unk0++ << 8;
    arg0->unk62 = 0;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80031FF0);

void func_80032078(Unk80031FC0* arg0) { arg0->unk66 = *arg0->unk0++; }

void func_80032094(Unk80031FC0* arg0) { arg0->unk66 = (arg0->unk66 + 1) & 0xF; }

void func_800320AC(Unk80031FC0* arg0) {
    arg0->unk66 = (arg0->unk66 + 0xFFFF) & 0xF;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800320C4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032274);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800323CC);

void func_800324D8(Unk80031FC0* arg0) { arg0->unkCC = (s8)*arg0->unk0++; }

void func_80032500(Unk80031FC0* arg0) {
    arg0->unkCC = (s8)*arg0->unk0++ + arg0->unkCC;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8003252C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8003257C);

void func_800325B8(Unk800325B8* arg0) { arg0->unk6C = 0; }

void func_800325C0(Unk80031FC0* arg0) { arg0->unkCE = (s8)*arg0->unk0++; }

void func_800325E8(Unk80031FC0* arg0) {
    arg0->unkCE = (s8)*arg0->unk0++ + arg0->unkCE;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032614);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032718);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032770);

void func_800327E0(Unk80031FC0* arg0) {
    arg0->unkD6 = 0;
    arg0->unk38 &= ~1;
    arg0->unkE0 |= 0x10;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032804);

void func_800328D4(Unk80031FC0* arg0) { arg0->unk90 = *arg0->unk0++ << 8; }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800328F8);

void func_80032968(Unk80031FC0* arg0) {
    arg0->unkD8 = 0;
    arg0->unk38 &= ~2;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8003298C);

void func_80032A04(Unk80031FC0* arg0) { arg0->unk9E = *arg0->unk0++ << 7; }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032A28);

void func_80032A98(Unk80031FC0* arg0) {
    arg0->unkDA = 0;
    arg0->unk38 &= ~4;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032ABC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032B30);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032BB4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032C20);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032C8C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032CE8);

void func_80032D44(Unk80032D44* arg0) { arg0->unk6E = 1; }

void func_80032D50(void) {}

void func_80032D58(Unk80032D44* arg0) { arg0->unk6E = 4; }

void func_80032D64(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032D6C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032E08);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032E6C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032ED0);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032F34);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032F98);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80032FFC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033060);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800330C4);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033128);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800331CC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033224);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033264);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800332EC);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8003337C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033420);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_8003345C);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033488);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800334EC);

void func_80033534(Unk80033788* arg0) { arg0->unk38 &= ~8; }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033548);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033588);

void func_800335CC(void* arg0, Unk800335CC* arg1) { arg1->unk54 = 1; }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800335D8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033628);

void func_8003366C(Unk80031FC0* arg0) {
    s16 var_v0 = *arg0->unk0++;
    if (var_v0 == 0) {
        var_v0 = 0x101;
    } else {
        var_v0++;
    }
    arg0->unkA4 = var_v0;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033698);

void func_800336DC(Unk80031FC0* arg0) {
    s16 var_v0 = *arg0->unk0++;
    if (var_v0 == 0) {
        var_v0 = 0x101;
    } else {
        var_v0++;
    }
    arg0->unkA6 = var_v0;
}

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033708);

void func_80033788(Unk80033788* arg0) { arg0->unk38 |= 0x10; }

void func_8003379C(Unk80033788* arg0) { arg0->unk38 &= ~0x10; }

void func_800337B0(Unk80033788* arg0) { arg0->unk38 |= 0x20; }

void func_800337C4(Unk80033788* arg0) { arg0->unk38 &= ~0x20; }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_800337D8);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033818);

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033894);

void func_80033A70() { func_80033894(); }

INCLUDE_ASM("asm/us/main/nonmatchings/akao", func_80033A90);
