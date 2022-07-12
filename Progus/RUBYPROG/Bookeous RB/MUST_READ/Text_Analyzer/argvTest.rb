
$a = 3
class Array
	def d!(&block)
		l = self.length
		for i in 0...length do
			
		self[i] = block[self[i]]
		end
		$a+=1
		->(x){block[:check].include?(x.class) ? self << block[x] : nil}
	end
end

b = %w%Ruby is cool. Why most of the programmers don't understand that?%

b = b.d! do |x| 
	mh = {
		:check => [String, Symbol, Integer, Float],
		String => [:upcase],
		Symbol => [:to_s, :upcase],
		Integer => [:to_s], 
		Float => [:to_s]
	}
	
	lam = ->(y) {
		mh[y].each{|z| x = x.send(z)}
		x
	}
	x==:check ? mh[x] : lam[x.class]
end
	
	
p b[3]
p b['dkfj']
p b[:kdjf]

			
