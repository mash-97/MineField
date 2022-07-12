f = File.open('friends.marsh', 'w')
Marshal.dump(["fred", "bert", "mary"], f)
f.close()

File.open('morefriends.marsh', 'w'){
	|friendsfile|
	Marshal.dump(["sally", "agnes", "john"], friendsfile)
}

File.open('morefriends.marsh'){
	|f|
	$arr = Marshal.load(f)
}

myfriends = Marshal.load(File.open('friends.marsh'))
morefriends = Marshal.load(File.open('morefriends.marsh'))

p(myfriends)
p(morefriends)
p($arr)
