def range_compare(range, value)
  return 0 if range.include?(value)
  range.first <=> value
end

def lin_search(array, x)
  i = 0
  while i<array.size do
    return i if array[i]>=x
    i += 1
  end
  return array.size-1
end

gets.to_i.times do
  n, k, q = gets.strip.split(' ').map(&:to_i)
  a = gets.strip.split(' ').map(&:to_i)
  b = gets.strip.split(' ').map(&:to_i)
  a.unshift(0)
  b.unshift(0)
  results = []
  q.times do
    d = gets.to_i
    i = a.bsearch_index{|e| e>=d}
    # i = lin_search(a, d)
    # puts("d: #{d}, i: #{i}")
    if a[i]==d then
      results << b[i]
    else
      li = i-1
      ri = i
      #cv = (b[ri]-b[li]).to_f/(a[ri]-a[li]).to_f
      # puts("cv: #{cv}")
      #t = b[li]+(d-a[li])*cv
      t = b[li] + (d-a[li])*(b[ri]-b[li])/(a[ri]-a[li])
      results << t.floor
    end
  end
  puts(results.map(&:to_s).join(' '))
end