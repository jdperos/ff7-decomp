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
