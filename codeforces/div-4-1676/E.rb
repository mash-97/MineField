

def recurrence(count=0, rn, n)
  if count==$n then
    if rn!=0 then
      return -1
    else
      $dp[n] = count
      return count
    end
  end
end

def main()
  gets.to_i.times do 
    $n, $q = gets.strip.split(' ').map(&:to_i)
    arr = gets.strip.split(' ').map(&:to_i)
    $maxi = arr.max 
    $array = Array.new(maxi+1){0}
    arr.each{|x|$array[x]+=1}
    $numbers = $array.each_with_index.select{|x,i|x!=0}.collect{|x|x.last}
    $dp = {}

  end
end

if $0 == __FILE__ then
  main()
end
