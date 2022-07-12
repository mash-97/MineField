a = (1..10)
b = (-10..-1)
c = (-10..10)
d = ('a'..'z')			#two dot array - 'a'..'z'
e = ('a'...'z')		#three dot array  - 'a'..'y'

f = (1.4..2.5)		#floating point range

puts a,"----------"
a.each{|a| puts a}
puts b,"----------"
b.each{|b| puts b}
puts c,"----------"
c.each{|c| puts c}
puts d,"----------"
d.each{|d| puts d}
puts e,"----------"
e.each{|x| puts x}
gets
