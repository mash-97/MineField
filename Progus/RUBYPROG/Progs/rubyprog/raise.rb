###### raise . rb ########
def handleError(e)
	puts("Type of error: #{e.class}:: #{e}")
	backtrace = e.backtrace()
	puts("Here is the backtrace: ")
	puts backtrace
end

def divByZero
	1/0
end

begin
	divByZero
rescue Exception => e
	puts("An error is occurred. Please wait...")
	begin
		raise
	rescue 
		handleError(e)
	end
end

gets