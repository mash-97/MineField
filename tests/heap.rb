
class Heap
  class << self
    def check_max_heap(array)
      array[2..].each_with_index.all?{|*e| array[parent(e.last+2)]>=e.first}
    end

    def parent(indx)
      return indx/2
    end
    def left_child(indx)
      return indx*2
    end
    def right_child(indx)
      return left_child(indx)+1
    end

    def max_heapify(cindx, array)
      lc_indx = left_child(cindx)
      rc_indx = right_child(cindx)
      lindx = cindx

      if lc_indx<array.length-1 and array[lc_indx] > array[lindx] then
        lindx = lc_indx
      end
      if rc_indx<array.length-1 and array[rc_indx] > array[lindx] then
        lindx = rc_indx
      end

      if lindx != cindx then
        temp = array[cindx]
        array[cindx] = array[lindx]
        array[lindx] = temp
        max_heapify(lindx, array)
      end
    end

    def build_heap!(array)
      (1...array.length).to_a.reverse.each{|indx| max_heapify(indx, array)}
      return array
    end

    def pop!(array)
      r = array[1]
      p = array.pop()
      array[1] = p
      build_heap!(array)
      return r 
    end

    def pop_exec(array)
      ta = array.dup
      s = ta.length-1
      sa = []
      s.times do
        sa << pop!(ta)
      end
      return sa
    end

    def push(val, array)
      array << val
      ci = array.size-1
      pi = parent(ci)
      while pi>0 and array[pi] < array[ci] do
        temp = array[pi]
        array[pi] = array[ci]
        array[ci] = temp
        ci = pi
        pi = parent(ci)
      end
      return ci 
    end
  end
end


if $0 == __FILE__ then
  gets.to_i.times do
    array = gets.strip.split(' ').map(&:to_i)
    puts("given array: #{array.to_s}, size: #{array.length}")
    array.unshift(0)
    if Heap.check_max_heap(array) then
      puts("the array is already a max heap!")
    else
      puts("the array is not a max heap!")
      puts("Heaped array is: #{Heap.build_heap!(array).to_s}")
      puts("checked: #{Heap.check_max_heap(array)}")
      pe = Heap.pop_exec(array)
      puts("pop_exec: #{pe}, size: #{pe.size}")
    end
    puts()

    puts("1 for push like (1 5)")
    puts("2 for pop exec like (2)")
    while true do
      print("query> ")
      i = $stdin.gets.strip.split(' ').map(&:to_i)
      case i.size
      when 1
        puts("checked: #{Heap.check_max_heap(array)}")
        pe = Heap.pop_exec(array)
        puts("pop_exec: #{pe}, size: #{pe.size}")
      when 2
        Heap.push(i.last, array)
        puts("array: #{array.to_s}")
      else
        break
      end
    end
  end
end