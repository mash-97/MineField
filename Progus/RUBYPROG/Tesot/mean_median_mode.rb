wkts_list = [6,5,6,4,3,1,3,2,1]
wkts_freq = {}

for item in wkts_list
	if wkts_freq.include?(item)
		wkts_freq[item] += 1
	else
		wkts_freq[item] = 1
	end
end

for item in wkts_freq
	puts("Wicket: "+item[0].to_s+" Count: "+item[1].to_s)
end
