class BinaryTree
  class Node
    attr_accessor :value, :left_child, :right_child
    def initialize(value, left_child=nil, right_child=nil)
      @value = value
      @left_child = left_child
      @right_child = right_child
    end
  end

  attr_accessor :root, :size
  def initialize()
    @root = nil
    @size = 0
  end

  
  def insert(value)
    new_node = Node.new(value)
    @size += 1
    current_node = @root
    if current_node==nil then
      @root = new_node
      return new_node
    end

    while current_node != nil do
      if new_node.value <= current_node.value then
        if current_node.left_child != nil then
          current_node = current_node.left_child
        else
          current_node.left_child = new_node
          break
        end
      else
        if current_node.right_child != nil then
          current_node = current_node.right_child
        else
          current_node.right_child = new_node
          break
        end
      end
    end

    return new_node
  end

  def display(node=@root, order=:in)
    display(node.left_child, order) if node.left_child
    print("#{node.value} ")
    display(node.right_child, order) if node.right_child
  end
end


if $0==__FILE__ then
  bt = BinaryTree.new
  11.times.collect{rand -11..11}.each{|e|bt.insert(e)}
  bt.display()
end

