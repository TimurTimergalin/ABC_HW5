.include "convenience.inc"
.include "mfunc.inc"
.include "hw5.inc"
.include "io.inc"

.macro input (%arr, %max_length)
	la a0 %arr
	li a1 %max_length
	jal _input
.end_macro
.macro print (%arr, %size)
	la a0 %arr
	mv a1 %size
	jal _print
.end_macro
.macro sum (%arr, %size)
	la a0 %arr
	mv a1 %size
	jal _sum
.end_macro