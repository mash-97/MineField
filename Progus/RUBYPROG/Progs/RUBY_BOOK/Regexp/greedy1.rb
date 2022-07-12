string = 'The cat sat on the mat!'
puts(/.*at/.match(string))

puts(/.*?at/.match(string))

a = string =~ (/.*at/)
puts $~
