e = %w{a e i}
o = %w{p s t x y z}
l = e+o
a = []

l.permutation(5) do |x|
	if e.include?(x[1]) && e.include?(x[3]) && [x[0], x[2], x[4]].join =~ /^[#{o.join}]{3}$/ then
		a<<x.join
	end
end


puts a
