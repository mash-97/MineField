module X
	@instvar = "X's @instvar"
	@@classvar = "X's @@classvar"
	
	def amethod
		@instvar = 10
		puts(@instvar)
	end
	
	def self.aaa
		puts(@instvar)
	end
end

include X
X.aaa
puts(@instvar)
amethod
puts(@instvar)
@instvar = "hello world"
puts(@instvar)
puts(@@classvar)
@@classvar = "bye bye"
puts(@@classvar)

puts("Module X's instance variables...")
p(X.instance_variables)
puts("Self's instance variables...")
p(self.instance_variables)

gets