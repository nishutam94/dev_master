cmd_/root/ProgramC/linux/hello_world.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /root/ProgramC/linux/hello_world.ko /root/ProgramC/linux/hello_world.o /root/ProgramC/linux/hello_world.mod.o;  true