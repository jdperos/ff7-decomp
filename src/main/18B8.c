#include <game.h>

typedef enum {
    LBA_INIT_YAMADA = 614,
} Lba;

typedef enum {
    INIT_YAMADA,
    INIT_WINDOW,
    INIT_KERNEL,
    BATTLE_BROM,
    BATTLE_TITLE,
    BATTLE_BATTLE,
    BATTLE_BATINI,
    BATTLE_SCENE,
    BATTLE_BATRES,
    BATTLE_CO,
    YAMADA_FILE_NUM,
} YamadaFile;

typedef enum {
    KERNEL_COMMAND,
    KERNEL_ATTACK,
    KERNEL_GROWTH,
    KERNEL_INIT,
    KERNEL_ITEM,
    KERNEL_WEAPON,
    KERNEL_ARMOR,
    KERNEL_ACCESSORY,
    KERNEL_MATERIA,
    KERNEL_DESC_COMMAND,
    KERNEL_DESC_MAGIC,
    KERNEL_DESC_ITEM,
    KERNEL_DESC_WEAPON,
    KERNEL_DESC_ARMOR,
    KERNEL_DESC_ACCESSORY,
    KERNEL_DESC_MATERIA,
    KERNEL_DESC_KEY_ITEM,
    KERNEL_NAME_COMMAND,
    KERNEL_NAME_MAGIC,
    KERNEL_NAME_ITEM,
    KERNEL_NAME_WEAPON,
    KERNEL_NAME_ARMOR,
    KERNEL_NAME_ACCESSORY,
    KERNEL_NAME_MATERIA,
    KERNEL_NAME_KEY_ITEM,
    KERNEL_TEXT_BATTLE,
    KERNEL_NAME_SUMMON,
} KernelID;

typedef struct {
    s32 loc; // disk sector where the file can be found
    s32 len; // file size in bytes
} Yamada;

typedef struct {
    s32 len; // decompressed length
    s32 unk4;
} GzHeader;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk8001DE0C;

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
    u8 unk0[0x6C];
    s16 unk6C;
    s16 unk6E;
} Unk80032D44;

typedef struct {
    u8 unk0[0x38];
    s32 unk38;
} Unk80033788;

typedef struct {
    u8 unk0[0x6C];
    s16 unk6C;
} Unk800325B8;

typedef struct {
    u8 unk0[0x54];
    s16 unk54;
} Unk800335CC; // might be the same as Unk80031FC0

typedef struct {
    s32 unk0;
    s8 unk4;
} Unk8002C5A8;

extern s32 D_80010100[];
extern s32 D_80048CFC;
extern s32 D_80048D00;
extern s32 D_80048D04;
extern s32 D_80048D08;
extern s32 D_80048D0C;
extern s32 D_80048D10;
extern Yamada D_80048D84[];
extern s32 D_80048DD4[];
extern s16 D_80062F40;
extern s16 D_80062F48;
extern s32 D_80062FE4;
extern s32 D_80062FE8;
extern u8 D_80063690[];
extern u16 D_80069490[];
extern u16 D_800707BC;
extern u16 D_800707BE;
extern u8 D_800708D4[];
extern u8 D_800716D0;
extern s32 D_80071744; // LBA loc for func_80014540
extern s16 D_80071A5C;
extern s32 D_80071C24[]; // accessory data?
extern s32 D_80071E44[]; // armor data?
extern s32 D_800722C8;   // LBA dst for func_80014540
extern u8 D_800722DC[];
extern s16 D_8008337E;
extern s16 D_800833DE;
extern s16 D_80095DD4;
extern s32 D_80095DD8; // LBA len for func_80014540
extern s16 D_800965E8;
extern s32 D_80099788;
extern s32 D_80099998;
extern u8 D_80099BA8[];
extern s32 D_80099DB8;
extern u16 D_8009C560;
extern u8 D_8009C738[];
extern s16 D_8009A000;
extern u16 D_8009ABF6;
extern u16 D_8009AC32;
extern u8 D_8009D5E9;
extern void (*D_800A00CC)(void); // battle/brom entrypoint
extern void (*D_800A1158)(void); // battle/battle entrypoint

s32 D_80062D4C = 0x00000000;
s32 D_80062D50 = 0x000000FF;
s32 D_80062D54 = 0x00000000;
s32 D_80062D58 = 0x00000009;
s32 D_80062D5C = 0x00000006;
s16 D_80062D60 = 0x0000;
s16 D_80062D62 = 0x0000;
s16 D_80062D64 = 0x0000;
s16 D_80062D66 = 0x0000;
s16 D_80062D68 = 0x0000;
s16 D_80062D6A = 0x0000;
s16 D_80062D6C = 0x0000;
s16 D_80062D6E = 0x0000;
s8 D_80062D70 = 0x00;
s8 D_80062D71 = 0x00;
s16 D_80062D72 = 0x0000;
s16 D_80062D74 = 0x0000;
s16 D_80062D76 = 0x0000;
s16 D_80062D78 = 0x0000;
s16 D_80062D7A = 0x0000;
s16 D_80062D7C = 0x0000;
u16 D_80062D7E = 0x0000;
s16 D_80062D80 = 0x0000;
s16 D_80062D82 = 0x0000;
s32 D_80062D84 = 0x00000000;
s16 D_80062D88 = 0x0000;
s16 D_80062D8A = 0x0000;
s32 D_80062D8C = 0x00000000;
s32 D_80062D90 = 0x00000000;
s32 D_80062D94 = 0x00000000;
s32 D_80062D98 = 0x00000000;
s32 D_80062D9C = 0x00000000;
s32 D_80062DA0 = 0x00140000;
s32 D_80062DA4 = 0x007800A0;
s32 D_80062DA8 = 0x00010002;
s32 D_80062DAC = 0x00060006;
s32 D_80062DB0 = 0x00010001;
s16 D_80062DB4 = 0x0007;
s16 D_80062DB6 = 0x0000;
s16 D_80062DB8 = 0x0000;
s16 D_80062DBA = 0x0000;
s16 D_80062DBC = 0x0000;
s16 D_80062DBE = 0x0000;
s32 D_80062DC0 = 0x00000000;
s32 D_80062DC4 = 0x00000000;
s32 D_80062DC8 = 0x00000000;
s32 D_80062DCC = 0x00000000;
s32 D_80062DD0 = 0x00000000;
s32 D_80062DD4 = 0x00000000;
s16 D_80062DD8 = 0x0000;
s8 D_80062DDA = 0x00;
s8 D_80062DDB = 0x00;
s8 D_80062DDC = 0x02;
s8 D_80062DDD = 0x00;
s8 D_80062DDE = 0x00;
s8 D_80062DDF = 0x00;
s32 D_80062DE0 = 0x00000000;
s8 D_80062DE4 = 0x00;
s8 D_80062DE5 = 0x00;
s16 D_80062DE6 = 0x00B4;
s16 D_80062DE8 = 0x0068;
s16 D_80062DEA = 0x0000;
s32 D_80062DEC = 0x801D0000;
s32 D_80062DF0 = 0x00000084;
s32 D_80062DF4 = 0xFFFFFFFF;
s32 D_80062DF8 = 0x00000001;
s8 D_80062DFC = 0x40;
s8 D_80062DFD = 0x00;
s8 D_80062DFE = 0x00;
s8 D_80062DFF = 0x00;
s32 D_80062E00 = 0x00000000;
s32 D_80062E04 = 0x00000000;
s16 D_80062E08 = 0x0000;
s16 D_80062E0A = 0x0000;

void func_8001155C(void);
void func_80014A00(s32* dst, s32* src, s32 len);
u16* func_80014D9C(s32, s32, s32);
void func_800150E4(u16*, u16*);
u16* func_800151F4(s32);
void func_80015CA0(GzHeader* src, s32* dst);
s32 func_80034B44();

void func_800110B8(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800110C0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001117C);

void func_800111E4(void) {
    D_8009A000 = 0xF4;
    func_8002DA7C();
    if (!(D_8009D5E9 & 0x30)) {
        func_8001117C(0x2B);
    }
    D_800707BC = D_8009ABF6;
    D_800707BE = D_8009AC32;
    D_800707BE = D_800716D0 | D_800707BE;
    func_800146A4();
    D_800716D0 = 0;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80011274);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800112E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001146C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001155C);

void func_8001171C(void) {
    StopCallback();
    ResetCallback();
    func_80043938(0);
    func_80036298();
    D_80095DD4 = 0;
    VSyncCallback(&func_8001155C);
    func_80043BA8(0);
    func_80043D3C(0);
    func_80039EDC();
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80011784);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80011860);

void func_80011920(void) {
    D_800965E8 = 0;
    D_80071A5C = 0;
}

void func_80011938(void) {
    func_80033E34(D_80048CFC, D_80048D00, 0x800F0000, 0);
    do {
    } while (func_80034B44());
    func_80033E34(D_80048D04, D_80048D08, 0x801B0000, 0);
    do {
    } while (func_80034B44());
    func_80033E34(D_80048D0C, D_80048D10, 0x801BC800, 0);
    do {
    } while (func_80034B44());
    func_8002988C(0x800F0000, 0x801BC800);
    func_80029998(0x801B0000);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800119E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80011AEC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80011BB4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", main);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80012840);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800128B8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800129D0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80012A8C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80012DB0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800131B8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800134F4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80013564);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800135C0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80013624);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80013800);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800138EC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80013C9C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800140A4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800140F4);

// obtain file sector from a YamadaFile
s32 func_800144D8(s32 file_no) { return D_80048D84[file_no].loc; }

void func_800144F0(s32 file_no) { func_80033DAC(file_no, 0); }

void func_80014510(s32 file_no) { func_800144F0(D_80048D84[file_no].loc); }

// used to load WORLD/WORLD.BIN or FIELD/FIELD.BIN
void func_80014540(void) {
    func_80033E34(D_80071744, D_80095DD8, D_800722C8, 0);
}

void func_80014578(s32 file_no, void* dst, s32 mode) {
    func_80033E34(D_80048D84[file_no].loc, D_80048D84[file_no].len, dst, mode);
}

void func_800145BC(void (*cb)(void)) {
    while (func_80034B44()) {
        if (cb) {
            cb();
        }
    }
}

void func_80014608(void) {}

// initialize LBA system
void func_80014610(void) {
    u8 buf[2048];
    func_80033E34(LBA_INIT_YAMADA, sizeof(buf), &buf, 0);
    func_800145BC(0);
    func_80014A00(
        (s32*)D_80048D84, (s32*)&buf, sizeof(Yamada) * YAMADA_FILE_NUM);
}

void func_80014658(s32 file_no, void (*cb)(void)) {
    func_80014578(file_no, (void*)0x801B0000, 0);
    func_800145BC(0);
    func_80015CA0((GzHeader*)0x801B0000, (s32*)0x800A0000);
    cb();
}

#ifndef NON_MATCHINGS
INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800146A4);
#else
void func_800146A4(void) {
    s32 var_s0 = -1;
    while (var_s0) {
        switch (D_8009C560) {
        case 4:
            func_800145BC(0);
            func_80014658(BATTLE_BROM, D_800A00CC);
            break;
        case 2:
            func_800140F4();
            func_80014658(BATTLE_BATTLE, D_800A1158);
            break;
        default:
            var_s0 = 0;
            break;
        }
    }
}
#endif

void func_80014750(void) {
    s32 temp_a0;
    s32 temp_s0;

    func_80015B44(0x801B0000);
    while (1) {
        temp_s0 = func_80015B50() & 0xFFFF;
        if (temp_s0 == 0xFFFF) {
            break;
        }
        temp_a0 = func_80015B88() & 0xFFFF;
        if (temp_s0 == 9) {
            func_80015BC0(func_80014C80(temp_a0));
        } else if (D_80048DD4[temp_s0]) {
            func_80015BC0(D_80048DD4[temp_s0]);
        }
    }
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014804);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800148A0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800148B4);

void func_80014934(void) {
    func_800148A0();
    func_80014578(INIT_KERNEL, (void*)0x801B0000, 0);
    func_800145BC(0);
    func_80015C3C(0x801B0000, &D_8009C738, KERNEL_INIT);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014980);

void func_800149E0(void) { func_80043DD8(0); }

void func_80014A00(s32* dst, s32* src, s32 len) {
    int i;
    for (i = 0; i < len >> 2; i++) {
        *dst++ = *src++;
    }
}

s32 func_80014A38(u32 arg0) {
    s32 i;
    for (i = 0;; i++) {
        arg0 >>= 1;
        if (!arg0) {
            return i;
        }
    }
}

s32 func_80014A58(u32 arg0) {
    s32 i;
    i = 0;
    while (arg0) {
        if (arg0 & 1) {
            i++;
        }
        arg0 >>= 1;
    }
    return i;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014A84);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014B08);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014B54);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014B70);

s32 func_80014BA8(s32 arg0) {
    return (u8)(((func_80014B70() & 0xFF) * arg0) >> 8);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014BE4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014C44);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014C70);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014C80);

s32 func_80014CBC(s32 arg0, s32 arg1) {
    s32 var_a2;
    u8 var_v1;

    var_v1 = 0xFF;
    var_a2 = -1;
    switch (arg0) {
    case 0:
    case 1:
    case 2:
        var_v1 = D_800708D4[(D_80010100[arg0] + arg1) * 0x1C];
        break;
    case 4:
        if (arg1 < 0x80) {
            var_v1 = D_800722DC[arg1 * 0x1C];
        }
    }
    if (var_v1 != 0xFF) {
        var_a2 = var_v1;
    }
    return var_a2;
}

u8* func_80014D58(u8* arg0, u8* arg1, s32 arg2) {
    u8 var_a3 = *arg1;
    while (var_a3 != 0xFF) {
        *arg0 = var_a3;
        arg1++;
        arg2--;
        arg0++;
        if (arg2 == -1) {
            break;
        }
        var_a3 = *arg1;
    }
    return arg0;
}

u16* func_80014D9C(s32 arg0, s32 arg1, s32 arg2) {
    u8* temp_v1 = D_80063690 + D_80069490[arg0 + arg2];
    return (u16*)&temp_v1[*(u16*)&temp_v1[arg1 * 2]];
}

void func_80014DD0(s32 arg0, s32 arg1, u8* arg2) {
    func_80014D58(arg2, (u8*)func_80014D9C(arg0, arg1, 0), -1);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014E0C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80014E74);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800150E4);

u16* func_800151F4(s32 arg0) { return func_80014D9C(0x10, arg0, 0); }

void func_8001521C(s32 arg0) {
    u16* temp_v0 = func_800151F4(arg0);
    func_800150E4(temp_v0, temp_v0);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015248);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800155A4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800155B0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015654);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015668);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800159B0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015AFC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015B44);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015B50);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015B88);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015BC0);

#ifndef NON_MATCHINGS
INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015C3C);
#else
// load kernel module by its ID
// https://wiki.ffrtt.ru/index.php/FF7/Kernel/Low_level_libraries#BIN-GZIP_Type_Archives
s32 func_80015C3C(u8* src, void* dst, s32 id) {
    s32 len;
    s32 cur_id;
    s32 ret;

    ret = -1;
    while (len = (src[0] | (src[1] << 8))) {
        cur_id = src[4] | (src[5] << 8);
        if (cur_id == id) {
            ret = func_80017108(src + 6, dst);
            break;
        }
        src += len + 6;
    }
    return ret;
}
#endif

void func_80015CA0(GzHeader* src, s32* dst) {
    s32 i;
    s32* var_s1;
    u32 len;
    s32 unk4;

    unk4 = src->unk4;
    len = src->len;
    func_80017108(src + 1, dst);
    var_s1 = &dst[len >> 2];
    unk4 = (u32)unk4 >> 2;
    for (i = 0; i < unk4; i++) {
        var_s1[i] = 0;
    }
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015D14);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80015D64);

s32 func_80016320(s32* arg0) {
    while (arg0) {
        arg0 = (s32*)arg0[-1];
    }
    return 0;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80016340);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800166C0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80016808);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800169B8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80016F90);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001708C);

// gzip inflate
INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80017108);

void func_80017238(u32 arg0, u32* arg1, u8* arg2) {
    *arg2 = arg0;
    *arg1 = arg0 >> 8;
    func_8001AC9C(*arg2, *arg1);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001726C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80017678);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001786C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80017E68);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80017F38);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018028);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018220);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800182FC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018390);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001840C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800184C0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800185A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018630);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018834);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018934);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018A04);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018AB0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018B14);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018BB8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018C94);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018D4C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018E18);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018E90);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018ECC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80018FC0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019064);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800190E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800191A0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019254);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019338);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001937C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800193F4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019440);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800194BC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019544);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019608);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001964C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019690);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800197B8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019978);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019D1C);

void func_80019D74(u8 arg0, u8 arg1) {
    if (arg1 == 0xB) {
        func_80019E4C(arg0);
    }
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019DA0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019E4C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019E84);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80019F90);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A174);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A1C8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A280);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A384);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A3B8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A440);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A4A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A518);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A5B4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A684);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A780);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A874);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A980);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001A9CC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001AB1C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001AC9C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001AE08);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001AEE4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B4A0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B570);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B5E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B704);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B834);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B8A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001B944);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001BA54);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001BB30);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001BC18);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001BCE8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001BD50);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001BDB0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C0EC);

void func_8001C3C4(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C3CC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C434);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C484);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C498);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C4E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C58C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C5BC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C788);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C808);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C8D4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001C980);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001CB48);

void func_8001CDA4(void) {
    SetPolyFT4(D_80062F24.ft4);
    SetShadeTex(D_80062F24.ft4, 1);
    D_80062F24.ft4->x0 = 0;
    D_80062F24.ft4->y0 = 5;
    D_80062F24.ft4->x1 = 0x40;
    D_80062F24.ft4->y1 = 5;
    D_80062F24.ft4->x2 = 0;
    D_80062F24.ft4->y2 = 0x45;
    D_80062F24.ft4->x3 = 0x40;
    D_80062F24.ft4->y3 = 0x45;
    D_80062F24.ft4->u0 = 0;
    D_80062F24.ft4->v0 = 0;
    D_80062F24.ft4->u1 = 128;
    D_80062F24.ft4->v1 = 0;
    D_80062F24.ft4->u2 = 0;
    D_80062F24.ft4->v2 = 128;
    D_80062F24.ft4->u3 = 128;
    D_80062F24.ft4->v3 = 128;
    D_80062F24.ft4->clut = GetClut(0, 0x1FE);
    D_80062F24.ft4->tpage = GetTPage(1, 0, 0x340, 0);
    AddPrim(D_80062FC4, D_80062F24.ft4);
    D_80062F24.ft4++;
}

void func_8001CF3C(s16 x, s16 y, s16 w, s16 h, u16 tx, u16 ty, u16 tw, u16 th,
                   s16 clut, s32 tex) {
    SetPolyFT4(D_80062F24.ft4);
    SetShadeTex(D_80062F24.ft4, 1);
    if (tex << 0x10) {
        SetSemiTrans(D_80062F24.ft4, 1);
    }
    D_80062F24.ft4->x0 = x;
    D_80062F24.ft4->y0 = y;
    D_80062F24.ft4->x1 = x + w;
    D_80062F24.ft4->y1 = y;
    D_80062F24.ft4->x2 = x;
    D_80062F24.ft4->y2 = y + h;
    D_80062F24.ft4->x3 = x + w;
    D_80062F24.ft4->y3 = y + h;
    D_80062F24.ft4->u0 = tx;
    D_80062F24.ft4->v0 = ty;
    D_80062F24.ft4->u1 = tx + tw;
    D_80062F24.ft4->v1 = ty;
    D_80062F24.ft4->u2 = tx;
    D_80062F24.ft4->v2 = ty + th;
    D_80062F24.ft4->u3 = tx + tw;
    D_80062F24.ft4->v3 = ty + th;
    D_80062F24.ft4->clut = GetClut(0x100, (s16)clut + 0x1E0);
    D_80062F24.ft4->tpage = GetTPage(1, 0, 0x3C0, 0x100);
    AddPrim(D_80062FC4, D_80062F24.ft4);
    D_80062F24.ft4++;
}

void func_8001D180(s16 x, s16 y, s16 w, s16 h, u16 tx, u16 ty, u16 tw, u16 th,
                   s16 clut, s32 tex) {
    SetPolyFT4(D_80062F24.ft4);
    SetShadeTex(D_80062F24.ft4, 1);
    if (tex << 0x10) {
        SetSemiTrans(D_80062F24.ft4, 1);
    }
    D_80062F24.ft4->x0 = x;
    D_80062F24.ft4->y0 = y;
    D_80062F24.ft4->x1 = x + w;
    D_80062F24.ft4->y1 = y;
    D_80062F24.ft4->x2 = x;
    D_80062F24.ft4->y2 = y + h;
    D_80062F24.ft4->x3 = x + w;
    D_80062F24.ft4->y3 = y + h;
    D_80062F24.ft4->u0 = tx;
    D_80062F24.ft4->v0 = ty;
    D_80062F24.ft4->u1 = tx + tw;
    D_80062F24.ft4->v1 = ty;
    D_80062F24.ft4->u2 = tx;
    D_80062F24.ft4->v2 = ty + th;
    D_80062F24.ft4->u3 = tx + tw;
    D_80062F24.ft4->v3 = ty + th;
    D_80062F24.ft4->clut = GetClut(0x180, (s16)clut);
    D_80062F24.ft4->tpage = GetTPage(1, 0, 0x340, 0x100);
    AddPrim(D_80062FC4, D_80062F24.ft4);
    D_80062F24.ft4++;
}

void func_8001D3C0(s16 x, s16 y) {
    SetTile1(D_80062F24.tile1);
    D_80062F24.tile1->x0 = x;
    D_80062F24.tile1->y0 = y;
    D_80062F24.tile1->r0 = 0xFF;
    D_80062F24.tile1->g0 = 0xFF;
    D_80062F24.tile1->b0 = 0;
    AddPrim(D_80062FC4, D_80062F24.tile1);
    D_80062F24.tile1++;
}

void func_8001D47C(s16 x, s16 w, s16 y, s32 color) {
    SetBlockFill(D_80062F24.blk_fill);
    D_80062F24.blk_fill->r0 = color >> 16;
    D_80062F24.blk_fill->g0 = color >> 8;
    D_80062F24.blk_fill->b0 = color;
    D_80062F24.blk_fill->x0 = x;
    D_80062F24.blk_fill->y0 = y;
    D_80062F24.blk_fill->w = w;
    D_80062F24.blk_fill->h = y;
    AddPrim(D_80062FC4, D_80062F24.blk_fill);
    D_80062F24.blk_fill++;
}

void func_8001D56C(s16 x, s16 y, s16 w, s16 h, s16 is_yellow) {
    if (is_yellow) {
        SetBlockFill(D_80062F24.blk_fill);
        D_80062F24.blk_fill->r0 = 0xFF;
        D_80062F24.blk_fill->g0 = 0xFF;
        D_80062F24.blk_fill->b0 = 0;
    } else {
        SetBlockFill(D_80062F24.blk_fill);
        D_80062F24.blk_fill->r0 = 0x80;
        D_80062F24.blk_fill->g0 = 0x80;
        D_80062F24.blk_fill->b0 = 0x80;
    }
    D_80062F24.blk_fill->x0 = x;
    D_80062F24.blk_fill->y0 = y;
    D_80062F24.blk_fill->w = w;
    D_80062F24.blk_fill->h = h;
    AddPrim(D_80062FC4, D_80062F24.blk_fill);
    D_80062F24.blk_fill++;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001D6A8);

void func_8001DE0C(Unk8001DE0C* arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    arg0->unk0 = arg1;
    arg0->unk2 = arg2;
    arg0->unk4 = arg3;
    arg0->unk6 = arg4;
}

void func_8001DE24(Unk8001DE0C* arg0, s32 arg1, s32 arg2) {
    arg0->unk0 = arg0->unk0 + arg1;
    arg0->unk2 = arg0->unk2 + arg2;
}

void func_8001DE40(Unk8001DE0C* arg0, Unk8001DE0C* arg1) {
    arg0->unk0 = arg1->unk0;
    arg0->unk2 = arg1->unk2;
    arg0->unk4 = arg1->unk4;
    arg0->unk6 = arg1->unk6;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001DE70);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001DEB0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001DEF0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001DF24);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001E040);

void func_8001EB2C(s16 x, s16 y) {
    RECT rect;

    setSprt(D_80062F24.sprt);
    SetSemiTrans(D_80062F24.sprt, 1);
    SetShadeTex(D_80062F24.sprt, 1);
    D_80062F24.sprt->x0 = x;
    D_80062F24.sprt->y0 = y;
    D_80062F24.sprt->u0 = 224;
    D_80062F24.sprt->v0 = 8;
    D_80062F24.sprt->w = 24;
    D_80062F24.sprt->h = 16;
    D_80062F24.sprt->clut = GetClut(0x100, 0x1E1);
    AddPrim(D_80062FC4, D_80062F24.sprt++);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0xFF;
    rect.h = 0xFF;
    func_80026A34(0, 1, (u16)GetTPage(0, 2, 0x3C0, 0x100), &rect);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001EC70);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001EF84);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001F1BC);

void func_8001F6AC(void) {}

u8 func_8001F6B4(void) { return D_80062DDB; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001F6C0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001F6E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001F710);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FA28);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FA68);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FAAC);

void func_8001FAF0(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FAF8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FBAC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FCDC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FE6C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FF50);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FF8C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8001FFD4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002001C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80020058);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800206E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80020B68);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80021044);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800211B8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800211C4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002120C);

void func_80021258(s32 arg0) { func_80015248(13, arg0, 8); }

void func_80021280(s32 arg0) { func_80015248(4, arg0, 8); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800212A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80021BAC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80021C4C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80021D5C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80021E70);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80021F58);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80022B5C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80022DE4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80022FE0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80023050);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002305C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800230C4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002368C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80023788);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002382C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80023940);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80023AC4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80023AD4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80024A04);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80024A3C);

void func_80024D88(s32 arg0) {
    func_800211C4(0xD);
    do {
    } while (func_80034B44());
    VSync(30);
    func_801D131C(arg0);
}

void func_80024DD4(s32 arg0) {
    func_800211C4(0xE);
    do {
    } while (func_80034B44());
    func_801D1A6C(arg0);
}

void func_80024E18(s32 arg0) {
    func_800211C4(0xF);
    do {
    } while (func_80034B44());
    func_801D4118(arg0);
}

void func_80024E5C(void) {
    func_800211C4(0x10);
    do {
    } while (func_80034B44());
    func_801D4CC0();
}

void func_80024E94(void) {
    func_800211C4(0xA);
    do {
    } while (func_80034B44());
    func_801D1774();
}

void func_80024ECC(void) {
    func_800211C4(1);
    do {
    } while (func_80034B44());
    func_801D2D74();
}

void func_80024F04(void) {
    func_800211C4(1);
    do {
    } while (func_80034B44());
    func_801D2E84();
}

void func_80024F3C(s32 arg0) {
    func_800211C4(1);
    do {
    } while (func_80034B44());
    func_801D2F00(arg0);
}

void func_80024F80(s32 arg0) {
    func_800211C4(1);
    do {
    } while (func_80034B44());
    func_801D3138(arg0);
}

void func_80024FC4(s32 arg0) {
    func_800211C4(1);
    do {
    } while (func_80034B44());
    func_801D3018(arg0);
}

void func_80025008(void) {
    func_800211C4(1);
    do {
    } while (func_80034B44());
    func_801D3228();
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025040);

void func_800250B4(void) {
    func_800211C4(0xC);
    do {
    } while (func_80034B44());
    func_801D027C();
}

void func_800250EC(s32 arg0) {
    func_800211C4(0xC);
    do {
    } while (func_80034B44());
    func_801D05C4(arg0);
}

void func_80025130(s32 arg0) {
    func_800211C4(0xC);
    do {
    } while (func_80034B44());
    func_801D0704(arg0);
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025174);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025288);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025310);

void func_80025360() { func_8001FA28(0x19F); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025380);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002542C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800254D8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800254E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025514);

void func_80025648(void) {}

void func_80025650(void) {}

s32 func_80025658() { return D_8009C738[1]; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025668);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800256DC);

s32* func_80025758(s32 arg0) { return &D_80071E44[arg0 * 9]; }

s32* func_80025774(s32 arg0) { return &D_80071C24[arg0 * 4]; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025788);

void func_800257C4(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800257CC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025800);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800258BC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025988);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025A44);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025B10);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025B48);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", GsGetWorkBase);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025B8C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025BD0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025C14);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025C54);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025C94);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025CD4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025D14);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025DF8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80025ED4);

void func_80026034(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002603C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026090);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800260DC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026258);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800262D8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026408);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026448);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800264A8);

void func_800269C0(void* arg0) { D_80062F24.poly = arg0; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800269D0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800269E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026A00);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026A0C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026A20);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026A34);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026A94);

void func_80026B5C(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026B64);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026B70);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026C5C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80026F44);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002708C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80027354);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80027408);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80027990);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80027B84);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80028030);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80028484);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800285AC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80028930);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80028CA0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80028E00);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029114);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800293D0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800293F4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029424);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029464);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800294A4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800294BC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800297A4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029818);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002988C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029998);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800299C8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029A50);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029AF0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029B78);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029BAC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029C48);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029E98);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80029F44);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A094);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A28C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A43C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A510);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A6C4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A748);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A798);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A7E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002A958);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002AABC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002AFB8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B1A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B1F8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B2F8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B3B4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B5A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B608);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B668);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B6AC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B730);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B7E0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B8B4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B904);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B958);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002B9AC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BA08);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BA5C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BA98);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BB20);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BBB4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BBEC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BC58);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BCCC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BD04);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BDCC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BE2C);

void func_8002BE8C(s32 arg0) { func_8002BCCC(arg0, D_80099BA8); }

void func_8002BEB4(s32 arg0) { func_8002BD04(arg0, D_80099BA8); }

void func_8002BEDC(s32 arg0) { func_8002BCCC(arg0, &D_80099998); }

void func_8002BF04(s32 arg0) { func_8002BD04(arg0, &D_80099998); }

void func_8002BF2C(s32 arg0) { func_8002BCCC(arg0, &D_80099788); }

void func_8002BF54(s32 arg0) { func_8002BD04(arg0, &D_80099788); }

void func_8002BF7C(s32 arg0) { func_8002BCCC(arg0, &D_80099DB8); }

void func_8002BFA4(s32 arg0) { func_8002BD04(arg0, &D_80099DB8); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002BFCC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C004);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C0CC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C12C);

void func_8002C18C(s32 arg0) { func_8002BFCC(arg0, D_80099BA8); }

void func_8002C1B4(s32 arg0) { func_8002C004(arg0, D_80099BA8); }

void func_8002C1DC(s32 arg0) { func_8002BFCC(arg0, &D_80099998); }

void func_8002C204(s32 arg0) { func_8002C004(arg0, &D_80099998); }

void func_8002C22C(s32 arg0) { func_8002BFCC(arg0, &D_80099788); }

void func_8002C254(s32 arg0) { func_8002C004(arg0, &D_80099788); }

void func_8002C27C(s32 arg0) { func_8002BFCC(arg0, &D_80099DB8); }

void func_8002C2A4(s32 arg0) { func_8002C004(arg0, &D_80099DB8); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C2CC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C300);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C3A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C408);

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

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C5C8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C634);

void func_8002C6A8(Unk8002C5A8* arg0) {
    s32 n = arg0->unk4;
    D_80062F40 = 0;
    D_80062FE4 = n << 0x10;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C6C8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C734);

void func_8002C7A8(void) { func_80029F44(); }

void func_8002C7C8(void) { func_8002A43C(); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C7E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C81C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C850);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C884);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C8C4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C8DC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002C9E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CA84);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CB78);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CC18);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CC44);

void func_8002CCBC(void) { D_8008337E = 0; }

void func_8002CCCC(void) { D_800833DE = 0; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CCDC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CDD0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CEC0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CF1C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CF78);

void func_8002CF98(void) {}

void func_8002CFA0() { func_80038FEC(0); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002CFC0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D1E4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D2D4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D410);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D4A0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D530);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D668);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D7A0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002D8E8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002DA30);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002DA7C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002DF88);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002E1A8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002E23C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002E428);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002E478);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002E954);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002ED34);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002F24C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002F738);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002F848);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002FDA0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002FE48);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8002FF4C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80030038);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80030148);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80030234);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80030380);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800308D4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80030E7C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031820);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800318BC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031A70);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031AB0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031AFC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031BA0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031BE4);

void func_80031C88(Unk80031FC0* arg0) {
    arg0->unk2C = *arg0->unk0++;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031CB0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031CE0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031D6C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031E98);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031EEC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031F30);

void func_80031FC0(Unk80031FC0* arg0) {
    arg0->unk60 = *arg0->unk0++ << 8;
    arg0->unk62 = 0;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80031FF0);

void func_80032078(Unk80031FC0* arg0) { arg0->unk66 = *arg0->unk0++; }

void func_80032094(Unk80031FC0* arg0) { arg0->unk66 = (arg0->unk66 + 1) & 0xF; }

void func_800320AC(Unk80031FC0* arg0) {
    arg0->unk66 = (arg0->unk66 + 0xFFFF) & 0xF;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800320C4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032274);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800323CC);

void func_800324D8(Unk80031FC0* arg0) { arg0->unkCC = (s8)*arg0->unk0++; }

void func_80032500(Unk80031FC0* arg0) {
    arg0->unkCC = (s8)*arg0->unk0++ + arg0->unkCC;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8003252C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8003257C);

void func_800325B8(Unk800325B8* arg0) { arg0->unk6C = 0; }

void func_800325C0(Unk80031FC0* arg0) { arg0->unkCE = (s8)*arg0->unk0++; }

void func_800325E8(Unk80031FC0* arg0) {
    arg0->unkCE = (s8)*arg0->unk0++ + arg0->unkCE;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032614);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032718);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032770);

void func_800327E0(Unk80031FC0* arg0) {
    arg0->unkD6 = 0;
    arg0->unk38 &= ~1;
    arg0->unkE0 |= 0x10;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032804);

void func_800328D4(Unk80031FC0* arg0) { arg0->unk90 = *arg0->unk0++ << 8; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800328F8);

void func_80032968(Unk80031FC0* arg0) {
    arg0->unkD8 = 0;
    arg0->unk38 &= ~2;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8003298C);

void func_80032A04(Unk80031FC0* arg0) { arg0->unk9E = *arg0->unk0++ << 7; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032A28);

void func_80032A98(Unk80031FC0* arg0) {
    arg0->unkDA = 0;
    arg0->unk38 &= ~4;
    arg0->unkE0 |= 3;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032ABC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032B30);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032BB4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032C20);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032C8C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032CE8);

void func_80032D44(Unk80032D44* arg0) { arg0->unk6E = 1; }

void func_80032D50(void) {}

void func_80032D58(Unk80032D44* arg0) { arg0->unk6E = 4; }

void func_80032D64(void) {}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032D6C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032E08);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032E6C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032ED0);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032F34);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032F98);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80032FFC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033060);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800330C4);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033128);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800331CC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033224);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033264);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800332EC);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8003337C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033420);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_8003345C);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033488);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800334EC);

void func_80033534(Unk80033788* arg0) { arg0->unk38 &= ~8; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033548);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033588);

void func_800335CC(void* arg0, Unk800335CC* arg1) { arg1->unk54 = 1; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800335D8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033628);

void func_8003366C(Unk80031FC0* arg0) {
    s16 var_v0 = *arg0->unk0++;
    if (var_v0 == 0) {
        var_v0 = 0x101;
    } else {
        var_v0++;
    }
    arg0->unkA4 = var_v0;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033698);

void func_800336DC(Unk80031FC0* arg0) {
    s16 var_v0 = *arg0->unk0++;
    if (var_v0 == 0) {
        var_v0 = 0x101;
    } else {
        var_v0++;
    }
    arg0->unkA6 = var_v0;
}

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033708);

void func_80033788(Unk80033788* arg0) { arg0->unk38 |= 0x10; }

void func_8003379C(Unk80033788* arg0) { arg0->unk38 &= ~0x10; }

void func_800337B0(Unk80033788* arg0) { arg0->unk38 |= 0x20; }

void func_800337C4(Unk80033788* arg0) { arg0->unk38 &= ~0x20; }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_800337D8);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033818);

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033894);

void func_80033A70() { func_80033894(); }

INCLUDE_ASM("asm/us/main/nonmatchings/18B8", func_80033A90);
