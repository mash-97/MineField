require 'gtk3'
Gtk.init()

class SampleWindow < Gtk::Window
	def initialize
		super("Ruby/Gtk3 Sample")
		self.signal_connect("destroy"){ Gtk.main_quit()}
		
		entry = Gtk::Entry.new
		button = Gtk::Button.new("All Caps!")
		button.signal_connect("clicked"){
			entry.text = entry.text.upcase
		}
		
		box = Gtk::Box.new("center")
		box.add(Gtk::Label.new("Text: "))
		box.add(entry)
		box.add(button)
		
		add(box)
		self.show_all()
	end
end


SampleWindow.new
Gtk.main()
