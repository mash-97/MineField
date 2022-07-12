class ID
	def initialize(sNo, name, birthday, department, roll)
		@name=name
		@bd=birthday
		@dpt=department
		@roll=roll
		@s=sNo
		@j=0
	end
	def create(confirmationcode)
		@con=confirmationcode
		i=898
		if @con == i then
			f=File.new("#{@s}.txt", "w")
			f.puts("Name:			#{@name}\n")
			f.puts("Birthday:		#{@bd}\n")
			f.puts("Department:		#{@dpt}\n")
			f.puts("Roll:			#{@roll}\n")
			f.close
			@j=1
		else 
			puts("Code doesn't match, Try again")
		end
	end
	def display
		if @j==1 then
			
			
			IO.foreach("#{@s}.txt") {|line| print(line)}
		else
			puts("Sorry! You haven't created this ID")
		end
	end
end
	puts "Your Student ID : "
	sNo=gets.to_i
	puts "Your Name : "
	name=gets
	puts "Your Birthday (monthname/date/year) : "
	birthday=gets
	puts "Department: "
	department=gets
	puts "Roll NO: "
	roll=gets.to_i
	n=ID.new( sNo, name, birthday, department, roll)
	n.create(898)
	n.display	
	