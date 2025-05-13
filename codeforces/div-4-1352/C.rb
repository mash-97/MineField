

gets.to_i.times do 
  n, k = gets.strip.split(' ').map(&:to_i)
  x = k/(n-1)
  x -= (k%(n-1)==0) ? 1 : 0
  kn = x*n
  kn += (k%(n-1)==0) ? (n-1) : (k%(n-1))
  puts(kn)
end
