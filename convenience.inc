# Макросы выхода
.macro exit
	li a7 10
	ecall
.end_macro

.macro exit (%code)
	li a7 93
	li a0 %code
	ecall
.end_macro

.macro print_num (%num)
	mv a0 %num
	li a7 1
	ecall
.end_macro

.macro print_num
	li a7 1
	ecall
.end_macro

.macro new_line
	li a7 11
	li a0 '\n'
	ecall
.end_macro

.macro print_str (%add)
	la a0 %add
	li a7 4
	ecall
.end_macro
