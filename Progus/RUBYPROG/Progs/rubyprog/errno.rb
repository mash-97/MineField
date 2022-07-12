for err in Errno.constants do
	errnum = eval("Errno::#{err}::Errno")
	puts("#{err} -- #{errnum}")
end
gets