############ str..reverse .rb ############
str1 = "hello"
puts(str1.object_id)

str1.reverse
puts str1
puts str1.object_id

puts

str1 = "hello"
puts(str1.object_id)
str1.reverse!
puts(str1)
puts(str1.object_id)
puts

str1 = "hello"
puts(str1.object_id)
str1 = str1.reverse
puts(str1)
puts(str1.object_id)

gets