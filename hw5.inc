.macro sum_body  # (arr, size) -> sum, count
	mv t0 a0
	mv t1 a1
	
	li a0 0
	li a1 0
	
	loop:
	beqz t1 end
		lw t2 (t0)
		add t3 a0 t2
		
		bltz t2 negg
			blt t3 a0 end
			b ok
		negg:
			bge t3 a0 end
		
		ok:
		mv a0 t3
		addi a1 a1 1
		addi t1 t1 -1
		addi t0 t0 4
		b loop	
	end:
.end_macro

func (_sum, sum_body)