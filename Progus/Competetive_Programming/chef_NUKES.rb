a,n,k = gets.split(" ").map(&:to_i)
a1 = a

results_arr = []
k.times do 
	results_arr << (a%(n+1))
	a /= (n+1)
end

results_arr.display()

results_arr2 = Array.new(k,0)
k.times do |indx|
	results_arr2[indx] = a1
	a1 /= (n+1)
end

k.times do |indx|
	results_arr2[indx] %= (n+1)
end

results_arr2.display()


