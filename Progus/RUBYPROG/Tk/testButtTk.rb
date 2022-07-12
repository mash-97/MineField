require 'tk'

button = TkButton.new{
	text("Hello World!")
	pack
}
button.configure("activebackground", "blue")

color = button.cget("activebackground")
puts(color.to_s)
Tk.mainloop()

