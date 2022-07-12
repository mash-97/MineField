##############singleton  class 2 .rb ##############
class MyClass
	def initialize(aMsg)
		@msg = aMsg
	end
	
	def saySomething
		puts @msg
	end
end

starPrize = MyClass.new("star prize")

def starPrize.congratulate
	puts("Hello! You have won the Prize")
end
class << starPrize
	def place
		puts("You will find your Precious Prize at Shire.")
	end
	def time
		puts("The time to take your Precious Prize is 1:30 am.")
	end
end

boxes = [MyClass.new("box 1 is empty"),
		 MyClass.new("box 2 is empty"),
		 starPrize,
		 MyClass.new("box 3 is empty")]
boxes.each do |item|
	a = item.singleton_methods
	if(a == [:congratulate,:place,:time]) then
	#if((item.methods.include?(:congratulate) == true) and (item.methods.include?(:place) == true))
		item.saySomething
		item.congratulate
		item.place
		item.time
	end
end
gets