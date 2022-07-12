require("tk")

root = TkRoot.new{title("checkbutton demo")}
top = TkFrame.new(root)

pack_opts = {side: "top", anchor: "w"}

cb1var = TkVariable.new
cb2var = TkVariable.new
cb3var = TkVariable.new

cb1 = TkCheckButton.new(top) do
	variable(cb1var)
	text("computer science")
	command{puts("Button 1 = #{cb1var.value}")}
	pack(pack_opts)
end
