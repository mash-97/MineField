gets.to_i.times do
  n, m = gets.strip.split(' ').map(&:to_i)

  div = n/m 
  xnum = div
  if (n.odd? and m.even?) or n<m then 
    xnum = 0
  elsif n%m==0 then
    xnum = div
  elsif n.odd? and m.odd? then
    xnum = div.even? ? div-1 : div # oddify
  elsif n.even? and m.odd? then 
    xnum = div.odd? ? div-1 : div # evenify
  elsif m.even? and m.even? then 
    xnum = div
  end

  if n==1 and m==1 then 
    puts("yes")
    puts(1)
  
  elsif ((xnum*(m-1)) + (n-(xnum*(m-1))))!=n  or (xnum*(m-1))==0 or (n-(xnum*(m-1)))==0 then 
    puts("no")
  else
    puts("yes")
    (m-1).times do 
      print("#{xnum} ")
    end
    puts((n-(xnum*(m-1))))
  end

end
