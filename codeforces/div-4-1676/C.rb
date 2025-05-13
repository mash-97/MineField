gets.to_i.times do 
  n, m = gets.strip.split(' ').map(&:to_i)
  strs = []
  n.times do 
    strs << gets.strip.split('')
  end

  diffs = []
  for i in 0...n do
    for j in (i+1)...n do
      diffs << strs[i].zip(strs[j]).collect{|x|(x.first.ord-x.last.ord).abs}.sum
    end
  end

  puts(diffs.min)
end
