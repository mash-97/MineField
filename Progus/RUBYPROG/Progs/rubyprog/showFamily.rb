#####showFamilyOfAClass######
def showFamily(aClass)
	if(aClass != nil && aClass.superclass != nil)
		print("#{aClass} - ")
		showFamily(aClass.superclass)
	else
		puts aClass
	end
end

class A
end
class B < A
end
showFamily(B)
gets