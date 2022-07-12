################################################################################################################################################################
################################################################################################################################################################
#															         CLASSES
################################################################################################################################################################
#String Class...
class String
	
	def rl										#read all the lines from the self
		if(File.exist?(self)) then 	
			IO.foreach(self){|l|puts l}
		else warn("File doesn't exist!!!") end
	end
end

#Integer class...
class Integer
	@@factorial_hash = Hash.new{
		|s, k|
		k==0 ? 1 : s[k] = (Math::gamma(k).floor)*k
	}
	
	def facto
		return @@factorial_hash[self]
	end
	
	def factorial
		result = 1
		(1..self).each{|x| result*=x}
		return result
	end
	
	def bits
		number = self
		bits = ""
		if(self==0) then return '0' end
		until number==0 do
			bits << (number&1).to_s
			number >>=1
		end
		return bits.reverse!
	end
end

#Array
class Array
	def cut_spaces()
		a = []
		self.each{|x| if(x!=nil && x!=' ') then a << x end}
		a
	end
end
class Array
	def match(match_against_data)
		self.flatten.each do 
			|e|
			if e.match(match_against_data) then return e.match(match_against_data) end
		end
		return nil
	end
	def removeNilOrZL
		self.each do |s|
			self.delete(s) if s.to_s.length==0
		end
		self
	end
end
################################################################################################################################################################
################################################################################################################################################################
