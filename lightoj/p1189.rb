# Reads two integers and prints their sum
$L = 20
$facts = Array.new($L){|x|x}
$facts[0] = 1
(1...$L).each {|x| $facts[x]*=$facts[x-1]}

def solve(n)
  i = $L-1
  facts = []
  while i>=0 and n>0 do 
    if $facts[i]<=n then 
      n -= $facts[i]
      facts << i
    end
    i -= 1
  end
  return nil if n!=0
  return facts
end


def main
  gets.to_i.times do |i|
    n = gets.to_i
    s = solve(n)
    print("Case #{i+1}: ")
    if s then 
      puts(s.map{|x|x.to_s+"!"}.join("+")) 
    else 
      puts("impossible") 
    end
  end
end

main