# Pairwise Global Allignment

class Cell
	attr_accessor :r_index, :c_index
	attr_accessor :value, :temp_value
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

def maxIndexOfTable(table)
	indexes = {}
	max_value = -(1/0.0)
	r = 0
	table.each do |row|
		c = 0
		row.each do |data|
			if data.value.to_f >= max_value then 
				max_value = data.value
				if indexes[data.value] == nil then indexes[data.value] = [[r, c]]  else indexes[data.value]<<[r, c] end
			end
			c+=1
		end
		r+=1
	end
	
	return indexes[max_value]
end
		
			
		
def opsFromTable(table, i, j, solution = [])
	cell = table[i][j]
	temp = solution
	
	if cell.value == 0 or (cell.l_cell==nil and cell.u_cell==nil and cell.a_cell==nil) then
		$temp = temp
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
		table[0][i].value = 0
		table[0][i].l_cell = table[0][i-1] if i!=0
		i+=1
	end
	
	# first columns
	i = 0
	while(i<r_no) do
		table[i][0].value = 0
		table[i][0].u_cell = table[i-1][0] if i!=0
		i+=1
	end
	
	
	for x in (1...r_no) do
		for z in (1...c_no) do
			
			cell = table[x][z]
			
			values = [ table[x-1][z-1].value+(sequence_2[x]==sequence_1[z] ? match_value : miss_match_value), 
				table[x-1][z].value+gap_value, table[x][z-1].value+gap_value]
			
			table[x][z].temp_value = values.max
			table[x][z].value = values.max < 0 ? 0 : values.max
			
			table[x][z].a_cell = table[x-1][z-1] if table[x][z].temp_value == values[0]
			table[x][z].u_cell = table[x-1][z]   if table[x][z].temp_value == values[1]
			table[x][z].l_cell = table[x][z-1]   if table[x][z].temp_value == values[2]
		end
	end
	
	puts("last value: #{table[-1][-1].value}")
	puts("Value table: ")
	table.each{|row|
		row.each{|column| print("%5d\t"%(column.value))}
		puts()
	}
	puts()
	result = []
	
	maxIndexOfTable(table).each{|r|
		$temp = []
		opsFromTable(table, r[0], r[1], [])
		result << $temp
		$temp = []
	}
	print(result)
	return result
end


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

