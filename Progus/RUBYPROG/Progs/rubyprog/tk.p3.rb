require("tk")
require("tkextlib/tile")

root = TkRoot.new()
l = Tk::Tile::Label.new(root){text("Starting...")}.grid
l.bind(:Enter){l[:text] = "Moved mouse inside"}
l.bind(:Leave){l[:text] = "Moved mouse outside"}
l.bind("1"){l[:text] = "Clicked left mouse button"}
l.bind("3"){l[:text] = "Clicked right mouse button"}
l.bind("Double-3"){l[:text] = "Double right clicked"}
l.bind("Double-1"){l[:text] = "Double left clicked"}
l.bind("B3-Motion", proc{|x,y| l[:text] = "right button drag to #{x} #{y}"}, "%x %y")
l.bind("B1-Motion", proc{|x,y| l[:text] = "left button drag to #{x} #{y}"}, "%x %y")
Tk.mainloop()

