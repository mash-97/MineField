puts(/cde/ =~ 'abcdefg')
puts(/cde/.match('abcdefg'))
p('abcdefg'.match(/cde/))

puts(/xde/ =~ 'abcdefg')
puts(/xde/.match('abcdefg'))
p(/xde/.match('abcdefg'))
