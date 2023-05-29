package linux

// func endOfStack(const struct task_struct *task) *uint
func endOfStack(task *taskStruct) *uintptr {
	if configStackGrowsup == 1 {
		return uintptr(task.stack) + threadSize - 1
	} else {
		return uintptr(task.stack)
	}
}
