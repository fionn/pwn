MAKEFLAGS += --warn-undefined-variables

CC ?= gcc
CFLAGS ?= -w

.PHONY: all
all: cat cat_static cat_static_pie cat_haha preload.so

cat: cat.c
	@$(CC) -o $@ $<

cat.hahah: cat
	objcopy --dump-section .rodata=$@ $<
	xxd $@

.PHONY: patch_cat_hahah
patch_cat_hahah: cat.hahah cat
	objcopy --update-section .rodata=$^

.PHONY: cat_patch_interpreter
cat_patch_interpreter: cat
	patchelf --set-interpreter /some/interpreter $<
	ldd $<

.PHONY: cat_patch_rpath
cat_patch_rpath: cat
	patchelf --set-rpath /some/runpath $<

cat_static: cat.c
	@$(CC) -static -o $@ $<
	./$@ /proc/self/maps

cat_static_pie: cat.c
	@$(CC) -static-pie -o $@ $<
	./$@ /proc/self/maps

cat_haha: cat_haha.c
	@$(CC) -o $@ $<

preload.so: preload.c
	@$(CC) -shared -o $@ $<

start_main.so: start_main.c
	@$(CC) -shared -o $@ $<

env: env.c
	@$(CC) -o $@ $<

signal: signal.c
	@$(CC) -o $@ $<

alarm: alarm.c
	@$(CC) -o $@ $<
