
require("yaml")

f = File.open('friends.yml', 'w')
a = YAML.dump(["fred", "bert", "mary"], f)
puts("YO::: a = #{a}")
f.close

h = File.open('morefriends.yml', 'w'){
	|friendsfile|
	YAML.dump(["sally", "agnes", "john"], friendsfile)
}
puts("\n\nh = #{h}\n\n")
g = File.open('morefriends.yml', 'r'){
	|f|
	$arr = YAML.load(f)
}
puts("\n\ng = #{g}\n\n")

myfriends = YAML.load(File.open('friends.yml'))
morefriends = YAML.load(File.open('morefriends.yml'))

puts myfriends
puts

puts morefriends
puts

p($arr)
