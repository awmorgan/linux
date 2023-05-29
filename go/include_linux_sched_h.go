package linux

// extern unsigned long init_stack[THREAD_SIZE / sizeof(unsigned long)];
vat initStack[(threadSize / unsafe.Sizeof(uintptr(0)))]uint
