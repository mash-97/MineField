def isTheWordPalindrome(aWord)
	if(aWord.length % 2 == 0)
		j = aWord.length - 1
		
		for i in (0..aWord.length/2)
			if(aWord[i]!=aWord[j])
				return false
			end
			j -= 1
		end
		return true
	else
		middle = (aWord.length/2).to_i
		j = aWord.length - 1
		for i in (0...middle)
			if(aWord[i] != aWord[j])
				return false
			end
			j -= 1
		end
		return true
	end
end
k=0
a = []
until a[k-1].to_i == -1
	print("Enter your word: ")
	a[k] = gets
	if(isTheWordPalindrome(a[k].chomp!) == true)
		puts("#{a[k]} is palindrome.")
	else
		puts("#{a[k]} is not palindrome.")
	end
	k += 1
end

gets