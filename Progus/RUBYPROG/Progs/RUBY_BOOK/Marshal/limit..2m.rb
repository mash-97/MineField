class Mclass
	attr_accessor(:num, :str, :arr)
	
	def initialize(aNum, aStr, anArray)
		@num = aNum
		@str = aStr
		@arr = anArray
	end
	
	
	def marshal_dump
		[@num, @arr, @str]
	end
	
	def marshal_load(data)
		@num = data[0]
		@arr = data[1]
		@str = data[2]
	end
end

ob = Mclass.new(100, "fred", [1,2,3])
p(ob)
marshal_data = File.open('limit.mars', 'w'){
	|f|
	Marshal.dump(ob, f)
}
puts("marshal dump ob data: #{marshal_data}")

File.open("limit.mars", 'r'){
	|f|
	$ob2 = Marshal.load(f)
}
p($ob2)
puts("ob2.str = #{$ob2.str}")
