
class Node
  attr_accessor :id, :color, :parent, :childs
  attr_accessor :whites, :blacks
  attr_accessor :first_sum
  def initialize(id, color, parent=nil, childs=[])
    @id = id
    @color = color
    @parent = parent
    @childs = childs
    @whites = 0
    @blacks = 0
    if color == 'W' then
      @whites += 1
    else
      @blacks += 1
    end
    @first_sum = false
  end
end


def __dfs__(curr_node)
  if curr_node==nil then
    return [0, 0]
  end
  whites = 0
  blacks = 0
  curr_node.childs.each do |chld_nd|
    wbr = __dfs__(chld_nd)
    if (wbr.first!=0 and wbr.last!=0) and (wbr.first==wbr.last) then
      $BSC += 1
    end
    whites += wbr.first
    blacks += wbr.last
  end
  if curr_node.color == 'W' 
    whites += 1 
  else
    blacks += 1
  end

  return [whites, blacks]
end

def __dfs__stack(curr_node)
  stack = [curr_node]
  stack_serial = [curr_node]
  tw = 0
  tb = 0
  cn = stack.last
  while not stack.empty? do 
    cn = stack.pop()
    cn.childs.each do |node|
      stack << node 
      stack_serial << node
    end
  end
  # puts(stack_serial.collect{|x|x.id}.map(&:to_s).join(' '))

  while not stack_serial.empty? do 
    curr_node = stack_serial.pop()
    if curr_node.color == 'W' then
      tw += 1
    else
      tb += 1
    end
    if (tw!=0 and tb!=0) and (tw==tb) then
      $BSC += 1
    end
  end
  return [tw, tb]
end


def dfs_color_parity_check(root)
  $BSC = 0 # balanced subtree count
  twb = __dfs__stack(root)
  return $BSC
end

def except_dfs(nodes)
  def go_up(node)
    cn = node
    cn.first_sum = true
    sumw = node.whites
    sumb = node.blacks
    cn = cn.parent
    while cn!=nil do 
      tw = cn.whites
      tb = cn.blacks
      
      cn.whites += sumw
      cn.blacks += sumb
      if not cn.first_sum 
        sumw = cn.whites
        sumb = cn.blacks
        cn.first_sum = true
      end

      cn = cn.parent
    end
  end
  $BSC = 0
  nodes.each do 
    |node|
    if node.childs.empty? then
      go_up(node)
    end
  end
  nodes.each do 
    |node|
    # puts("node: #{node.id}, whites: #{node.whites}, blacks: #{node.blacks}")
    if (node.whites!=0 and node.blacks!=0) and node.whites==node.blacks then
      $BSC += 1
    end
  end
  return $BSC
end


def main()
  gets.to_i.times do 
    n = gets.to_i
    a = gets.strip.split(' ').map(&:to_i)
    colors = gets.strip
    
    nodes = n.times.collect do |i|
      Node.new(i+1, colors[i])
    end
    nodes.first.parent = nil
    a.each_with_index do |p, i|
      child = nodes[i+1]
      parent = nodes[p-1]
      parent.childs << child
      child.parent = parent
    end

    # blc_subtrees = dfs_color_parity_check(nodes.first)
    puts(except_dfs(nodes))
  end
end

if $0 == __FILE__ then
  main()
end


