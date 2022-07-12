require 'gtk3'
Gtk.init()

class SampleWindow < Gtk::Window
	def initialize(text)
		super(text)
		signal_connect('destroy')  {Gtk.main_quit()}
		set_default_size(150, 50)
		
		label = Gtk::Label.new
		label.text = "Text"
		entry = Gtk::Entry.new
		entry.text = "hello"
		button = Gtk::Button.new(label: " All Caps! ")
		button.signal_connect('clicked'){
			entry.text = entry.text.upcase
			label.text = "Enter text again"
		}
		entry.signal_connect('changed'){
			label.text = entry.text.length.to_s
		}
		
		box = Gtk::Box.new(:vertical, 20)
		box.add(label)
		box.add(entry)
		box.add(button)
		
		add(box)
		show_all()
	end
end


SampleWindow.new("Gtk Button")
Gtk.main()
		
