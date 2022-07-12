############class methods 2 .rb ############
class Box
	def initialize(aStr)
		@msg = aStr
	end
	
	def look_inside
		puts(@msg)
	end
end

starprize = Box.new("Star Prize")			#Create a singleton method.
def starprize.congratulate
	puts("You've won a fabulous holiday in Grimsby!")
end

boxes = [Box.new("Box 1 is empty"), Box.new("Box 2 is empty"), starprize, Box.new("Box 3 is empty")]

boxes.each{
	|item|
	item.look_inside
	#Test if the congratulate singleton method exists before calling it.
	#if item.singleton_methods.include?(:congratulate) then
	if item.respond_to?(:congratulate) then #an alternative test
		item.congratulate
	end
}
gets
		