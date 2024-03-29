# Compiling c++ for OpenWRT on Archer C7 V2

- static compiled with crosstool-ng environment
  - success!
  - 5.7 MB is too large
- dynamically compiled and linked
  - success! 6 KB fibonacci (hello world equivalent) executable
  - many little pieces needed, listed below

## Alternatives?

- note that openwrt has its own build root: https://openwrt.org/docs/guide-developer/toolchain/crosscompile
  - but i don't know how to use it with c++17
  - probably it's not that bad but may have limitations
  - also some c hello world example here, but not c++17: 
    - https://openwrt.org/docs/guide-developer/helloworld/start
    - build: https://openwrt.org/docs/guide-developer/helloworld/chapter2
    - package for openwrt: https://openwrt.org/docs/guide-developer/helloworld/chapter3


# OpenWRT Toolchain Methodology (recommended)

time cost: very low

Not guaranteed compatible forwards between OpenWRT versions on the same host, although c++ does guarantee. Likely brittle points are dynamic linker, anything gcc related.


1. Get the tarball for either `toolchain` or `sdk`, and grep your g++ `filepath` and `filename`
2. Add the `bin/` folder in this `filepath` to your path with the shell script to add to path
3. Fix the makefile to have the `filename` for g++ in your bin/
4. make clean && make
5. Copy to your openwrt and go
6. consider learning how to use the SDK to compile opkg for openwrt install process


# Crosstool-ng Methodology (not recommended)

time cost: not too high with included crosstool .config, but not low.

Compatibility may suffer, brittle.


## Prep OpenWRT install for cpp

Apparently opkg libstdcpp only supports gcc 8.4.0 which only goes up to c++17 or something. c++20 did not work.

- used `opkg install libstdcpp` to install g++ library in /usr/lib on OpenWRT
  - i need to have a compatible gcc and maybe g++ version in crosstool-ng
  - only 1 mb
  - i really need to get dynamic linking working


# rough compiler setup steps

- use the .config to build your crosstool-ng
- use the included Makefile to properly dynamically link your executable
  - use ldd to debug your linking
  - if the linker is in the wrong place (ld.so.1 file), ldd won't actually tell you.

- dynamically linked with LDFLAGS to set ld.so path, see Makefile
  - this absolutely worked
  - i had to build crosstool-ng toolchain with my custom .config
    - stored here as crosstool-ng.mips-unknown-linux-musl.config
  - one of the important customizations was downgrading gcc to 9.5 to be compatible with the opkg libstdcpp which was 8.4.0
    - I did this by setting the crosstool-ng gcc to 8.5.0



# crosstool-ng

- I worked off master on github: https://github.com/crosstool-ng/crosstool-ng
- I followed the docs very closely: https://crosstool-ng.github.io/docs/configuration/

- First run "setting up host OS" dockerfile apt install command, even though the section is listed last... https://crosstool-ng.github.io/docs/os-setup/

- to make the menuconfig, I used an x86 example of musl, then modified it for mips32
  - it's committed alongside this readme

- I had a problem with ISL compile hanging and had to downgrade to 0.15: https://github.com/crosstool-ng/crosstool-ng/issues/1392
  - in the future, experiment with crosstool-ng build in docker if you want
  - sounds like this might be related to pyenv on my system, which is weird too

- The tool puts the finalized toolchain in `~/x-tools/mips-unknown-linux-musl/bin/`
  - put this bin on your path, e.g.:

```
cat ~/openwrt_build_dir.sh 
#!/bin/sh

# remember to run as "source script.sh"

BUILD_PATH=/home/robbintt/x-tools/mips-unknown-linux-musl/bin/

export PATH="${PATH}:$BUILD_PATH"
```


## ldd

Example of checking linking

```
root@my_router:~# ldd my_program
        /lib/ld-musl-mips-sf.so.1 (0x77e36000)
        libstdc++.so.6 => /usr/lib/libstdc++.so.6 (0x77d36000)
        libgcc_s.so.1 => /lib/libgcc_s.so.1 (0x77d12000)
        libc.so => /lib/ld-musl-mips-sf.so.1 (0x77e36000)
```
