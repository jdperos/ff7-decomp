import ninja_syntax
import os
import yaml

CPP_FLAGS = "-Iinclude -Iinclude/psxsdk -DUSE_INCLUDE_ASM"
CC_FLAGS = "-O2 -G8"
LD_FLAGS = ""

nw: ninja_syntax.Writer = None
objs: list[str] = []


def basename(cfg):
    return cfg["options"]["basename"]


def asm_path(cfg):
    return cfg["options"]["asm_path"]


def build_path(cfg):
    return cfg["options"]["build_path"]


def ld_path(cfg):
    return cfg["options"]["ld_script_path"]


def src_path(cfg):
    return cfg["options"]["src_path"]


def asset_path(cfg):
    return cfg["options"]["asset_path"]


def platform(cfg):
    return cfg["options"]["platform"]


def add_s(cfg: any, file_name: str):
    in_path = f"{asm_path(cfg)}/{file_name}.s"
    out_path = f"{build_path(cfg)}/{in_path}.o"
    if out_path in objs:
        return
    objs.append(out_path)
    nw.build(
        rule=f"{platform(cfg)}-as",
        outputs=[out_path],
        inputs=[in_path],
    )
    nw.build(
        rule="phony",
        outputs=[in_path],
        implicit=[ld_path(cfg)],
    )


def add_c(cfg: any, file_name: str):
    in_path = f"{src_path(cfg)}/{file_name}.c"
    out_path = f"{build_path(cfg)}/{in_path}.o"
    if out_path in objs:
        return
    objs.append(out_path)
    nw.build(
        rule=f"{platform(cfg)}-cc",
        outputs=[out_path],
        inputs=[in_path],
        implicit=["include/common.h", "include/game.h"],
    )
    nw.build(
        rule="phony",
        outputs=[in_path],
        implicit=[ld_path(cfg)],
    )


def add_copy(cfg: any, file_name: str):
    in_path = f"{asset_path(cfg)}/{file_name}"
    out_path = f"{build_path(cfg)}/{in_path}.o"
    if out_path in objs:
        return
    objs.append(out_path)
    nw.build(
        rule=f"copy",
        outputs=[out_path],
        inputs=[in_path],
    )
    nw.build(
        rule="phony",
        outputs=[in_path],
        implicit=[ld_path(cfg)],
    )


def add_splat_config(file_name: str):
    with open(file_name) as f:
        cfg = yaml.load(f, Loader=yaml.SafeLoader)
    nw.build(
        rule="splat",
        outputs=[ld_path(cfg)],
        inputs=file_name,
        implicit=cfg["options"]["symbol_addrs_path"],
    )
    objs.clear()
    if platform(cfg) == "psx" and basename(cfg) == "main":
        add_s(cfg, "header")
    for segment in cfg["segments"]:
        if not "type" in segment:
            continue
        if segment["type"] != "code":
            continue
        for sub in segment["subsegments"]:
            offset = int(sub[0])
            if len(sub) < 2:
                kind = "data"
                name = segment["name"]
            else:
                kind = str(sub[1])
                if len(sub) > 2:
                    name = str(sub[2])
                else:
                    name = str.format("{0:X}", offset)
            if kind == "data":
                add_s(cfg, f"data/{name}.data")
            elif kind == "rodata":
                add_s(cfg, f"data/{name}.rodata")
            elif kind == "bss":
                add_s(cfg, f"data/{name}.bss")
            elif kind == "asm":
                add_s(cfg, name)
            elif kind == "c":
                add_c(cfg, name)
    nw.build(
        rule="psx-ld",
        outputs=[f"{build_path(cfg)}/{basename(cfg)}.elf"],
        inputs=[ld_path(cfg)],
        implicit=objs,
        variables={
            "map_path": f"{build_path(cfg)}/{basename(cfg)}.map",
            "obj_paths": objs,
            "symbol_path": str.join(
                " ",
                [
                    f"-T {cfg["options"]["undefined_syms_auto_path"]}",
                    f"-T config/sym_extern.us.txt",
                ],
            ),
        },
    )
    nw.build(
        rule="psx-exe",
        outputs=[f"{build_path(cfg)}/{basename(cfg)}.exe"],
        inputs=[f"{build_path(cfg)}/{basename(cfg)}.elf"],
    )


with open("build.ninja", "w") as f:
    nw = ninja_syntax.Writer(f)
    nw.rule(
        "splat",
        command=".venv/bin/splat split $in > /dev/null && touch $out",
        description="splat $in",
    )
    nw.rule(
        "psx-as",
        command="mipsel-linux-gnu-as -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -o $out $in",
        description="psx as $in",
    )
    nw.rule(
        "psx-cc",
        command=(
            f"mipsel-linux-gnu-cpp {CPP_FLAGS} -lang-c -Iinclude -Iinclude/psxsdk -undef -Wall -fno-builtin $in"
            f" | bin/cc1-psx-272 -quiet -mcpu=3000 -g -mgas -gcoff {CC_FLAGS}"
            " | python3 tools/maspsx/maspsx.py  --expand-div --aspsx-version=2.34"
            " | mipsel-linux-gnu-as -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -o $out"
        ),
        description="psx cc $in",
    )
    nw.rule(
        "copy",
        command="mipsel-linux-gnu-ld -r -b binary -o $out $in",
        description="copy $in",
    )
    nw.rule(
        "psx-ld",
        command=f"mipsel-linux-gnu-ld -nostdlib --no-check-sections {LD_FLAGS} -Map $map_path -T $in $symbol_path -o $out $obj_paths",
        description="psx ld $in",
    )
    nw.rule(
        "psx-exe",
        command=f"mipsel-linux-gnu-objcopy -O binary $in $out",
        description="psx exe $in",
    )
    nw.rule(
        "check",
        command="sha1sum -c config/check.sha1",
        description="check",
    )
    nw.build(
        rule="check",
        outputs=["build/check.dummy"],
        inputs=[
            "build/us/main.exe",
        ],
    )
    add_splat_config("config/main.us.yaml")
