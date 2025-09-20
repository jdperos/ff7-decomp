OVL_US += BATTLE/BATINI.X
OVL_US += BATTLE/BATRES.X
OVL_US += BATTLE/BATTLE.X
OVL_US += BATTLE/BROM.X
OVL_US += FIELD/FIELD.BIN
OVL_US += MINI/CHOCOBO.BIN
OVL_US += WORLD/WORLD.BIN

.PHONY: all
all: disks
	python3 tools/ninja/gen.py && ninja

.PHONY: disks
disks: disks/us disks/betaus

disks/%.iso:
	bchunk "disks/$*.bin" "disks/$*.cue" "$@"
	mv "disks/$*.iso01.iso" "$@"
disks/us: disks/Final\ Fantasy\ VII\ (USA)\ (Disc\ 1).iso
	7z x "$<" -o$@
	@for f in $(OVL_US); do \
		tail --bytes=+9 "$@/$$f" | gzip -cd > "$@/$$f.dec"; \
	done
disks/betaus: disks/Final\ Fantasy\ VII\ (USA)\ (Interactive\ Sampler\ CD).iso
	7z x "$<" -o$@

.PHONY: clean
clean:
	git clean -xfd asm/
	git clean -xfd build/
	git clean -xfd config/

format: bin/clang-format
	find src/ include/ -type f \( -name '*.c' -o -name '*.h' \) -print0 | xargs -0 -P$$(nproc) bin/clang-format -i

build/us/%.o: %
	ninja $@
