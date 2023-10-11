# Библиотека для ввода/вывода массивов


# Далее нотация (arg1, arg2, ...) -> res1, res2 означает, что перед запуском подпрограммы 
# в a0 должен лежать arg1, в a1 - arg2 и т.д.
# а после запуска в a0 будет лежать res1, в a1 - res2


# Производит ввод массива. В случае, если введенный массив окажется неправильной длины, аварийно завершит программу
.macro input_body  # (arr, max_length) -> length
.data
	s_input_size: .asciz "Введите размер массива: "
	s_input_elements: .asciz "Введите элементы массива:\n"
	s_invalid_size: .asciz "Ошибка: размер должен быть числом от 0 до 10"
.text
	mv t1 a0  # В t1 адрес массива

	la a0 s_input_size
	li a7 4  # Вывод строки
	ecall
	
	li a7 5  # ввод числа
	ecall
	
	mv t6 a0  # В t6 размер массива
	
	bgt a0 a1 invalid
	bltz a0 invalid
	b valid
	invalid:  # В случае, если введен неправильный размер
		la a0 s_invalid_size
		li a7 4
		ecall
		exit (1)
	valid:
		li a7 4
		la a0 s_input_elements
		ecall
		
		li a7 5
		mv t0 t6  # В t0 счётчик цикла
		
		loop:  # Ввод элементов массива
		beqz t0 end
			# Сохраняем введенные элементы в массив
			ecall  # a7 = 5
			sw a0 (t1)
			addi t1 t1 4
			addi t0 t0 -1
			b loop
		end:
		mv a0 t6
.end_macro

# Вывод массива в консоль 
.macro print_body # (arr, size) 
.data
	s_sp: .asciz " "
.text
	mv t1 a0
	
	loop:
	beqz a1 end
		# Выводим элемент с пробелом после
		lw a0 (t1)
		li a7 1
		ecall
		li a7 4
		la a0 s_sp
		ecall
		addi a1 a1 -1
		addi t1 t1 4
		b loop
	end:
	new_line ()
.end_macro

# Определение подпрограмм

func(_input, input_body)
func(_print, print_body)