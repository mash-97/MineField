class Passenger:
    def __init__(self, *args):
        self.name = args[0]
        self.ticket_type = None 
        self.money = 0
        if type(args[1]) == str:
            self.buyTicket(args[1])
            self.money = args[2]
            print(f"{self.name} is waiting for {self.ticket_type} having {self.money} taka in pocket.")

        else:
            self.money = args[1]
            print(f"{self.name} has {self.money} taka in pocket. Please buy a ticket.")

        self.has_bought_ticket = False 

    def buyTicket(self, ticket_type):
        if ticket_type=="Bus Ticket":
            self.ticket_type = "Bus"
        elif ticket_type=="Train Ticket":
            self.ticket_type = "Train"
        self.has_bought_ticket = True 
    
class TicketCounter:
    def __init__(self):
        self.passengers = {'Bus': [], 'Train': []} 
        print("This is a general bus and train ticket counter.")
    
    def servePassenger(self, *args):
        fare_chart = args[-1]
        for passenger in args[:-1]:
            if passenger.has_bought_ticket:
                print(f"{passenger.name} has bought {passenger.ticket_type} Ticket.")
                passenger.money -= fare_chart[passenger.ticket_type]
                self.passengers[passenger.ticket_type].append(passenger)
            else:
                print(f"{passenger.name} please buy a ticket.")
    
    def showAllPassenger(self):
        print(f"Total passengers: {len(self.passengers['Bus']+self.passengers['Train'])}")
        print(f"Bus passengers: {len(self.passengers['Bus'])}")
        for bp in self.passengers['Bus']:
            print(f"Passenger Name: {bp.name}\tRemaining balance: {bp.money}")
        for tp in self.passengers['Train']:
            print(f"Passenger Name: {tp.name}\tRemaining balance: {tp.money}")


if __name__=='__main__':
    fareChart = {"Bus":550, "Train":600}
    p1 = Passenger("Bob", "Bus Ticket",800)
    p2 = Passenger("Simon", "Train Ticket", 950)
    p3 = Passenger("David", "Train Ticket", 750)
    p4 = Passenger("Carol", 1500)
    print("1==============================")
    tc = TicketCounter()
    print("2==============================")
    tc.servePassenger(p1,fareChart)
    print("3==============================")
    tc.servePassenger(p2,fareChart)
    print("4==============================")
    tc.servePassenger(p3, p4, fareChart)
    print("5==============================")
    p4.buyTicket("Train Ticket")
    tc.servePassenger(p4,fareChart)
    print("6==============================")
    tc.showAllPassenger()


    

