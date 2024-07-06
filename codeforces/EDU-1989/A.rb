gets.to_i.times do 
  x,y = gets.strip.split(' ').map(&:to_i)
  if y>=-1 then
    puts("yes")
  else
    puts("no")
  end
end
