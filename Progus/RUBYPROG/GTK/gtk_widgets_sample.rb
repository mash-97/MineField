require 'gtk3'
Gtk.init()

class TicketWindow < Gtk::Window
	
	def initialize
		super("Purchase Ticket")
		signal_connect("destroy") {
			Gtk.main_quit()
		}
		
		destination_model = Gtk::ListStore.new(String, String)
		destination_view = Gtk::TreeView.new(destination_model)
		destination_column = Gtk::TreeViewColumn.new("Destination", Gtk::CellRendererText.new, :text => 0)
		destination_view.append_column(destination_column)
		country_column = Gtk::TreeViewColumn.new("Country", Gtk::CellRendererSpin.new, :text => 1)
		destination_view.append_column(country_column)
		destination_view.selection.set_mode(:single)
		
		[["Cairo", "Egypt"], ["New York", "USA"],
			["Tokyo", "Japan"]].each do |destination, country|
				iter = destination_model.append
				iter[0] = destination
				iter[1] = country
			end
		destination_view.selection.signal_connect("changed") do
			@city = destination_view.selection.selected[0]
			@country = destination_view.selection.selected[1]
		end
		
		@round_trip = Gtk::CheckButton.new("Round Trip")
		
		purchase = Gtk::Button.new(label: "Purchase")
		purchase.signal_connect("clicked") {cmd_purchase}
		
		@result = Gtk::Label.new
		
		@coach = Gtk::RadioButton.new(label: "Coach class")
		@business = Gtk::RadioButton.new(member: @coach, label: "Business class")
		@first = Gtk::RadioButton.new(member: @business, label: "First class")
		
		flight_box = Gtk::Box.new(:vertical)
		flight_box.add(destination_view).add(@round_trip)
		
		seat_box = Gtk::Box.new(:vertical)
		seat_box.add(@coach).add(@business).add(@first)
		
		top_box = Gtk::Box.new(:horizontal)
		top_box.add(flight_box).add(seat_box)
		
		main_box = Gtk::Box.new(:vertical)
		main_box.add(top_box).add(purchase).add(@result)
		
		add(main_box)
		show_all()
	end
	
	def cmd_purchase
		text  = @city+", "+@country
		
		if @first.active?
			text += ": first class"
		elsif @business.active?
			text += ": business class"
		elsif @coach.active?
			text += ": coach"
		end
		
		text += ", round trip " if @round_trip.active?
		@result.text = text
	end
end

TicketWindow.new()
Gtk.main()
