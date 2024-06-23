def gcdcheck(arr)
  pgcd = arr[0].gcd(arr[1])
  (1...(arr.size-1)).each do 
    |indx|
    cgcd = arr[indx].gcd(arr[indx+1])
    if cgcd < pgcd then
      return indx
    end
    pgcd = cgcd
  end
  return true
end


gets.to_i.times do 
  |t|
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  
  cindx = gcdcheck(a)
  # puts("cindx: #{cindx}")
  if cindx==true then
    puts("yes")
  else
    pa = a.dup
    pa.delete_at(cindx-1)
    pa = gcdcheck(pa)==true
    ca = a.dup
    ca.delete_at(cindx)
    ca = gcdcheck(ca)==true
    aa = a.dup
    aa.delete_at(cindx+1)
    aa = gcdcheck(aa)==true
    if pa or ca or aa then
      puts("yes")
    else
      puts("no")
    end
  end
end

