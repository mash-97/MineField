gets.to_i.times do 
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  mnemonics = [0]
  i = -1
  j = n 
  as = 0
  bs = 0
  while i+1<j or i<j-1 do 
    while as <= bs and i+1<n and i+1<j do 
      i += 1
      as += a[i]
      if as==bs then 
        mnemonics << (i+1)+(n-j)
      end
    end

    while bs <= as and 0<j and i < j-1 do 
      j -= 1
      bs += a[j]
      if as==bs then 
        mnemonics << (i+1)+(n-j)
      end
    end
  end

  puts(mnemonics.max)
end
