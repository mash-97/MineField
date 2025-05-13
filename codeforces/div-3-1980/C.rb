gets.to_i.times do 
  n = gets.to_i 
  a = gets.strip.split(' ').map(&:to_i)
  b = gets.strip.split(' ').map(&:to_i)
  m = gets.to_i
  d = gets.strip.split(' ').map(&:to_i)
  if not b.include?(d.last) then 
    puts("No")
    next
  end

  i = 0
  c = []
  while i<n do
    c<<b[i] if a[i]!=b[i] 
    i+=1
  end

  c = c.sort 
  d = d.sort 

  id = 0
  ic = 0
  while id<d.size and ic<c.size do 
    if d[id]==c[ic] then 
      id+=1
      ic+=1
    elsif d[id]<c[ic] then 
      id += 1
    else
      break
    end
  end

  if ic==c.size then 
    puts("Yes")
  else
    puts("No")
  end
end
