
# do an n-sum-of-product on array 
# containing values
def waterfall_sop(arr)
  result = 0
  indx = 0
  while indx < arr.size do
    xindx = indx+1
    while xindx < arr.size do
      result += arr[indx]*arr[xindx]
      xindx += 1
    end
    indx += 1
  end
  return result
end

# get elements that start with letter l
def cruz_fl(l, arr)
  return arr.select{|x| x[0]==l}.collect{|x|x[1]}
end

# get a hash containing letter counts
def cruz_bh(arr)
  h = ('a'..'k').to_a.zip(Array.new(11){0}).to_h
  arr.each{|x|h[x]+=1}
  return h
end

# get an array containing frequencies in each hash
# for letter l
def cruz_l(l, hashes)
  larr = []
  hashes.each do |h|
    larr << h[l]
  end
  return larr
end

def main()
  gets.to_i.times do 
    n = gets.to_i
    ss = []
    n.times do 
      ss << gets.strip
    end

    l_hash = ('a'..'k').to_a.zip(Array.new(11){nil}).to_h

    result = 0
    for key in l_hash.keys() do
      l_hash[key] = cruz_bh(cruz_fl(key, ss))
      result += waterfall_sop(l_hash[key].values())
    end

    ('a'..'k').each do |l|
      result += waterfall_sop(cruz_l(l, l_hash.values()))
    end
    puts(result)
  end
end

main()

