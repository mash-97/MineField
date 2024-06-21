gets.to_i.times do 
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  puts(a.last + a[..-2].max)
end
