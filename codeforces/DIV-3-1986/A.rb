gets.to_i.times do 
  x = gets.strip.split(' ').map(&:to_i)
  min = 111
  (0..10).each do |a|
    f = x.collect{|_|(a-_).abs}.sum
    if min > f then
      min = f 
    end
  end
  puts(min)
end

