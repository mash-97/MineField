gets.to_i.times do
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  m = a.min
  ec = 0
  a.each do |c|
    ec += c>m ? c-m : 0
  end
  puts(ec)
end
