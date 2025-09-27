# Final Fantasy VII decomp (PSX)

Clone the repository:

```shell
git clone git@github.com:Xeeynamo/ff7-decomp.git --recursive &&\
cd ff7-decomp
```

Install the necessary dependencies:

```shell
make dependencies

# Debian/Ubuntu
sudo apt install ninja-build 7zip bchunk binutils-mipsel-linux-gnu gcc-mipsel-linux-gnu

# Arch Linux
sudo pacman -S ninja 7zip bchunk
yay mipsel-linux-gnu-binutils mipsel-linux-gnu-gcc
```

Place the necessary disk files:

```shell
'disks/Final Fantasy VII (USA) (Disc 1).bin'
'disks/Final Fantasy VII (USA) (Disc 1).cue'
'disks/Final Fantasy VII (USA) (Interactive Sampler CD).bin' # OPTIONAL!
'disks/Final Fantasy VII (USA) (Interactive Sampler CD).cue' # OPTIONAL!
```

Then build the project:

```shell
make
```

## Game strings

The game features non-standard ASCII strings. This code base represent them as `_S("Hello FF7!")` and similar. To decode a FF7-style string into ASCII, use the tool as the following:

```shell
# compile it at least once
make bin/str

# specify an overlay and an offset in hex
bin/str disks/us/MENU/SAVEMENU.MNU 12DF8

# the program will now print on your terminal the FF7 string into readable ASCII
Saving. Do not remove Memory card.
```
