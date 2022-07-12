########### override.rb ############
class MyClass
	def sayHello
		return "Hello from MyClass"
	end
	
	def sayGoodbye
		return "Goodbye from MyClass"
	end
end

class MyOtherClass < MyClass
	#Overrides MyClass.sayHello
	def sayHello
		return "Hello from MyOtherClass"
	end
	def to_s
		return "I am an instance of the #{self.class} class"
	end
	#Overrides MyClass.sayGoodbye but first calls that method with super.
	#So this version "adds to" MyClass.sayGoodbye.
	def sayGoodbye
		return super << " and also from MyOtherClass"
	end
end

myclassob = MyClass.new
myotherclassob = MyOtherClass.new
=begin
puts(myclassob.sayHello)
puts(myclassob.sayGoodbye)
puts(myclassob.to_s)
puts
puts(myotherclassob.sayHello)
puts(myotherclassob.sayGoodbye)
puts(myotherclassob.to_s)
=end

puts(myclassob)
puts(myotherclassob)
gets

gets
	