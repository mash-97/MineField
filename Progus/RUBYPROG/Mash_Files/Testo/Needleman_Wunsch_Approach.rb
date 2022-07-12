# Pairwise Global Allignment

class Cell
	attr_accessor :r_index, :c_index
	attr_accessor :value
	attr_accessor :l_cell, :u_cell, :a_cell
	attr_accessor :u_c, :l_c
	
	def initialize(row_index, column_index, upper_char, left_char)
		@r_index = row_index
		@c_index = column_index
		@u_c = upper_char
		@l_c = left_char
		@value = nil
		@l_cell = nil
		@u_cell = nil
		@a_cell = nil
	end
end

$temp = []

def opsFromTable(table, i, j, solution = [])
	cell = table[i][j]
	temp = solution
	
	#print([cell.r_index, cell.c_index])
	#~ puts()
	if cell.l_cell==nil and cell.u_cell==nil and cell.a_cell==nil then
		$temp << temp
		#~ puts("Return temp: #{temp}")
		return
	end
	
	if cell.l_cell != nil then
		opsFromTable(table, i, j-1, temp+[[cell.u_c, nil]])
	end
	
	if cell.u_cell != nil then
		opsFromTable(table, i-1, j, temp+[[nil, cell.l_c]])
	end
	
	if cell.a_cell != nil then
		opsFromTable(table, i-1, j-1, temp+[[cell.u_c, cell.l_c]])
	end
end


def opsOfPGAllignment(sequence_1, sequence_2, match_value, miss_match_value, gap_value)
	#puts("seq1: #{sequence_1}, seq2: #{sequence_2}, match: #{match_value}, mm: #{miss_match_value}, gap: #{gap_value}")
	sequence_1 = ("-"+sequence_1).split('').map(&:upcase)
	sequence_2 = ("-"+sequence_2).split('').map(&:upcase)
	
	optimal_solutions = []
	c_no = sequence_1.length
	r_no = sequence_2.length
	
	table = r_no.times.collect do	|i|
				c_no.times.collect do |j|
					Cell.new(i, j, sequence_1[j], sequence_2[i])
				end
			end
	puts()
	
	# first rows
	i = 0
	while(i<c_no) do
		table[0][i].value = i*gap_value
		table[0][i].l_cell = table[0][i-1] if i!=0
		i+=1
	end
	
	# first columns
	i = 0
	while(i<r_no) do
		table[i][0].value = i*gap_value
		table[i][0].u_cell = table[i-1][0] if i!=0
		i+=1
	end
	
	
	for x in (1...r_no) do
		for z in (1...c_no) do
			
			#puts("------------x: #{x} and z: #{z}")
			cell = table[x][z]
			#puts("cell.u_c: #{cell.u_c}, cell.l_c: #{cell.l_c}")
			
			values = [ table[x-1][z-1].value+(sequence_2[x]==sequence_1[z] ? match_value : miss_match_value), 
				table[x-1][z].value+gap_value, table[x][z-1].value+gap_value]
			table[x][z].value = values.max
			#print(values)
			#puts
			#puts
			table[x][z].a_cell = table[x-1][z-1] if table[x][z].value == values[0]
			table[x][z].u_cell = table[x-1][z] if table[x][z].value == values[1]
			table[x][z].l_cell = table[x][z-1] if table[x][z].value == values[2]
		end
	end
	
	puts("last value: #{table[-1][-1].value}")
	puts("Value table: ")
	table.each{|row|
		row.each{|column| print("%5d\t"%(column.value))}
		puts()
	}
	puts()
	$temp = []
	opsFromTable(table, r_no-1, c_no-1, [])
	result = $temp
	$temp = []
	return result
end


#~ print("Sequence 1: ")
#~ seq1 = gets.chomp
#~ print("Sequence 2: ")
#~ seq2 = gets.chomp
#~ print("Match Value: ")
#~ match = gets.chomp.to_i
#~ print("Miss Match Value: ")
#~ miss_match = gets.chomp.to_i
#~ print("Gap Value: ")
#~ gap = gets.chomp.to_i
10.times do
	s1, s2, m, mm, g = gets.chomp.split(' ')

	result = opsOfPGAllignment(s1, s2, m.to_i, mm.to_i, g.to_i)

	puts
	puts("Total optimal solutions: #{result.length}")
	count = 1
	result.each{|r| 
		puts("#{count}: \n")
		count+=1
		f = []
		s = []
		r.each{|a| 
			f<<a[0]
			s<<a[1]
		}
		
		print("\t")
		f.reverse!
		s.reverse!
		f.each{|x|
			if x==nil then print("_") else print(x) end
		}
		puts
		print("\t")
		s.each{|x|
			if x==nil then print("_") else print(x) end
		}
		puts
		puts
			
	}
	puts
end
	
	
# ttccatg tcat 2 -2 -3
