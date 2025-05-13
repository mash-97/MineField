
def zero_check(s)
  return ((s.size==3 and (s.last==0 or s.first==0)) or (s.size>3 and s.include?(0)))
end


def minSum(array)
  return (array.first*10+array.last) if array.size==2
  indx = 0
  sum = 0
  array.each do |x|
    sum += x if x!=1
  end
  min_sum = (sum+10)*100
  indx = 0
  while indx < array.size-1 do 
    n1 = array[indx]
    n2 = array[indx+1]
    sx = sum
    n = n1*10+n2

    if n!=1 or (n==1 and sx==0) then
      sx -= n1 if n1 != 1
      sx -= n2 if n2 != 1
      sx += n
    end
    # puts("sx: #{sx}")
    if sx < min_sum then
      min_sum = sx
    end
    indx += 1
  end
  # puts("min_sum: #{min_sum}")
  return min_sum
end



gets.to_i.times do |i|
  n = gets.to_i
  s = gets.strip.chars.map(&:to_i)
  z = zero_check(s)
  ms = minSum(s)
  ans = z ? 0 : ms
  puts(ans)
end
