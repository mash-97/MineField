aString = "Quantum Mechanics is a microscopic physics"
caString = %W(#{aString})
print("#{aString}\n")

print("#{caString}\n")
print("#{caString}\n")
for i in caString
	puts(i)
end
gets

for word in ["Theory of Relativity generally a macroscopic physics"]
	print(word)
end
gets