require("yaml")

class Tree

	attr_accessor(:name, :height, :leaves_size, :fruity)
	
	def initialize(*array)
		@name = array[0]
		@height = array[1]
		@leaves_size = array[2]
		@fruity = array[3]
	end
	
end

aTree = Tree.new
anotherTree = Tree.new("coconaut", 30)
anotherOne = Tree.new("Mango", 10, 0.2, true)

puts("###################")
puts(aTree)
puts(anotherTree)
puts(anotherOne)
puts("###################")

file_name = "Tree.yml";
file = File.open(file_name, "w")
file.puts(YAML.dump(aTree))
YAML.dump(anotherTree, file)
file.puts(anotherOne.to_yaml)

file.close()

puts("The file:: #{file_name} is going to be read, in yaml style:")
file = File.open(file_name, "r")
while(not file.eof()) do print(file.getc()) end

puts("The file:: #{file_name} is going to be read, in normal style:")
file.rewind()
puts(YAML.load(file).inspect)
file.rewind()
puts(YAML.load(file).inspect)
file.rewind()
puts(YAML.load(file).inspect)
puts()

puts("END")
file.close()


