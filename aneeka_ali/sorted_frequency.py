
def sorted_frequency(string_text):
    words = string_text.split(" ")
    freq_list = []
    for word in words:
        freq_list.append([word, string_text.count(word)])
    freq_list.sort(key=lambda x: x[1])
    freq_dict = {}
    for f in freq_list:
        freq_dict[f[0]] = f[1]
    return freq_dict 


def perfect_check(number):
    sum = 0
    if number==0: return "Not Perfect"
    
    for i in range(1,number):
        if number%i == 0:
            sum += i 
            if sum > number:
                return "Not Perfect" 
    if sum==number: return "Perfect"
    return "Not Perfect"

def prime_check(number):
    if number==2: return "Prime" 
    if number==0 or number==1 or number%2==0: return "Not Prime" 
    
    i = 3 
    while i*i<=number:
        if number%i==0:
            return "Not Prime"
    return "Prime" 

def even_check(number):
    if number%2==0: return "Even"
    return "Odd"

def numbers_check(numbers_text):
    numbers_dict = {}
    for number in list(numbers_text):
        numbers_dict[int(number)] = []
    for k in numbers_dict.keys():
        numbers_dict[k] = (even_check(k), prime_check(k), perfect_check(k))
    return numbers_dict 


if __name__ == '__main__':
    string_text = input()
    print(numbers_check(string_text))

