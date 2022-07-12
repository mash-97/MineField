#The Book of Ruby - http://www.sapphiresteel.com

#"double-quoted" heredoc
hdoc1 = <<E
I wandered lonely as a #{"cloud".upcase!}.
That floats on high o'er vale and hill...
E

#'single-quoted' heredoc
hdoc2 = <<'E'
I wandered lonely as a #{"cloud". upcase}.
That floats on high o'er vale and hill...
E

#heredoc with indented end marker
hdoc3 = <<-E
I wandered lonely as a #{"cloud".upcase}.
That floats on high o'er vale and hill...
	E

	
#heredoc with 'reserved word' end marker
hdoc4 = <<def
I wandered lonely as a #{"cloud".upcase}.
That float on high o'er vale and hill...
def

def printout(doc)
	puts ("#{doc}")
end

def printout2(doc)
	puts("'#{doc.chomp}'")
end

printout(hdoc1)
printout(hdoc2)
printout(hdoc3)
printout(hdoc4)


printout2(hdoc4
);;;;;;;gets