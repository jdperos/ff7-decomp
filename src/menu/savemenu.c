//! PSYQ=3.3 CC1=2.7.2
#include <game.h>

const char D_801D0050[] = "BASCUS-94163FF7-S15";
const char D_801D0064[] = "BASCUS-94163FF7-S14";
const char D_801D0078[] = "BASCUS-94163FF7-S13";
const char D_801D008C[] = "BASCUS-94163FF7-S12";
const char D_801D00A0[] = "BASCUS-94163FF7-S11";
const char D_801D00B4[] = "BASCUS-94163FF7-S10";
const char D_801D00C8[] = "BASCUS-94163FF7-S09";
const char D_801D00DC[] = "BASCUS-94163FF7-S08";
const char D_801D00F0[] = "BASCUS-94163FF7-S07";
const char D_801D0104[] = "BASCUS-94163FF7-S06";
const char D_801D0118[] = "BASCUS-94163FF7-S05";
const char D_801D012C[] = "BASCUS-94163FF7-S04";
const char D_801D0140[] = "BASCUS-94163FF7-S03";
const char D_801D0154[] = "BASCUS-94163FF7-S02";
const char D_801D0168[] = "BASCUS-94163FF7-S01";

extern const char D_801D018C[];
extern const char D_801D0194[];
extern s32 D_801D4EC4;
extern s32 D_801D4EDC[];
extern const char* D_801E2C78[];
extern s32 D_801E2CB4;
extern const char* D_801E2CB8[];
extern s32 D_801E2CF4;
extern s32 D_801E2CF8;
extern s32 D_801E368C[];
extern s32 D_801E3698;
extern s32 D_801E36B0;
extern s32 D_801E36B8;
extern s32 D_801E36B4;
extern s8 D_801E36BC[][0x5C];
extern s8 D_801E3774[][0x14];
extern s32* D_801E3854;
extern s32 D_801E3858[2];
extern s32 D_801E3864[][0x54 / 4];
extern s32 D_801E3D50;
extern s32 D_801E3D54;
extern s32 D_801E3D58; // backbuffer id?
extern u8* D_801E3D5C; // maybe OT?
extern u8 D_801E3D60[][0x10];
extern Unk80026448 D_801E3DFE[];
extern u8 D_801E3E34[][0x5C]; // list of primitives?
extern s8 D_801E3E90[];
extern u8 D_801E3EEC[][20];
extern s32 D_801E3F00;
extern s32 D_801E3F2C[];
extern s32 D_801E4538[];
extern Unk80026448 D_801E379C[];
extern u8 D_801E8F38[2][3];
extern s32 D_801E3850;
extern s32 D_801E3860;
extern s32 D_801E8F44[];

void func_801D19C4(void);
void func_801D1BA4(void);

void func_801D0408(u16 arg0) {
    D_8009A000 = 0x30;
    D_8009A004 = arg0;
    D_8009A008 = arg0;
    func_8002DA7C(arg0);
}

s32 func_801D0448(s32 arg0) {
    RECT rect;

    setTile(D_80062F24.tile);
    SetSemiTrans(D_80062F24.tile, 1);
    D_80062F24.tile->x0 = 0;
    D_80062F24.tile->y0 = 0;
    D_80062F24.tile->w = 0x180;
    D_80062F24.tile->h = 0xE8;
    D_80062F24.tile->r0 = D_801D4EC4;
    D_80062F24.tile->g0 = D_801D4EC4;
    D_80062F24.tile->b0 = D_801D4EC4;
    AddPrim(D_80062FC4, D_80062F24.tile++);
    rect.x = 0;
    rect.y = 0;
    rect.w = 255;
    rect.h = 255;
    func_80026A34(0, 1, 0x5F, &rect);
    D_801D4EC4 += arg0;
    if (D_801D4EC4 < 0) {
        D_801D4EC4 = 0;
    }
    if (D_801D4EC4 >= 0x100) {
        D_801D4EC4 = 0xFF;
    }
    return D_801D4EC4;
}

void func_801D05C0(u8 arg0) {
    D_801E3860 = 0xF0;
    D_801E36B8 = arg0;
    D_801E3850 = 0;
    func_80026448(D_801E379C, 0, 0, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0);
    func_80025B8C(&D_801E8F44);
    func_80025C14(&D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

void func_801D0670(void) {
    func_80025BD0(D_801E8F44);
    func_80025C54(D_801E4538);
    func_801D1BA4();
}

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D06B0);

s32 func_801D1774(void) {
    s32 ret;
    s32 i;

    func_80021044(D_801E36BC, D_801E3774);
    i = 0;
    D_801E36B0 = 0;
    func_801D05C0(1);
    D_801E36B4 = 0;
    while (1) {
        func_8001CB48();
        func_800269C0(D_80077F64[D_801E36B4]);
        D_801E3854 = &D_801E3858[D_801E36B4];
        func_8004418C(D_801E3854, 1);
        func_80026A00(D_801E3854);
        func_8001F710();
        ret = func_801D06B0(i);
        if (D_801E36B0 == -1) {
            break;
        }
        func_80043DD8(0);
        VSync(0);
        func_800444AC(D_801E3774[D_801E36B4]);
        func_800443B0(D_801E36BC[D_801E36B4]);
        func_8004433C(D_801E3854);
        D_801E36B4 ^= 1;
        i++;
    }
    func_801D0670();
    VSync(0);
    func_800444AC(D_801E3774[0]);
    func_800443B0(D_801E36BC[0]);
    VSync(0);
    func_800444AC(D_801E3774[1]);
    func_800443B0(D_801E36BC[1]);
    return ret;
}

u16 func_801D1950(u16 len, u8* data) {
    u16 i, j;
    s32 sum = 0xFFFF;
    for (i = 0; i < len; i++) {
        sum ^= *(data + i) << 8;
        for (j = 0; j < 8; j++) {
            if (sum & 0x8000) {
                sum = (sum * 2) ^ 0x1021;
            } else {
                sum *= 2;
            }
        }
    }
    return ~sum;
}

void func_801D19C4(void) {
    s32 i;

    if (D_80062DCC == 0) {
        i = 0;
        EnterCriticalSection();
        D_8009A024[0] = OpenEvent(0xF4000001, 0x0004, 0x2000, 0);
        D_8009A024[1] = OpenEvent(0xF4000001, 0x8000, 0x2000, 0);
        D_8009A024[2] = OpenEvent(0xF4000001, 0x0100, 0x2000, 0);
        D_8009A024[3] = OpenEvent(0xF4000001, 0x2000, 0x2000, 0);
        D_8009A024[4] = OpenEvent(0xF0000011, 0x0004, 0x2000, 0);
        D_8009A024[5] = OpenEvent(0xF0000011, 0x8000, 0x2000, 0);
        D_8009A024[6] = OpenEvent(0xF0000011, 0x0100, 0x2000, 0);
        D_8009A024[7] = OpenEvent(0xF0000011, 0x2000, 0x2000, 0);
        InitCARD(1);
        func_80048A44();
        ChangeClearPAD(0);
        _bu_init();
        _card_auto(0);
        for (; i < 8; i++) {
            EnableEvent(D_8009A024[i]);
        }
        ExitCriticalSection();
        D_80062DCC = 1;
    }
    for (i = 0; i < 2; i++) {
        D_801E8F38[i][0] = 0;
        D_801E8F38[i][1] = 0;
        D_801E8F38[i][2] = 0;
    }
}

void func_801D1BA4(void) {}

void func_801D1BAC(s32 arg0, s32 arg1) {
    TestEvent(D_8009A024[arg1], arg1 * 4);
}

// strcmp?
s32 func_801D1BE0(u8* arg0, u8* arg1) {
    while (1) {
        if (*arg0++ != *arg1++) {
            return 0;
        }
        if (!*arg0 && !*arg1) {
            return 1;
        }
    }
}

#ifndef NON_MATCHINGS
INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D1C2C);
#else
u16 func_801D1C2C(s32 arg0) {
    DIRENTRY sp10;
    const char* memcard;
    s32 i;
    DIRENTRY* entry;
    u16 var_s3;

    var_s3 = 0;
    i = 0;
    while (1) {
        memcard = &D_801D0184;
        if (arg0) {
            memcard = &D_801D017C;
        }
        entry = firstfile2(memcard, &sp10);
        if (entry) {
            break;
        }
        i++;
        if (i >= 100) {
            var_s3 = 0;
            goto end;
        }
    }
    while (entry) {
        for (i = 0; i < 15; i++) {
            if (func_801D1BE0(entry->name, D_801E2C78[i]) != 0) {
                var_s3 |= 1 << i;
            }
        }
        entry = nextfile(entry);
    }
end:
    return var_s3;
}
#endif

const char D_801D018C[] = "bu10:%s";
const char D_801D0194[] = "bu00:%s";

s32* func_801D1D1C(s32 arg0) { return D_801E3864[arg0]; }

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D1D40);

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D1F40);

s32 func_801D2150(s8 arg0) {
    if (arg0 > -0x68 && arg0 < -0x60 || arg0 > -32 && arg0 < -3) {
        return 1;
    }
    return 0;
}

s32 func_801D2184(s8 arg0) {
    if (arg0 > -0x80 && arg0 < -0x60 || arg0 > -33 && arg0 < -3) {
        return 1;
    }
    return 0;
}

void func_801D21B8(u8* arg0, u8* arg1) {
    s32 i;
    for (i = 0; i < 0x40; i++) {
        *arg0++ = *arg1++;
    }
}

void func_801D21E0(s32 arg0) { D_801E2CB4 = arg0; }

void func_801D21F0(u8* arg0, u8* arg1) {
    s32 i;
    for (i = 0; i < D_801E2CB4; i++) {
        *arg0++ = *arg1;
        if (*arg1 == 0xFF) {
            break;
        }
        arg1++;
    }
}

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D224C);

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D2408);

// clang-format off
// most likely the memcard title in shift-jis format
const s16 D_801D019C[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x5082, 0x5482, 0x5E81, 0x5082, 0x5082, 0x4681, 0x5082, 0x5082, 0, 0};
const s16 D_801D01C0[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x5082, 0x5382, 0x5E81, 0x5082, 0x5082, 0x4681, 0x5082, 0x5082, 0, 0};
const s16 D_801D01E4[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x5082, 0x5282, 0x5E81, 0x5082, 0x5082, 0x4681, 0x5082, 0x5082, 0, 0};
const s16 D_801D0208[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x5082, 0x5182, 0x5E81, 0x5082, 0x5082, 0x4681, 0x5082, 0x5082, 0, 0};
const s16 D_801D022C[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x5082, 0x5082, 0x5E81, 0x5082, 0x5082, 0x4681, 0x5082, 0x5082, 0, 0};
const s16 D_801D0250[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x5082, 0x4F82, 0x5E81, 0x5082, 0x5082, 0x4681, 0x5082, 0x5082, 0, 0};
const s16 D_801D0274[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5882, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D0298[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5782, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D02BC[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5682, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D02E0[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5582, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D0304[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5482, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D0328[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5382, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D034C[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5282, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D0370[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5182, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
const s16 D_801D0394[] = {0x6582, 0x6582, 0x5682, 0x5E81, 0x7282, 0x6082, 0x7582, 0x6482, 0x4F82, 0x5082, 0x5E81, 0x4F82, 0x4F82, 0x4681, 0x4F82, 0x4F82, 0, 0};
// clang-format on

s16 func_801D2A34(s32 save_id) {
    char sp10[0x40];
    s32 ret;
    s32 slot;

    if (save_id & 0x10) {
        func_80042DD8(&sp10, D_801D018C, D_801E2C78[save_id & 15]);
    } else {
        func_80042DD8(&sp10, D_801D0194, D_801E2C78[save_id & 15]);
    }
    slot = save_id & 15;
    D_801E3D50 = slot;
    ret = func_801D2408(&sp10, D_801E2CB8[slot]);
    if (!(s16)ret) {
        __builtin_memcpy(&D_801E3864[slot], D_8009C6E4, 0x54);
    }
    return ret;
}

void func_801D2B58(u16 arg0) {
    D_8009A000 = 0x30;
    D_8009A004 = arg0;
    D_8009A008 = arg0;
    func_8002DA7C();
}

s32 func_801D2B98(s32 arg0) {
    RECT rect;

    setTile(D_80062F24.tile);
    SetSemiTrans(D_80062F24.tile, 1);
    D_80062F24.tile->x0 = 0;
    D_80062F24.tile->y0 = 0;
    D_80062F24.tile->w = 0x180;
    D_80062F24.tile->h = 0xE8;
    D_80062F24.tile->r0 = (u8)D_801E2CF4;
    D_80062F24.tile->g0 = (u8)D_801E2CF4;
    D_80062F24.tile->b0 = (u8)D_801E2CF4;
    AddPrim(D_80062FC4, D_80062F24.tile++);
    rect.x = 0;
    rect.y = 0;
    rect.w = 255;
    rect.h = 255;
    func_80026A34(0, 1, 0x5F, &rect);
    D_801E2CF4 += arg0;
    if (D_801E2CF4 < 0) {
        D_801E2CF4 = 0;
    }
    if (D_801E2CF4 >= 0x100) {
        D_801E2CF4 = 0xFF;
    }
    return D_801E2CF4;
}

void func_801D2D10(s32 arg0) {
    switch (arg0) {
    case 0:
        D_8009A000 = 0x81;
        D_8009A004 = 0x81;
        D_8009A008 = 0x81;
        break;
    case 1:
        D_8009A000 = 0x80;
        D_8009A004 = 0x80;
        D_8009A008 = 0x80;
        break;
    case 2:
        D_8009A000 = 0x82;
        D_8009A004 = 0x82;
        D_8009A008 = 0x82;
        break;
    }
    func_8002DA7C();
}

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D2DA8);

void func_801D32C0(void) {
    TestEvent(D_8009A024[0]);
    TestEvent(D_8009A024[1]);
    TestEvent(D_8009A024[2]);
    TestEvent(D_8009A024[3]);
}

void func_801D3318(void) {
    TestEvent(D_8009A024[4]);
    TestEvent(D_8009A024[5]);
    TestEvent(D_8009A024[6]);
    TestEvent(D_8009A024[7]);
}

s32 func_801D3370(void) {
    while (1) {
        if (TestEvent(D_8009A024[0]) == 1) {
            return 0;
        }
        if (TestEvent(D_8009A024[1]) == 1) {
            return 1;
        }
        if (TestEvent(D_8009A024[2]) == 1) {
            return 2;
        }
        if (TestEvent(D_8009A024[3]) == 1) {
            return 3;
        }
    }
}

s32 func_801D33F4(void) {
    while (1) {
        if (TestEvent(D_8009A024[4]) == 1) {
            return 0;
        }
        if (TestEvent(D_8009A024[5]) == 1) {
            return 1;
        }
        if (TestEvent(D_8009A024[6]) == 1) {
            return 2;
        }
        if (TestEvent(D_8009A024[7]) == 1) {
            return 3;
        }
    }
}

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D3478);

void func_801D3668(s32 arg0) {
    if (!(arg0 & 0x3F)) {
        func_801D3478(0);
        func_801D3478(1);
    }
}

s32 func_801D3698(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 i;
    s32 ret;

    for (i = 0; i < 0x14; i++) {
        var_a0 = arg1;
        if (arg0) {
            var_a0 |= 0x10;
        }
        if (func_801D1D40(var_a0) == 0) {
            ret = 0;
            break;
        }
        ret = 1;
    }
    return ret;
}

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D370C);

void func_801D39C4(void) {
    D_801E3698 = 0;
    D_801E2CF8 = 7;
    func_8001DEF0(&D_801E368C);
    func_80025D14(&D_801D4EDC, 0x380, 0, 0, 0x1E0);
    func_80043DD8(0);
    func_80026448(D_801E3DFE, 0, 1, 1, 2, 0, 0, 1, 2, 0, 0, 0, 1, 0);
    func_80025CD4(&D_801E3F2C);
    func_80025B8C(&D_801E8F44);
    func_80025C14(&D_801E4538);
    func_80025DF8();
    func_801D19C4();
}

INCLUDE_ASM("asm/us/menu/nonmatchings/savemenu", func_801D3AB0);

void func_801D4C38(void) {
    func_80025ED4();
    func_80025CD4(D_800756F8);
    func_80025C94(D_801E3F2C);
    func_80025BD0(D_801E8F44);
    func_80025C54(D_801E4538);
    func_801D1BA4();
    func_800444AC(D_801E3EEC);
    func_800443B0(D_801E3E34);
}

// title screen loop?
s32 func_801D4CC0(void) {
    s32 i;
    s32 ret;

    func_80021044(D_801E3E34, D_801E3EEC);
    D_801E3D54 = 0;
    func_801D39C4();
    D_801E3D58 = 0;
    for (i = 0;; i++) {
        func_8001CB48();
        func_800269C0(D_80077F64[D_801E3D58]);
        D_801E3D5C = D_801E3D60[D_801E3D58];
        func_8004418C(D_801E3D5C, 1);
        func_80026A00(D_801E3D5C);
        func_8001F710();
        ret = func_801D3AB0(i);
        if (D_801E3D54 == -1) {
            break;
        }
        func_80043DD8(0);
        VSync(0);
        func_800444AC(D_801E3EEC[D_801E3D58]);
        func_800443B0(D_801E3E34[D_801E3D58]);
        func_8004433C(D_801E3D5C);
        D_801E3D58 ^= 1; // flip back buffer ID?
    }
    func_801D4C38();
    VSync(0);
    func_800444AC(&D_801E3F00);
    func_800443B0(D_801E3E90);
    for (i = 0; i < 3; i++) {
        if (D_8009CBDC[i] != 0xFF) {
            func_80020058(i);
            func_8001786C((u8)i);
        }
    }
    func_80017678();
    return ret;
}
