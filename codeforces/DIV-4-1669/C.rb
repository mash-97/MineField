def main
  gets.to_i.times do
    n = gets.to_i
    a = gets.strip.split(' ').map(&:to_i)
    r = true
    for indx in (1...a.size)
      x =  ((a[indx]&1) == (a[(indx&1)]&1))
      r &&= x
    end

    if r then
      puts("Yes")
    else
      puts("No")
    end
  end
end

main()