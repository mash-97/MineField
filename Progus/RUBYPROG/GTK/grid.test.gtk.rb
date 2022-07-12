require 'gtk3'

Gtk.init()

box = Gtk::Box.new(:horizontal)

label1 = Gtk::Label.new("Label_1")
label2 = Gtk::Label.new("Label_2")

box.add(label1)
box.add(label2)

window = Gtk::Window.new("Grid Test")
window.signal_connect('destroy'){Gtk.main_quit}
window.add(box)
window.show_all()

Gtk.main()
