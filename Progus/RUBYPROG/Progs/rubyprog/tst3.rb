class Array
	def concatenate
		@string = ''
		self.each{|x| @string = @string << x<<' '}
		return @string
	end
end

a = "This","will","be a string"
puts a.concatenate