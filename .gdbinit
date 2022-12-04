target remote localhost:1234
#symbol-file arch/arm/boot/compressed/vmlinux -o 0x40010000
set pagination off
symbol-file vmlinux
tui enable
layout src
#layout regs
#display /i $pc
define hook-stop
info local
end
tbreak start_kernel
# source .breakpoints
# continue
set pagination on

