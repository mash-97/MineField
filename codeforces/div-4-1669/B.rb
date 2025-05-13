gets.to_i.times do 
  n = gets.to_i 
  a = gets.strip.split(' ').map(&:to_i)
  arr = Array.new(n+1){0}
  a.each{|indx| arr[indx] += 1}
  ans = arr.find_index{|e| e>=3}
  ans = (ans!=nil and ans>=1) ? ans : -1
  puts(ans)
end


