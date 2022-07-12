temp = 78
require("tk")

#Common packing options...
top = {"side" => 'top', "padx" => '5', "pady" => '5'}
left = {"side" => 'left', "padx" => '5', "pady" => '5'}
bottom = {"side" => 'bottom', "padx" => '5', 'pady' => '5'}

#Starting temperature...


root = TkRoot.new #{title "Thermostat"}
root.title("Thermostat")
tframe = TkFrame.new(root){background "#606060"}
bframe = TkFrame.new(root)
b1frame = TkFrame.new(root){background "#601060"}
co = "yellow"
b1lab = TkLabel.new(b1frame) do
	text("howdy")
	font("{Helvetica} 33 {bold}")
	foreground("blue")
	background("black")
	pack({padx: 15, pady: 16, side: "bottom"})
end
tlab = TkLabel.new(tframe) do
	text(temp.to_s)
	font("{Helvetica} 54 {bold}")
	if(temp > 74) then foreground("red")
	else foreground("yellow") end
	background("#606060")
	pack(left)
	puts("tlab")
end

#The "degree" symbol
TkLabel.new(tframe) do
	text("o")
	font("{Helvetica} 14 {bold}")
	foreground("green")
	background("#606060")
	#Anchor-north above text like a degree symbol
	pack(left.update(anchor: 'e'))
end

TkButton.new(bframe) do
	relief("groove")
	text("Up")
	pack(left)
	command do
		temp +=1
		tlab.configure(text: temp.to_s)	
	end
end
	
TkButton.new(bframe) do
	relief("groove")
	text("Down")
	pack(left)
	command do
		temp -= 1
		tlab.configure(text: temp.to_s)
		if(temp < 74) then tlab.configure(foreground: "black")
		elsif(temp > 74 && temp < 77) then tlab.configure(foreground: "yellow")
		else tlab.configure(foreground: "red") end
	end
end

tframe.pack(top)
bframe.pack(bottom)
b1frame.pack(left)
puts(temp)

Tk.mainloop()