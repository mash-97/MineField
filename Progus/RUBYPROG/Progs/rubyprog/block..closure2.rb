def calcTax(taxRate)
	return lambda{|subtotal|
		subtotal * taxRate
	}
end
bookTax = calcTax(0.10)
vat = calcTax(0.175)

print("Tax due on book = ")
print(bookTax.call(10))

print("\nVat due on DVD = ")
print(vat.call(10))

gets