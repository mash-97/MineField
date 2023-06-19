class Anime:
   def __init__(self, name, rating, genre):
     self.name = name
     self.rating = rating
     self.genre = genre

   def add_character(self, *info):
     pass

   def __str__(self):
     s = f"Name: {self.name}\nRating: {self.rating}\nGenre: {self.genre}"
     return s

class Naruto(Anime):
    def __init__(self, name, rating, genre, ry):
        super().__init__(name, rating, genre)
        self.ry = ry 
        self.characters = {}
    
    def release_year(self):
        return "{} has been released in {}!!!".format(self.name, self.ry)
    
    def add_character(self, *characters):
        i = 0
        l = len(characters)
        while i<l-1:
            if characters[i] in self.characters.keys():
                self.characters[characters[i]].append(characters[i+1])
            else:
                self.characters[characters[i]] = [characters[i+1]]
            i += 1
    def __str__(self):
        r = "\nCharacters:\nMain: {}\nAnti Hero: {}\nSupporting: {}\n".format(
            self.name, 
            self.rating,
            self.genre,
            self.ry,
            self.characters['Main'],
            self.characters['Anti Hero'],
            self.characters['Supporting']
        )
        return "Anime Details:\n"+super().__str__()+r 


class MyHeroAcademia(Anime):
    def __init__(self, name, rating, genre, season):
        super().__init__(name, rating, genre)
        self.season = season 
        self.characters = {}
    
    def season_status(self):
        return "{} has premiered {} seasons!!!".format(self.name, self.season)
    
    def add_character(self, *characters):
        i = 0
        l = len(characters)
        while i<l-1:
            if characters[i] in self.characters.keys():
                self.characters[characters[i]].append(characters[i+1])
            else:
                self.characters[characters[i]] = [characters[i+1]]
            i += 2
        
    def __str__(self):
        r = "\nCharacters:\nSupporting: {}\nAnti Hero: {}\nMain: {}\n".format(
            self.characters['Supporting'],
            self.characters['Anti Hero'],
            self.characters['Main'])
        return "Anime Details:\n"+super().__str__()+r


naruto = Naruto("Naruto", 10, "Adventure Fiction", 2007)
naruto.add_character("Naruto Uzumaki", "Main", "Itachi Uchiha", "Main", "Madara Uchiha", "Anti Hero", "Pain", "Supporting", "Shikamaru Nara", "Supporting")
print('1.------------------------------------')
print(naruto.release_year())
print('2.------------------------------------')
print(naruto)
print('3.====================================')
my_hero_academia = MyHeroAcademia("My Hero Academia", 8, "Superhero Fiction", 5)
my_hero_academia.add_character("Supporting", "Uraraka", "Anti Hero", "Nomu", "Supporting", "Mirio", "Main", "Midoriya", "Main", "Todoroki")
print('4.------------------------------------')
print(my_hero_academia.season_status())
print('5.------------------------------------')
print(my_hero_academia)