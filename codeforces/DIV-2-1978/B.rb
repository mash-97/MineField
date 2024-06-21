gets.to_i.times do 
  n, a, b = gets.strip.split(' ').map(&:to_i)
  m = [n, b].min 
  sum = 0
  if a<b then
    i = (b-a+1)
    x = a
    if i>m then
      x += (i-m)
      i = m
    end
    r = i/2
    sum += (r*(b+x))
    if i.odd? then
      sum += (b-r)
    end
    n -= i
  end
  sum += a*n  
  puts(sum)
end
