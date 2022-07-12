require("tk")
require("tkextlib/tile")

root = TkRoot.new(){title("Expo")}

frame_1 = Tk::Tile::Frame.new(root).grid(:sticky => "nsew")
$aText = TkVariable.new()
$aText.value = "YOSSUP"
upSign = TkPhotoImage.new(:file => "download.jpg.gif")
label_1 = Tk::Tile::Label.new(frame_1){image(upSign)}.grid(:column => 1, :row => 1, :sticky => "e")

Tk.mainloop