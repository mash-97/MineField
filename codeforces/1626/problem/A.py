
def getEquidistantLetters(string):
    # char_indexed_array
    cia = [0 for i in range(27)]

    for s in string:
        cia[ord(s)-97] += 1
    
    # resutl_string
    rs = ""
    for i,v in enumerate(cia):
        rs += chr(i+97)*v 
    return rs 

if __name__ == '__main__':
    t = int(input())
    while(t>0):
        s = input()
        print(getEquidistantLetters(s))
        t -= 1
