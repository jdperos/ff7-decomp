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
disks/betaus: disks/Final\ Fantasy\ VII\ (USA)\ (Interactive\ Sampler\ CD).iso
	7z x "$<" -o$@


.PHONY: clean
clean:
	git clean -xfd asm/
	git clean -xfd build/
	git clean -xfd config/

build/us/%.o: %
	ninja $@
