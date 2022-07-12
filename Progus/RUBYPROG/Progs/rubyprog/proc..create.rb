#proc_creating.rb

a = Proc.new{|x| x = x*10;puts(x)}
b = lambda{|x| x = x*10; puts(x)}
c = proc{|x| x.capitalize!}

puts(a.class)
puts(b.class)
puts(c.class)

puts a
puts b
puts c

gets
gets