gets.to_i.times do |__t__|
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  gcda = []
  i = 0
  while i<n-1
    # gcda << [a[i].gcd(a[i+1]), [i, i+1]]
    gcda << a[i].gcd(a[i+1])
    i+=1
  end
  puts("###> #{__t__+1} ")
  puts(a.to_s)
  print("   ")
  puts(gcda.to_s)
  puts()
  fcount = 0
  tcount = 0
  cindx = 1
  while fcount==0 and cindx < n-1 do 
    pa = a[cindx-1]
    ga = a[cindx]
    gb = a[cindx+1]
    
    if gcda[cindx] < gcda[cindx-1]
      pgcd = pa.gcd(gb)
      if pgcd >= gcda[cindx-1]
        tcount += 1
      else
        fcount += 1
      end
    end
    cindx += 1
  end
  if tcount == 1 then
    puts("yes")
  else
    puts("no")
  end
  

end
