gets.to_i.times do 
  n = gets.to_i 
  arr = gets.strip.split(' ').map(&:to_i)
  sa, sb = 0, 0
  pa, pb = 0, 0
  ai = -1
  bi = n
  ab = true
  moves = 0
  while ((moves.even? and ai+1<bi and ai+1<n) or (moves.odd? and ai<bi-1 and bi-1>-1)) do 
    temp_sum = 0
    moves += 1
    
    if moves.odd? then 
      while (ai+1<bi and ai+1<n) and (temp_sum <= pb) do 
        ai += 1
        temp_sum += arr[ai]
        
      end
      pa = temp_sum
      sa += pa 
    else
      while (bi-1>ai and bi-1>-1) and (temp_sum <= pa) do 
        bi -= 1
        temp_sum += arr[bi]
      end
      pb = temp_sum
      sb += pb 
    end
  end

  puts("#{moves} #{sa} #{sb}")
end
