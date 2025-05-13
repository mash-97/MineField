gets.to_i.times do 
  n, m = gets.strip.split(' ').map(&:to_i)
  if (n.odd? and m.even?) or n<m then 
    puts("no")
    next
  end

  prefix = 0
  if n.odd? and m.odd? then 
    prefix = 1
  elsif n.even? and m.odd? then 
    prefix = 2
  elsif n.even? and m.even? then 
    prefix = 2
  end

  if (n/m)!=0 and (n%m)==0 then 
    x = n/m
    puts("yes")
    (m-1).times do print("#{x} ") end 
    puts(x)
  elsif prefix == 0 or (n-(prefix*(m-1)))<=0 then 
    puts("no")
  else
    puts("yes")
    (m-1).times do print("#{prefix} ") end 
    puts((n-(prefix*(m-1))))
  end
end
