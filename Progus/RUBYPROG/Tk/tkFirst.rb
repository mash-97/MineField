require 'tk'

root = TkRoot.new{ 
	title("Hello, World!")
}

TkLabel.new(root) do
	padx(100)
	pady(100)
	text("Hello World!")
	
	justify("right")
	text("My name is Mash")
	foreground("red")
	background("black")
	pack{
		padx(20)
		pady(20)
		side("right")
	}
end

TkLabel.new(root) do
	padx(100)
	pady(100)
	text("Hello Mash")
end

Tk.mainloop()
