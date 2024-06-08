gets.to_i.times do
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  b = gets.strip.split(' ').map(&:to_i)

  min_steps = 0
  indx = 0
  mcn = (a.max-b.last).abs 

  while indx < n do
    min_steps += (a[indx]-b[indx]).abs
    tab = [a[indx], b[indx]]
    if (tab.min..tab.max).include?(b.last) then
      mcn = 0
    end
    indx += 1
  end

  puts(min_steps+1+mcn)
end
