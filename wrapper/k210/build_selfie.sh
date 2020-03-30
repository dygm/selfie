#!/usr/bin/bash

# COMPILATION
#riscv64-unknown-elf-gcc -mabi=lp64 -march=rv64imafdc -ffreestanding -nostdlib -c sbi_wrapper.c -I../opensbi/include -o libsbi_wrapper.o
riscv64-unknown-elf-gcc -g3 -mabi=lp64 -march=rv64imafdc -mcmodel=medany -ffreestanding -nostdlib -c ../../selfie.c -o selfie.o -D'uint64_t = unsigned long long int'
riscv64-unknown-elf-gcc -mabi=lp64 -march=rv64imafdc -mcmodel=medany -ffreestanding -nostdlib -I../opensbi/include  -c hello-world.S -o hello_world_S.o
riscv64-unknown-elf-gcc -g3 -mabi=lp64 -march=rv64imafdc -mcmodel=medany -ffreestanding -nostdlib -c ../sbi_wrapper.c -o sbi_wrapper.o -I../opensbi/include -L../opensbi/build/lib/ -lsbi

# MERGE OBJECT FILES
riscv64-unknown-elf-ld -r -b elf64-littleriscv -m elf64lriscv hello_world_S.o sbi_wrapper.o selfie.o -L../opensbi/build/lib -lsbi -o test.o

# LINKER SCRIPT PREPROCESSING
riscv64-unknown-elf-cpp  -DFW_TEXT_START=0x80000000 -DFW_PAYLOAD_OFFSET=0x1A000 -DFW_PAYLOAD_ALIGN=0x1000 -x c test.elf.ldS | grep -v '#' > test.elf.preprocessed.ld

# LINKING
riscv64-unknown-elf-gcc -mabi=lp64 -march=rv64imafdc -mcmodel=medany -ffreestanding -nostdlib test.o -L../opensbi/build/lib -o own-payload.elf -T ./test.elf.preprocessed.ld

riscv64-unknown-elf-objcopy -S -O binary own-payload.elf own-payload.bin