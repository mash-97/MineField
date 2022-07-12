require("tk")

root = TkRoot.new{title("Push me")}
frame_1 = TkFrame.new(root)
frame_1.grid
frame_2 = TkFrame.new(root)
frame_2.grid
label = TkLabel.new(frame_1){text("Push the button")}

#Make it appear
label.grid

button = TkButton.new(frame_2){
	text("PUSH")
	command{print("ARRRRRRRRg!\n")}
}

#Make this appear
button.grid

Tk.mainloop()
