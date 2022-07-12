require("tk")
root = TkRoot.new
root.title("Log in")

TkLabel.new(root){
	text("Hello World!")
	font("{} 40 {}")
	pack({"padx" => 550, "pady" => 350, "side" => "bottom"})
}
Tk.mainloop()
