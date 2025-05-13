gets.to_i.times do 
  n, f, k = gets.strip.split(' ').map(&:to_i)
  a = gets.strip.split(' ').map(&:to_i)
  if n==k then
    puts("YES")
    next
  end

  f = a[f-1]
  na = Array.new(101){0}
  a.each{|x| na[x]+=1}
  a = []
  na.each_with_index do |v, i|
    if v>0 then
      v.times{a << i}
    end
  end
  a = a.reverse
  # puts(a.to_s)
  
  if a[k-1]==f and a[k]==f then
    puts("MAYBE")
  elsif a[k-1] <= f then
    puts("YES")
  else
    puts("NO")
  end
end

