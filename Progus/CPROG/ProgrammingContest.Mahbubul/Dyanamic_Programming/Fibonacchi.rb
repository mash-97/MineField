
$fib = Array.new(100, nil)
$count = Array.new(100, 0)
def way(n,m)
	return 0 if n<0
	return 1 if n==0 or n==1
	
	result = 0
	(1..m).each{	|x|	
		break if n-x < 0
		if not $fib[n-x] then
			$count[n-x] += 1
			$fib[n-x] = way(n-x, m) 
		end
		result += $fib[n-x]
	}
	
	return result;
end


n = 0
while( (n=gets) != nil) do
	n,m = n.split(' ').map(&:to_i)
	puts("way(#{n}, #{m}): #{way(n,m)}")
	print($count[0...n])
	puts
	$fib = Array.new(10000, nil)
	$count = Array.new(10000, 0)
	
end
	
