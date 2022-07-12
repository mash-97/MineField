FRAUD=21
Ok=12
YES=1
NO=0
def checkExistencyOfJustLettersIn(aString)
	aString.split(//).each do |l|
		if not((l>='A' && l<='Z') and (l>='a' && l<='z')) then return(FRAUD) end
	end
	return(Ok)
end

def totalLowerCaseLettersOf(aString)
	l = 0
	aString.split(//).each{|l| 
		if(l>='a' && l<='z') then l+=1 end
	}
	return(l)
end

def totalUpperCaseLettersOf(aString)
	u = 0
	aString.split(//).each{|l|
		if(l >= 'A' && l<='Z') then u+=1 end
	}
	return(u)
end

def checkChefFor(aString, k, u)
	if(u <= k) then return(YES) 
	else return(NO) end
end

def checkBrotherFor(aString, k, l)
	if(l <= k) then return(YES)
	else return(NO) end
end
s = ""
t = gets.to_i
while(t>=1 and t<=1000) do
	N=gets.to_i
	k=gets.to_i
	s=gets.chomp
	if(s.length == N && checkExistencyOfJustLettersIn(s)==Ok && k<=N && k>=0 && N>=1 && N<=100) then 
		u = totalUpperCaseLettersOf(s)
		l = totalLowerCaseLettersOf(s)
		if(checkBrotherFor(s,k,l)==YES)then puts("brother")
		elsif(checkChefFor(s,k,u)==YES)then puts("chef")
		elsif(checkBrotherFor(s,k,l) == YES && checkChefFor(s,k,u) == YES)then puts("both")
		else puts("none") end
	end
	t-=1
end
			

	
	