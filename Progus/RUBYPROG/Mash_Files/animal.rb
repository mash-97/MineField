
module Animal
	class Dog
		attr_accessor(:name, :gender, :color, :barking)
		def initialize(name, gender, color, barking_style)
			@name = name
			@gender = gender
			@color = color
			@bark = barking_style
			if(@gender.downcase=='male') then puts("This Dog name is #{@name}. He is #{@color}. Barks like #{@bark}.")
			elsif(@gender.downcase=='female') then puts("This Dog name is #{@name}. She is #{@color}. Barks like #{@bark}.")
			else puts("A new Dog") end
		end
		
		def bark(times)
			times.times(){puts @bark}
		end
				
	end
			
	class Cat
		attr_accessor(:name, :gender, :color, :meowing)
		def initialize(name, gender, color, meowing_style)
			@name = name
			@gender = gender 
			@color = color
			@meowing = meowing_style
			if(@gender.downcase=='male') then puts("This Cat name is #{@name}. He is #{@color}. Barks like #{@bark}.")
			elsif(@gender.downcase=='female') then puts("This Cat name is #{@name}. She is #{@color}. Barks like #{@bark}.")
			else puts("A new Cat") end
		end
				
		def meow(times)
			times.times{puts @meowing}
		end
	end
end


