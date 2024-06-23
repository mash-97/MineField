class HeapArray
  attr_accessor :heap_size, :type
  def initialize(heap_size, type=:min, *args)
    @heap_size = heap_size
    @array = Array.new(@heap_size)
    args.each_with_index{|v,i| @array[i]=v}
    @type = type
  end

  def check_heap(type: @type, **kwargs)
    type = kwargs[:type]
    type_lambda = ->(x, y) {x<=>y}
    if type==:max then
      type_lambda = ->(x,y) {y<=>x}
    end

    for indx in (@heap_size-1..0).to_a.reverse do
      if type_lambda.call(@array[parent(indx)], @array[indx]) < 0 then
        return false
      end
    end

    return true
  end

  private
  def parent(indx)
    indx/2
  end

  def left_child(indx)
    indx*2+1
  end

  def right_child(indx)
    indx*2+2
  end
  
end

