require 'gtk3'
Gtk.init()

class MenuSample < Gtk::Window
	
	def initialize
		super("Ruby/Gtk-3 Menu Sample")
		signal_connect(:destroy) { Gtk.main_quit() }
		
		file_exit_item = Gtk::MenuItem.new(label: "_Exit")
		file_exit_item.signal_connect(:activate) { Gtk.main_quit() }
		file_exit_item.set_tooltip_text("Activate to exit")
		
		file_menu = Gtk::Menu.new
		file_menu.add(file_exit_item)
		
		file_item = Gtk::MenuItem.new(label: "File")
		file_item.submenu = file_menu
		
		menubar = Gtk::MenuBar.new("vertical")
		menubar.append(file_item).append(Gtk::MenuItem.new(label: "Item_2")).
		append(Gtk::MenuItem.new(label: "Item_3"))
		
		box = Gtk::Box.new(:vertical)
		box.pack_start(menubar, expand: false, fill: false, padding: 0)
		box.add(Gtk::Label.new("Try menus and tooltips"))
		
		add(box)
		set_default_size(400, 101)
		show_all()
	end
end


MenuSample.new
Gtk.main
