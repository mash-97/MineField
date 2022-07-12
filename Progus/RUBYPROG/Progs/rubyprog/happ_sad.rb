module Happy
	def Happy.mood
		return "happy"
	end
	
	def expression
		return "smiling"
	end
end

module Sad
	def Sad.mood
		return "sad"
	end
	
	def expression
		return "frowning"
	end
end

class Person
	include Happy
	include Sad
	attr_accessor :mood
	def initialize(a=1)
		if(a==1);@mood = Happy.mood
		else @mood = Sad.mood end
	end
end

p1 = Person.new(0)
puts(p1.mood)
puts(p1.expression)
gets