array1  = ['h', 'e', 'l', 'l', 'o', ' ' , 'w', 'o', 'r', 'l', 'd']
array2 = array1
array3 = array1.clone

array1.reverse!

puts(array1.to_s)
puts(array2.to_s)
puts(array3.to_s)
gets