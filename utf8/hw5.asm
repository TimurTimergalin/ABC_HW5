.include "lib.inc"

.data
	.align 2
	arr: .space 40
	s_sum: .asciz "Сумма: "
	s_count: .asciz "Количество слагаемых: "
.globl main
.text
main:
	input (arr, 10)
	mv s0 a0
	sum (arr, s0)
	mv s1 a0
	mv s2 a1
	
	print_str (s_sum)
	print_num (s1)
	new_line()
	print_str (s_count)
	print_num (s2)
	exit()

	