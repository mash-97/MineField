# import re
# def check_web_address(text):
#   pattern = r"^[a-zA-Z0-9.+_-]*\.(com|info|edu|org|US)$"
#   result = re.search(pattern, text)
#   return result != None

# print(check_web_address("gmail.com")) # True
# print(check_web_address("www@google")) # False
# print(check_web_address("www.Cour-sera.org")) # True
# print(check_web_address("web-address.com/homepage")) # False
# print(check_web_address("My_Favorite-Blog.US")) # True

import re
def check_time(text):
  pattern = r"^(1?[1-2]|[1-9]):[0-5][0-9]\s*?(AM|PM|am|pm)$"
  result = re.search(pattern, text)
  return result != None

# print(check_time("12:45pm")) # True
# print(check_time("9:59 AM")) # True
# print(check_time("6:60am")) # False
# print(check_time("five o'clock")) # False
print(check_time("13:00 am")) # False