cmd_/root/ProgramC/linux/hello_world.mod := printf '%s\n'   hello_world.o | awk '!x[$$0]++ { print("/root/ProgramC/linux/"$$0) }' > /root/ProgramC/linux/hello_world.mod
