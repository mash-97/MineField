gets.to_i.times do 
  n = gets.to_i 
  ans = (n<=1399) ? 4 : (n<=1599 ? 3 : (n<=1899 ? 2 : 1))
  puts("Division #{ans}")
end
