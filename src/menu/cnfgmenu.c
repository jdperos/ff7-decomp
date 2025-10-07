//! PSYQ=3.3 CC1=2.7.2
#include <game.h>

extern s32 D_801D1AA8;
extern s16 D_801D24AA;
extern u8 D_801D1AAC[];
extern u8 D_801D248C[];
extern Unk80026448 D_801D24CC[4];
extern u8 D_801D252C[];

u8 D_801D1ADC[] = {0x05, 0x06, 0x04, 0x07, 0x02, 0x03,
                   0x00, 0x01, 0x08, 0x0B, 0x00, 0x00};
unsigned char D_801D1AE8[][0x30] = {
    _S("Window color"),   // 0
    _S("Sound"),          // 1
    _S("Controller"),     // 2
    _S("Cursor"),         // 3
    _S("ATB"),            // 4
    _S("Battle speed"),   // 5
    _S("Battle message"), // 6
    _S("Field message"),  // 7
    _S("Camera angle"),   // 8
    _S("Select"),         // 9
    _S("Cancel"),         // 10
    _S("Menu"),           // 11
    _S("Window OFF"),     // 12
    _S("Pause"),          // 13
    _S("Battle help"),    // 14
    _S("Mono"),           // 15
    _S("Stereo"),         // 16
    _S("Wide"),           // 17
};
unsigned char D_801D1E48[][0x30] = {
    _S("Normal"),
    _S("Customize"),
};
unsigned char D_801D1EA8[][0x30] = {
    _S("Initial"),
    _S("Memory"),
};
unsigned char D_801D1F08[][0x30] = {
    _S("Active"),      // 0
    _S("Recommended"), // 1
    _S("Wait"),        // 2
    _S("Auto"),        // 3
    _S("Fix"),         // 4
    _S(""),            // 5
    _S("Slow"),        // 6
    _S("Fast"),        // 7
    _S("RED"),         // 8
    _S("GREEN"),       // 9
    _S("BLUE"),        // 10
};
unsigned char D_801D2118[][0x30] = {
    _S("Magic order"), //
};
unsigned char D_801D2148[][0x30] = {
    _S("restore"),   // 0
    _S("attack"),    // 1
    _S("indirect"),  // 2
    _S("forbidden"), // 3
    _S("No."),       // 4
};
unsigned char D_801D2238[][0x30] = {
    _S("Left2"),  // 0
    _S("Right2"), // 1
    _S("Left1"),  // 2
    _S("Right1"), // 3
    _S("Menu"),   // 4
    _S("Select"), // 5
    _S("Cancel"), // 6
    _S("EXT"),    // 7
    _S("Help"),   // 8
};
unsigned char D_801D23E8[][0x30] = {
    {0x30, 0x52, 0x45, 0x53, 0x53, 0x00, 0xB2, 0x33, 0x34, 0x21, 0x32, 0x34,
     0xB3, 0x00, 0x54, 0x4F, 0x00, 0x43, 0x55, 0x53, 0x54, 0x4F, 0x4D, 0x49,
     0x5A, 0x45, 0x0E, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
};
unsigned char D_801D2418[][0x30] = {
    _S("Press Directional button Left or Right to end."),
    _S("Pause"),
};

void func_801D0040(u16 arg0) {
    D_8009A000 = 0x30;
    D_8009A004 = arg0;
    D_8009A008 = arg0;
    func_8002DA7C(arg0);
}

void func_801D0080(s32 arg0) {
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

u8 func_801D0118(u16 arg0) {
    s32 i;
    for (i = 0; i < 12; i++) {
        if ((arg0 >> i) & 1) {
            return i;
        }
    }
    return 0xFF;
}

#ifndef NON_MATCHINGS
INCLUDE_ASM("asm/us/menu/nonmatchings/cnfgmenu", func_801D014C);
#else
void func_801D014C(s16 x, s16 y, s32 value) {
    func_80028CA0(x, y, (D_801D1AAC[value * 2 + 0] & 3) * 0x10 + 0x60,
                  (D_801D1AAC[value * 2 + 0] >> 2) * 0x10 + 0x40, 0x10, 0x10,
                  D_801D1AAC[value * 2 + 1], 0);
}

#endif

INCLUDE_ASM("asm/us/menu/nonmatchings/cnfgmenu", func_801D01C8);

void func_801D069C(void) {
    volatile s32 dummy;
    s32 i;
    func_80026448(&D_801D24CC[0], 0, 0, 1, 10, 0, 0, 1, 10, 0, 0, 0, 1, 0);
    func_80026448(&D_801D24CC[1], 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 1, 1, 0);
    func_80026448(&D_801D24CC[2], 0, 0, 1, 3, 0, 0, 1, 3, 0, 0, 0, 1, 0);
    func_80026448(&D_801D24CC[3], 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0);
    D_801D1AA8 = 0;
    for (i = 0; i < 12; i++) {
        D_801D252C[i] = D_80049208[i];
    }
}

INCLUDE_ASM("asm/us/menu/nonmatchings/cnfgmenu", func_801D080C);

void func_801D1AA0(void) {}
