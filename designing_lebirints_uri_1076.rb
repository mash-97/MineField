class Node
	attr_reader :value
	attr_reader :adj_nodes
	
	def initialize(value, *nodes)
		@value = value
		@adj_nodes = ([]+nodes).flatten
	end
	
	def add_adj_node(adj_node)
		@adj_nodes << adj_node
	end
	
	def adj_node_with_value(value)
		@adj_nodes.each do |adj_node|
			return adj_node if adj_node.value == value
		end
		return false
	end
end



class Graph
	attr_reader :nodes
	
	def initialize(*nodes)
		@nodes = ([]+nodes).flatten
	end
	
	
	def node_with_value(value)
		@nodes.each do |node|
			return node if node.value==value
		end
		return nil
	end
	
	def add_edge_between_nodes(value_1, value_2)
		node_1 = self.node_with_value(value_1)
		node_2 = self.node_with_value(value_2)
		raise "NodeNotExisted" if not node_1 or not node_2
		node_1.add_adj_node(node_2) if not node_1.adj_nodes.include?(node_2)
		node_2.add_adj_node(node_1) if not node_2.adj_nodes.include?(node_1)
	end
	
	def show_graph()
		@nodes.each do |node|
			puts("node.value: #{node.value} :: node.adj_nodes: #{node.adj_nodes.map(&:value).to_s}")
		end
	end
	
	
	alias :exist? :node_with_value
end


class MazeGraph < Graph
	
	def minimum_steps_dfs(start_value)
		#~ puts("The graph looks like: ")
		#~ self.show_graph()
		
		steps = 0
		stack  = []
		visited = []
		
		stack.push(node_with_value(start_value))
		
		while not stack.empty? do 			
			#~ puts("stack: #{stack.collect{|x|x.value}.to_s}")
			#~ puts("visited: #{visited.collect{|x|x.value}.to_s}")
			current_node = stack.pop()
			#~ puts("\n--> current_node: #{current_node} :: value: #{current_node.value}")
			
			steps += 1
			
			current_node.adj_nodes.each do |adj_node|
				next if visited.include?(adj_node)
				stack.push(adj_node) 
			end
			visited << current_node
		end
		return steps
	end
	
	
	def minimum_steps_bfs(start_value)
		#~ puts("The graph looks like: ")
		#~ self.show_graph()
		
		steps = 0
		queue  = []
		visited = []
		
		queue.push(node_with_value(start_value))
		
		while not queue.empty? do 			
			#~ puts("queue: #{queue.collect{|x|x.value}.to_s}")
			#~ puts("visited: #{visited.collect{|x|x.value}.to_s}")
			current_node = queue.shift()
			#~ puts("\n--> current_node: #{current_node} :: value: #{current_node.value}")
			
			steps += 1
			
			current_node.adj_nodes.each do |adj_node|
				next if visited.include?(adj_node)
				queue.push(adj_node) 
			end
			visited << current_node
		end
		return steps
	end
	
end



if __FILE__== $0
	t = gets.to_i
	t.times do 
		n = gets.to_i
		v,a = gets.split(" ").map(&:to_i)
		
		maze = MazeGraph.new(v.times.collect{|x|Node.new(x)})
		a.times do 
			|x|
			v1, v2 = gets.split(" ").map(&:to_i)
			maze.add_edge_between_nodes(v1, v2)
		end
		puts((maze.minimum_steps_bfs(n)-1)*2)
	end
			
end


