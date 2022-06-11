# Program Interaction

> https://pwn.college/modules/interaction

## Useful Tools for ELF Files

`7f` **`45` `4c` `46`**

* edit binaries directly with `vim -b`
* `readelf`
    * e.g. `readelf -a cat`
* `objdump`
* `nm`
    * e.g. `nm -D cat` or `nm -a cat`
* `patchelf`
* `objcopy`
    * e.g. `objcopy --dump-section .rodata=cat.hahah cat`
* load ELFs with their interpreters directly
    * e.g. `/lib64/ld-linux-x86-64.so.2 ./cat $file`
* mess with loading using environment variables
    * `LD_PRELOAD` (obvious)
        * e.g. `LD_PRELOAD=./preload.so ./cat cat.c`
    * `LD_LIBRARY_PATH`
        * e.g. `LD_LIBRARY_PATH=/some/library/path ./cat cat.c`
    * use `-E FOO=bar` to apply the environment variables when `strace`ing
* getting a program to inspect files in `/proc/self` is interesting, e.g.
    * `xxd /proc/self/cmdline`
    * virtual memory space in `/proc/self/maps`

## External Links

* https://ide.kaitai.io/
* https://www.intezer.com/blog/research/executable-linkable-format-101-part1-sections-segments/
* https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
