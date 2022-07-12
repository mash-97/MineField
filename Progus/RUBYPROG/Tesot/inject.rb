class Range
	def inj(&x)
		a = self.to_a
		r = a[0]
		a[1..a.length].each{|x| r = yield(r,x)}
		return r
	end
end



(1..2).inj{|x| puts("x: #{x}")}
