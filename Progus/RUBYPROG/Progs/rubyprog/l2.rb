def timesRepeat(aNum)
	for i in 1..aNum do
		yield(i)
	end
end
def timesRepeat2(aNum, anArray)
	for i in (0...aNum) do
		yield(anArray[i])
	end
end

timesRepeat(3){|a| puts(a)}
timesRepeat2(3,[1,2,3]){|k|puts(k)}
gets
	