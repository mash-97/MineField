a = gets.to_i
b = gets.to_i
c = gets.to_i
d = gets.to_i

if((b > c and d > a) and ((c+d) > (a+b)) and (not(c<0 and d<0) and a%2==0)) then puts("Valores aceitos")
else puts("Valores nao aceitos") end
gets