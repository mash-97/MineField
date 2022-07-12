x = (1..5).collect{|i| i}
p(x)

array = [1,2,3,4,5]
y = array.collect{|i| i*i}
z = array.collect{|i| i+i}

p(y)
p(z)

p(array.include?(3))
p(array.include?(6))

p(array.min)
p(array.max)

gets