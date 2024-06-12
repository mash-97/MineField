gets.to_i.times do 
  n = gets.to_i
  a = gets.strip.split(' ').map(&:to_i)
  gcda = []
  i = 0
  while i<n-1
    # gcda << [a[i].gcd(a[i+1]), [i, i+1]]
    gcda << a[i].gcd(a[i+1])
    i+=1
  end
  puts(a.to_s)
  puts(gcda.to_s)
  puts()
  # count = 0
  # prev = 0
  # cindx = 1
  # while cindx < n-1 
  #   if gcda[cindx-1][0] > gcda[cindx][0]
  #     probable = gcda[cindx-1][1][1].gcd(gcda[cindx-1][1][0])
  #     if probable >= gcda[cindx-1][0]
end
