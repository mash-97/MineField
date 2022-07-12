
def maxIndexOfTable(table)
	indexes = {}
	max_value = -(1/0.0)
	r = 0
	table.each do |row|
		c = 0
		row.each do |data|
			if data.to_f >= max_value then 
				max_value = data
				indexes[data] = [] if indexes[data] == nil
				indexes[data]<<[r, c]
			end
			c+=1
		end
		r+=1
	end
	
	return indexes[max_value]
end


a = [[1,2,3], [3,3,4,52, 55, 55], [55, 5, 55]]

print(maxIndexOfTable(a))
