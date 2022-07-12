print("Enter a mathematical expression: ")
exp = gets().chomp()
print("This is the result of evaluating this with eval(): ")
puts(eval(exp))

print('This is the result of evaluating this inside a string "#{exp}": ')
puts("#{exp}")

puts("This is the class of the expression entered: #{exp.class}")
puts("Which, when evaluated like this (\#{eval(exp)}), gives: #{eval(exp)}")
puts

print("Enter the name of a string method (e.g. reverse or upcase: ")
# Here is another example showing how eval and "#{}" differ when evaluating
# a string
methodname = gets().chomp()
exp2 = "'Hello world'." << methodname
puts("#{exp2}")
puts("#{eval(exp2)}")
