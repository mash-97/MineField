def apply_changes(array, darray, carray)
  ch_array = array.dup
  cd = carray.zip(darray)
  cd.each do |pair|
    ch_array[pair.first] = pair.last
  end
  return ch_array
end

def test_brute(cm, n, m)
  if cm.size == m then
    puts(cm.to_s)
    return nil 
  end

  (0..n).each do |i|
    cm.push(i)
    test_brute(cm, n, m)
    cm.pop()
  end
  return nil
end

def brute_ops(carray, n, m, array, barray, darray, solutions=[])
  if(carray.size==m) then
    # puts(carray.to_s)
    chng_array = apply_changes(array, darray, carray)
    if chng_array == barray then
      solutions << carray.zip(darray)
      return true
    end
    return false
  end

  (0...n).each do |cindx|
    carray.push(cindx)
    brute_ops(carray, n, m, array, barray, darray, solutions)
    carray.pop()
  end
  return nil
end

def main_cpp
  ans = []
  gets.to_i.times do |i|
    n = gets.to_i
    array = gets.strip.split(' ').map(&:to_i)
    barray = gets.strip.split(' ').map(&:to_i)
    m = gets.to_i
    darray = gets.strip.split(' ').map(&:to_i)

    puts("test case: #{i+1}")
    solutions = []
    r = brute_ops([], n, m, array, barray, darray, solutions)
    puts("#{r} => there are #{solutions.size} solutions!")
    solutions[..3].each do |sol|
      puts(sol.to_s)
    end

    puts()
    puts()
    ans << (solutions.size == 0 ? "NO" : "YES")
  end
  puts(ans)
end

def test()
  gets.to_i.times do 
    n, m = gets.strip.split(' ').map(&:to_i)
    test_brute([], n, m)
  end
end

if $0 == __FILE__ then
  main_cpp()
end
