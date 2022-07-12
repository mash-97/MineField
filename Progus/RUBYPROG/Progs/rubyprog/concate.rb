############# concate . rb #############
str1 = "hello"
str2 = "world"
str3 = "goodbye"

puts("Before...")
puts("#{str1} #{str1.object_id}")
puts("#{str2} #{str2.object_id}")
puts("#{str3} #{str3.object_id}")

str3 = str2 << str1

puts("After...")
puts("#{str1} #{str1.object_id}")
puts("#{str2} #{str2.object_id}")
puts("#{str3} #{str3.object_id}")
str2 << " hmm"
puts("...#{str3} #{str3.object_id}")
gets