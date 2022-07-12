puts(`dir`)
puts('Press Enter')
gets()

puts(%x/dir/)
puts('Press Enter')

gets

puts(%x<echo "Hello World">)
puts('Press Enter""')

gets()
puts(%x`notepad`)
puts('Press Enter')
gets()
print("Goodbye #{%x<calc>}")