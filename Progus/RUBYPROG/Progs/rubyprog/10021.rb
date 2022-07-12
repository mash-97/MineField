
def notasMoedas(format)
	money = $N/format
	$N %= format
	return money.to_i
end

$N = gets.to_f
if($N>=0 && $N<= 1000000.00) then 
	puts("NOTAS:")
	puts("#{notasMoedas(100)} nota(s) de R$ 100,00")
	puts("#{notasMoedas(50)} nota(s) de R$ 50,00")
	puts("#{notasMoedas(20)} nota(s) de R$ 20,00")
	puts("#{notasMoedas(10)} nota(s) de R$ 10,00")
	puts("#{notasMoedas(5)} nota(s) de R$ 5,00")
	puts("#{notasMoedas(2)} nota(s) de R$ 2,00")

	puts("MOEDAS:")
	puts("#{notasMoedas(1)} moeda(s) de R$ 1,00")
	puts("#{notasMoedas(0.5)} moeda(s) de R$ 0,50")
	puts("#{notasMoedas(0.25)} moeda(s) de R$ 0,25")
	puts("#{notasMoedas(0.10)} moeda(s) de R$ 0,10")
	puts("#{notasMoedas(0.05)} moeda(s) de R$ 0,05")
	puts("#{notasMoedas(0.01)} moeda(s) de R$ 0,01")
end
gets
