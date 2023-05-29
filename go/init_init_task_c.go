package linux

import "unsafe"

type taskStruct struct {
	stack unsafe.Pointer
}

// extern unsigned long init_stack[THREAD_SIZE / sizeof(unsigned long)];

// var initStack [threadSize / unsafe.Sizeof(uintptr(0))]uintptr
var initTask taskStruct = taskStruct{
	stack: unsafe.Pointer(uintptr(0)),
}
