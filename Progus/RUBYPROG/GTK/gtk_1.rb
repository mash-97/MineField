require 'gtk3'

Gtk.init()

window = Gtk::Window.new("Time")
window.signal_connect('destroy'){Gtk.main_quit()}

time = Time.now.strftime("Today is %B %d %Y")

window.add(Gtk::Label.new(time))
window.set_default_size(150, 150)

window.show_all()
Gtk.main()

window = Gtk::Window.new("Tip")
window.signal_connect('destroy'){Gtk.main_quit()}
window.add(Gtk::Label.new("Run the program again\n   To see the program again"))
window.show_all()

Gtk.main()
