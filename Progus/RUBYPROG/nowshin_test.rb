#~ #! /usr/bin/ruby

#~ total_correct_ans = 0
#~ total_quest = 10.times do 
	#~ |x|
	#~ a = rand(0..1000)
	#~ b = rand(0..1000)
	
	#~ c = ['/', '*', '-', '+'][rand(0..3 )]
	
	#~ b,a = [a,b].minmax if c== '-' || c=='/'
	#~ b = b.to_s.split('')[0] if c=="*"
	#~ a = a-(a%b) if c=='/'
	
	
	#~ equation = "#{a} #{c} #{b}"
	#~ puts("#{x}: #{equation}")
	
	#~ begin
		#~ correct_ans = eval(equation).to_s
	#~ rescue
		#~ correct_ans = "vool"
	#~ end
	
	#~ loop do
		#~ print("--> ")
		#~ get_ans = gets
		#~ if not get_ans == nil then
			#~ get_ans.chomp!
			#~ break if get_ans == "next" || get_ans == "step"
			#~ exit if get_ans == "end"
			
			#~ if get_ans == correct_ans then puts("Correct!") else puts("Incorrect!") end
		#~ end
		#~ puts()
	#~ end
	#~ puts("-----------------------------------------------------")
#~ end


class Node
	attr_accessor :value, :left_node, :right_node
	def initialize(value, left_node=nil, right_node=nil)
		@value = value
		@left_node = left_node
		@right_node = right_node
	end
	

	def self.create_node(value, left_node=nil, right_node=nil)
		Node.new(value, left_node, right_node)
	end
end

		

class BinaryIndexedTree
	
	def initialize(root_node=nil)
		root_node = Node.new(root_node) if root_node != nil and root_node.class != Node
		@root_node = root_node
	end
	
	def addNode(node)
		return false if node==nil
		node = Node.new(node) if not node.class == Node
		@root_node = insert_node(@root_node, node)
		return true
	end
	
	def searchNode(value)
		@step_count = 0
		result = search_node(value, @root_node)
		result = [result, @step_count]
		@step_count = 0
		return result
	end
	
	def displayTree(mode=:pre_order, node=@root_node)
		return if node==nil
		
		puts(print([node.value])) if mode == :pre_order
		
		self.displayTree(mode, node.left_node) if node.left_node!=nil
		
		puts(print([node.value])) if mode == :in_order
		
		self.displayTree(mode, node.right_node) if node.right_node!=nil
		
		puts(print([node.value])) if mode == :post_order
	end
	
	def disp()
		puts(@value)
	end
	
	private
		def insert_node(parent, node)
			return @root_node = node if @root_node == nil
			return @root_node if node == nil
			raise("inside insert_node(): parent argument is nil") if parent == nil
			
			if parent.value >= node.value then	
				if parent.left_node == nil then
					parent.left_node = node
					return @root_node
				else
					return insert_node(parent.left_node, node)
				end
			else
				if parent.right_node == nil then
					parent.right_node = node
					return @root_node
				else
					return insert_node(parent.right_node, node)
				end
			end
		end
		
		def search_node(value=nil, parent)
			@step_count += 1
			return false if value == nil or parent == nil
			return parent if parent.value == value
			
			if parent.value >= value then
				return false if parent.left_node == nil
				return search_node(value, parent.left_node)
			end
			
			return false if parent.right_node == nil
			return search_node(value, parent.right_node)
		end
					
end



bt = BinaryIndexedTree.new(nil)
a = [5, 6, 6, 14, 9, 8, 12, 12, 33, 30, 17, 15]
#~ 10.times do a << (c=rand(1..33)); bt.add_node(c) end
puts(a.to_s)
puts("-----")
a.each{|e|bt.addNode(e)}
bt.displayTree(:in_order)
puts("-----")
number = 17
puts("Searching for #{number}: #{bt.searchNode(number)}")

	
