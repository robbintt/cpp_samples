# Compiling c++ for OpenWRT on Archer C7 V2


# Tools

- static compiled with crosstool-ng environment
  - success!
  - 5.7 MB is too large

- used `opkg install libstdcpp` to install g++ library in /usr/lib on OpenWRT
  - i need to have a compatible gcc and maybe g++ version in crosstoool-ng
  - only 1 mb
  - i really need to get dynamic linking working

- dynamically linked with LDFLAGS to set ld.so path, see Makefile
  - this absolutely worked
  - i had to build crosstool-ng toolchain with my custom .config
    - stored here as crosstool-ng.mips-unknown-linux-musl.config
  - one of the important customizations was downgrading gcc to 9.5 to be compatible with the opkg libstdcpp which was 8.4.0
    - I did this by setting the crosstool-ng gcc to 8.5.0

- to make the menuconfig, I used an x86 example of musl, then modified it for mips32


# rough steps

- use the .config to build your crosstool-ng
- use the included Makefile to properly statically link your executable
  - use ldd to debug your linking
  - if the linker is in the wrong place (ld.so.1 file), ldd won't actually tell you.



## ldd

Example of checking linking

```
root@my_router:~# ldd my_program
        /lib/ld-musl-mips-sf.so.1 (0x77e36000)
        libstdc++.so.6 => /usr/lib/libstdc++.so.6 (0x77d36000)
        libgcc_s.so.1 => /lib/libgcc_s.so.1 (0x77d12000)
        libc.so => /lib/ld-musl-mips-sf.so.1 (0x77e36000)
```
