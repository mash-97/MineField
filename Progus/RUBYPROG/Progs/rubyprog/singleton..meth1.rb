##########single_methods1.rb#############
FULLMOON = false 		#<=try changing this to false

class Creature
	def initialize(aSpeech)
		@speech = aSpeech
	end
	
	def talk
		puts(@speech)
	end
	def anger
		puts("greeeeee")
	end
end

cat = Creature.new("miaow")
dog = Creature.new("woof")
budgie = Creature.new("Who's a pretty boy, then!")
werewolf = Creature.new("grow!")
def werewolf.howl
	if FULLMOON then
		puts("How-oo-ll-ooo-lll!")
	else
		anger
		talk
	end
end


werewolf.howl		#I can try out these....
werewolf.talk
budgie.talk
#But....
#budgie.howl    		#<=this won't work!

gets