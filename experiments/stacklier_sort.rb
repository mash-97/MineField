def insertion_sort(array)
  step = 0
  for i in (1...array.length)
    j = i-1
    while(j>=0 and array[j+1] < array[j]) do
      buff = array[j+1]
      array[j+1] = array[j]
      array[j] = buff
      j -= 1
      step += 1
    end
  end
  return array, step
end


def stacklier_sort(array)
  buffer_stack = Array.new
  sorted_stack = Array.new
  
  sorted_stack << array[0]
  steps = 0
  array[1..].each do |element|
    while sorted_stack.last != nil and sorted_stack.last > element do
      buffer_stack << sorted_stack.pop()
      steps += 1
    end
     
    sorted_stack << element
    
    while buffer_stack.last != nil do
      sorted_stack << buffer_stack.pop()
      steps += 1
    end
  end
  return sorted_stack, steps
end


if $0 == __FILE__ then
  print("enter array: ")
  array = gets.strip.split(' ').map(&:to_i)
  ss = stacklier_sort(array)
  puts("stacklier_sort: #{ss.first.to_s}, steps: #{ss.last}")
  is = insertion_sort(array)
  puts("insertion_sort: #{is.first.to_s}, steps: #{is.last}")
  puts("array: #{array.to_s}")
end
