package linux


func StartKernel() {
	// string command_line
	// string after_dashes

	setTaskStackEndMagic(&initTask)

}
