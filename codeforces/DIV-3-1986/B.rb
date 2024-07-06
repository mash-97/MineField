def normalize(matrix)
  n = matrix.size
  m = matrix.first.size
  ni = 0
  while ni < n do 
    mi = 0
    while mi < m do 
      ucv = rcv = dcv = lcv = -1
      ucv = matrix[ni-1][mi] if (ni-1)>=0
      rcv = matrix[ni][mi+1] if (mi+1<m)
      dcv = matrix[ni+1][mi] if (ni+1<n)
      lcv = matrix[ni][mi-1] if (mi-1>=0)
      maxcv = [ucv, rcv, dcv, lcv].max
      # puts("#>#{[ni, mi].to_s} => maxcv: #{maxcv}")
      if maxcv < matrix[ni][mi] then
        matrix[ni][mi] -= (matrix[ni][mi]-maxcv).abs
      end
      mi+=1
    end
    ni+=1
  end
  return matrix
end

gets.to_i.times do 
  n, m = gets.strip.split(' ').map(&:to_i)
  matrix = n.times.collect{gets.strip.split(' ').map(&:to_i)}
  matrix = normalize(matrix)
  matrix.each do |row|
    puts(row.map(&:to_s).join(' '))
  end
end
