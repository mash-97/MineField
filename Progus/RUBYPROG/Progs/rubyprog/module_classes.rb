def showFamily(aClass)
	if(aClass.superclass != nil) then
		print(aClass.to_s + " - ")
		showFamily(aClass.superclass)
	else puts(aClass) end
end

puts("Class hierarchy of class...")
showFamily(Class)

class X < Module
end
puts("Class hierarchy of X...")
showFamily(X)

gets