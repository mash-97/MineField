require "tk"

root = TkRoot.new(){title "Today's Date"}

str = Time.now.strftime("Today is \n%B %d, %Y")

lab = TkLabel.new(root) do
	text str
	pack("padx" => 115, "pady" => 110, "side" => "top")
end

bt_ok = TkButton.new do
	text("OK")
	command{puts("The User says OK!")}
	pack(side: "left")
end

yo = TkButton.new do
	text("YO")
	command{puts("Yossup!")}
	pack(side: "left")
end
exit = TkButton.new{
	text("EXIT")
	command{return 0}
	pack(side: "right")
}
Tk.mainloop
