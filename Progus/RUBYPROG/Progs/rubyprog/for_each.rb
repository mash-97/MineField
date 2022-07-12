#--- Example 1 ---
#  i)for

for s in ['one', 'two', 'three'] do
	print (s)
end
puts
# ii)each

['one', 'two', 'three'].each do |s|
	print (s)
end
puts


#--- Example 2 ---
#  i)for

for x in [1,"two", [3,4,5]] do print (x) end
puts
# ii)each
[1,"two", [3,4,5]].each do|x| print (x) end
puts
gets
