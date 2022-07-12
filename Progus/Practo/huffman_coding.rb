#! /usr/bin/ruby
puts("Loading: mashz")
require 'mashz'
puts()

# Huffman Coding for a given string
class BNode
	attr_accessor :value, :label
	attr_accessor :left, :right, :parent
	
	def initialize(value=nil, label = nil, left=nil, right=nil, parent=nil)
		@value = value
		@label = label
		@left = left
		@right = right
		@parent = parent
	end
	
	def +(node)
		if self.parent!=nil or node.parent!=nil then
			puts("False: Parent Exists")
			return nil
		end
		
		result_node = BNode.new(value=(self.value+node.value), label = "*", left=self, right=node)
		self.parent = result_node
		node.parent = result_node
		
		return result_node
	end
	
	def BNode.add(node_1, node_2)
		return node_1 + node_2
	end
		
end
	
class HuffmanCode
	attr_accessor :tree, :string, :encoded_s
	attr_accessor :ucc_hash
	
	def initialize(string)
		@string = string.clone()
		@ucc_hash = string.split("").uniq().collect{|x| [x, string.count(x)]}.to_h()
		@nodes = @ucc_hash.collect{|x| BNode.new(value = x[1], label = x[0])}.sort{|x, y| 
			if x.value == y.value then
				x.label <=> y.label
			else
				x.value <=> y.value
			end
		}
		@tree = @nodes.inject{|x,y| y+x}
		self.extractCodes()
		self.produceHuffmanCode()
	end
	
	protected
		def extractCodes()
			@ucc_hash.each do |key, value|
				code = HuffmanCode.extractCode(@tree, key)
				code = code.map(&:to_s).join('') if code!=nil
				@ucc_hash[key] = {:value => value, :code => code}
			end
		end
		
		def produceHuffmanCode()
			@encoded_s = ""
			@string.split('').each do |character|
				@encoded_s += @ucc_hash[character][:code]
			end
			return @encoded_s
		end
		
	def self.extractCode(node, character, temp=[])
		return nil if node==nil 
		if node.label == character then
			return temp.clone()
		end
		
		temp.push(0)
		result = self.extractCode(node.left, character, temp)
		temp.pop()
		return result if result != nil and result.length != 0
		
		temp.push(1)
		result = self.extractCode(node.right, character, temp)
		temp.pop()
		
		return result
	end
		
	def self.travelHuffmanTree(node, mode=:pre_order)
		return if node==nil
		puts(print([node.label, node.value])) if mode == :pre_order
		
		HuffmanCode.travelHuffmanTree(node.left, mode) if node.left!=nil
		puts(print([node.label, node.value])) if mode == :in_order
		
		HuffmanCode.travelHuffmanTree(node.right, mode) if node.right!=nil
		puts(print([node.label, node.value])) if mode == :post_order
	end
end

def huff(string)
	huffman = HuffmanCode.new(string)
	huffman.ucc_hash.each{|k,v| puts("#{k}: #{v.to_s}")}
	puts("\n#{huffman.string}: #{huffman.encoded_s}")
	puts()
	command = ""
	until (print("\t--> ")==nil) and (command=gets) == nil do
		begin
			puts eval(command.chomp)
		rescue => exception
			puts("Exception: #{exception}")
		end
	end
	puts()	
end


# main program starts here...
string = ""
until (print("\n==> ") ==nil) and (string = gets) == nil do
	begin
		string.chomp!
		huff(string)
	rescue => exception
		puts("Exception: #{exception}")
	end
end

