# ���������� ��� �����/������ ��������


# ����� ������� (arg1, arg2, ...) -> res1, res2 ��������, ��� ����� �������� ������������ 
# � a0 ������ ������ arg1, � a1 - arg2 � �.�.
# � ����� ������� � a0 ����� ������ res1, � a1 - res2


# ���������� ���� �������. � ������, ���� ��������� ������ �������� ������������ �����, �������� �������� ���������
.macro input_body  # (arr, max_length) -> length
.data
	s_input_size: .asciz "������� ������ �������: "
	s_input_elements: .asciz "������� �������� �������:\n"
	s_invalid_size: .asciz "������: ������ ������ ���� ������ �� 0 �� 10"
.text
	mv t1 a0  # � t1 ����� �������

	la a0 s_input_size
	li a7 4  # ����� ������
	ecall
	
	li a7 5  # ���� �����
	ecall
	
	mv t6 a0  # � t6 ������ �������
	
	bgt a0 a1 invalid
	bltz a0 invalid
	b valid
	invalid:  # � ������, ���� ������ ������������ ������
		la a0 s_invalid_size
		li a7 4
		ecall
		exit (1)
	valid:
		li a7 4
		la a0 s_input_elements
		ecall
		
		li a7 5
		mv t0 t6  # � t0 ������� �����
		
		loop:  # ���� ��������� �������
		beqz t0 end
			# ��������� ��������� �������� � ������
			ecall  # a7 = 5
			sw a0 (t1)
			addi t1 t1 4
			addi t0 t0 -1
			b loop
		end:
		mv a0 t6
.end_macro

# ����� ������� � ������� 
.macro print_body # (arr, size) 
.data
	s_sp: .asciz " "
.text
	mv t1 a0
	
	loop:
	beqz a1 end
		# ������� ������� � �������� �����
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

# ����������� �����������

func(_input, input_body)
func(_print, print_body)