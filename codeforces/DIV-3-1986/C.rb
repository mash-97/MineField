
def puniq(array, lim=10**5)
  a = Array.new(lim+1){0}
  array.each{|x|a[x]+=1}
  return a.each_with_index.select{|v, i| v>0}.collect{|v,i| i}
  # array = array.sort
  # ua = [array.first]
  
  # indx = 1
  # while indx<array.size do 
  #   if ua.last!=array[indx] then
  #     ua << array[indx]
  #   end
  #   indx += 1
  # end
  # return ua
end

def cuniq(chars)
  s = [0]*26
  chars.each{|c| s[(c.ord-'a'.ord)]+=1}
  str = []
  (0...26).each do 
    |indx|
    if s[indx]>0 then
      s[indx].times{str << (('a'.ord+indx).chr)}
    end
  end
  return str
end


gets.to_i.times do 
  n, m = gets.strip.split(' ').map(&:to_i)
  s = gets.strip
  inds = gets.strip.split(' ').map(&:to_i)
  inds = puniq(inds, n)
  c = cuniq(gets.strip.chars)
  inds.each_with_index do |vindx, aindx|
    s[vindx-1] = c[aindx]
  end
  puts(s)
end
