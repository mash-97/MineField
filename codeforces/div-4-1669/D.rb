gets.to_i.times do
  n = gets.to_i
  a = gets.strip
  indx = 0
  p = true
  r, b = 0, 0
  while indx < n do
    if a[indx]=='W' then 
      p &&= ((r==b and b==0) or (b>0 and r>0))
      while indx<n and a[indx]=='W' do
        indx += 1
      end
      r=0
      b=0
      next
    end
    r += 1 if a[indx]=='R'
    b += 1 if a[indx]=='B'
    indx += 1
  end
  p &&= ((r==b and b==0) or (b>0 and r>0))
  if p then
    puts("yes")
  else
    puts("no")
  end
end
