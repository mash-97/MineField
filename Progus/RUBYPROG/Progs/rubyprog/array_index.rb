array = ['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']

#Here we print each char in sequence
print(array[0, 5])
puts
puts("array[-5]: #{array[-5]}")
print(array[-5, 5])
puts
puts("array[0]: #{array[-array.length]}")
print(array[0..4])
puts
print(array[-5..-1])
puts

#Here we inspect the chars. Notice that we can index into an array like this..
#array[<start index>, <number of items>]
#or specify a range like this...
#array[<start index>..<end index>]
#
#So these are equivalent

p(array[0,5])
p(array[0..4])

gets