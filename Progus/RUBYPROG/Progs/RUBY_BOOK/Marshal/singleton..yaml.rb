require 'yaml'
ob = Object.new

class << ob
	
	def xxx(aStr)
		@x = aStr
	end
	
	def getx
		return @x
	end
end

ob.xxx("YO!")
p(ob)

File.open('test.yml', 'w'){
	|f|
	YAML.dump(ob, f)
}

ob.xxx("new string")
p(ob)

File.open('test.yml'){
	|f|
	ob = YAML.load(f)
}

p(ob)
#puts("ob.xxx #{ob.getx}")

ob.xxx("goodbye")
