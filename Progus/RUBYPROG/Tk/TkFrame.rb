require 'tk'

f1 = TkFrame.new{
	relief("sunken")
	borderwidth(1)
	background("red")
	padx(100)
	pady(200)
	pack("side" => "left")
}

f2 = TkFrame.new{
	relief("groove")
	borderwidth(1)
	background("yellow")
	padx(10)
	pady(10)
	pack("side" => "right")
}

TkButton.new(f1){
	text("Button1")
	command{ print("Push button1 !!\n")}
	pack("fill" => 'x')
}

TkButton.new(f1){
	text("Button2")
	command{ print("push button2 !!\n")}
	pack("fill" => 'x')
}

TkButton.new(f2){
	text("Quit")
	command("exit")
	pack("fill" => "x")
}

Tk.mainloop()
