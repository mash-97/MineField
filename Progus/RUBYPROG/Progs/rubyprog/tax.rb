taxrate = 0.175
subtotal = gets.to_f
if (subtotal < 0.0) then
	subtotal = 0.0
end
tax = subtotal*taxrate

puts "Tax on #{subtotal} is #{tax}, so the total is #{subtotal+tax}"