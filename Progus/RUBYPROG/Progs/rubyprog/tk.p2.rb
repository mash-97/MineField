require("tk")
require("tkextlib/tile")

root = TkRoot.new()
content = Tk::Tile::Frame(root)
Tk::Tile::Button(content)

Tk.mainloop()