array1 = [1,2,3,4,5]
array2 = array1.clone

array3 = [1,2,3,4]
array4 = [1,2,3,5]

array5 = [1000, 2000, 3000]
array6 = [1,2]

array7 = [2,1]

array8 = ["hello", "world"]
array9 = ["Hello", "World"]
print("#{array1}<=>#{array2}::")
p(array1<=>array2)		#0
puts;puts

print("#{array3}<=>#{array1}::")
p(array3<=>array1)		#1
puts;puts

print("#{array4}<=>#{array3}::")
p(array4<=>array3)		#
puts;puts

print("#{array5}<=>#{array4}::")
p(array5<=>array4)		#
puts;puts

print("#{array7}<=>#{array6}::")
p(array7<=>array6)		#
puts;puts

print("#{array8}<=>#{array7}::")
p(array8<=>array7)		#nil
puts;puts

print("#{array9}<=>#{array8}::")
p(array9<=>array8)		#
puts;puts

gets
