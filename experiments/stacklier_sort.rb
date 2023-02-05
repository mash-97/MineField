
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
  puts("sorted_array: #{ss.first.to_s}, steps: #{ss.last}")
end
