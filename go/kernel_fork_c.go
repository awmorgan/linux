package linux

func setTaskStackEndMagic(tsk *taskStruct) {
	// unsigned long *stackend

	// stackend = end_of_stack(tsk);
	// *stackend = STACK_END_MAGIC;	/* for overflow detection */
}
