
class Exp 
  def initialize(str)
    @h = {}
    @h[:lo], @h[:ro], @h[:r] = str.strip.split(/[\s=]/).map(&:to_i)
  end
  def [](sym)
    return @h[sym]
  end
end

while true do
  t = gets
  break if not t
  t = t.to_i
  exps = t.times.collect do 
    exp = Exp.new(gets)
    Proc.new {
      |op|
      if op=='I' then
        !(["*", "+", "-"].any?{|o| eval("#{exp[:lo]} #{o} #{exp[:ro]}")==exp[:r]})
      else
        eval("#{exp[:lo]} #{op} #{exp[:ro]}")==exp[:r]
      end
    }
  end
  anss = t.times.collect do
    ans = gets.split(" ")
    exps[ans[1].to_i-1].call(ans.last) || ans.first
  end
  anss.reject!{|x|x==true}
  anss.sort!
  
  if anss.length==t then
    puts("None Shall Pass!")
  elsif anss.length==0 then
    puts("You Shall All Pass!")
  else
    puts(anss.join(" "))
  end
end

    
  