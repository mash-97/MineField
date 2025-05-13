def minimumRoundAddends(n)
  addends = []
  i = 0
  while n!=0 do 
    r = n%10
    n /= 10
    addends << r*10**i if r!=0
    i += 1
  end
  return addends
end

gets.to_i.times do 
  n = gets.to_i
  addends = minimumRoundAddends(n)
  puts(addends.size)
  puts(addends.map(&:to_s).join(' '))
end
