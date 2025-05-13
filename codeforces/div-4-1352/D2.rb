gets.to_i.times do 
  n = gets.to_i 
  arr = gets.strip.split(' ').map(&:to_i)
  sa, sb = 0, 0
  pa, pb = 0, 0
  moves = 0

  while not arr.empty? do 
    moves += 1
    if moves.odd? then 
      temp_sum = 0
      while temp_sum <= pb and not arr.empty? do 
        temp_sum += arr.shift
      end
      pa = temp_sum
      sa += pa
    else
      temp_sum = 0
      while temp_sum <= pa and not arr.empty? do 
        temp_sum += arr.pop
      end
      pb = temp_sum
      sb += temp_sum
    end
  end

  puts("#{moves} #{sa} #{sb}")
end
