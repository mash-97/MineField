
class Q:
  dl = 100
  class EnqueueError(Exception):
    def __init__(self):
      super().__init__(f"Q is full!")
  
  class DequeueError(Exception):
    def __init__(self):
      super().__init__(f"Q is empty!")
  
  def __init__(self, lim=100, *args):
    self.lim = lim
    self.q = [None for i in range(0, self.lim)]
    self.si = 0
    self.ei = 0
    self.cs = 0
    if len(args)>0:
      for val in args:
        self.enq(val)
  
  def enq(self, val):
    if self.cs==self.lim:
      raise Q.EnqueueError
    self.cs += 1
    self.q[self.ei] = val 
    self.ei = (self.ei+1)%self.lim 
    # print(f"after enq of {val} --> cs: {self.cs}, self.si: {self.si}, self.ei: {self.ei}, self.q: {self.q}")
    return self.q[self.ei-1]
  
  def deq(self):
    if self.cs==0:
      raise Q.DequeueError
    self.cs -= 1
    val = self.q[self.si]
    self.si = (self.si+1)%self.lim
    # print(f"after deq of {val} --> cs: {self.cs}, self.si: {self.si}, self.ei: {self.ei}, self.q: {self.q}")
    return val 

    
  
def throwingCardsAway(deck):
  deck = Q(len(deck), *deck)
  discarded_cards = []
  while(deck.cs > 1):
    discarded_cards.append(deck.deq())
    mc = deck.deq()
    deck.enq(mc)
  remaining_card = deck.deq()
  return [discarded_cards, remaining_card]

if __name__=='__main__':
  while True:
    n = int(input())
    if n==0:
      break
    dcs, rc = throwingCardsAway([i for i in range(1, n+1)])
    print(f"Discarded cards: {', '.join([str(i) for i in dcs])}")
    print(f"Remaining card: {rc}")
