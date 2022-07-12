######### in..out.rb ##########
def change(x)
	x+=1
	return x
end

num = 10
puts("num.object_id = #{num.object_id}")
num = change(num)
puts("num.object_id = #{num.object_id}")
k = 11
puts("k.object_id = #{k.object_id}")

gets