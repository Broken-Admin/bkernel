obj := out/kernel.o out/screen.o out/bootloader.o
bkernel : $(obj)
	ld -m elf_i386 -T source/linker.ld -o build/bkernel.out $^
out/kernel.o : source/kernel.c
	gcc -m32 -c source/kernel.c -o out/kernel.o
out/screen.o : source/screen.c
	gcc -m32 -c source/screen.c -o out/screen.o
out/bootloader.o : source/bootloader.asm
	nasm -f elf32 source/bootloader.asm -o out/bootloader.o
clean :
	rm out/*.o && rm build/*.out
test :
	qemu-system-i386 -kernel build/bkernel.out
