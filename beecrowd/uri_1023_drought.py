
# cunt = 0
# while True:
#   x = int(input())
#   if x==0: break
#   cunt += 1
#   consums_sum = 0.0
#   total_rsdnts = 0
#   cons = [0 for i in range(201)]

#   for i in range(x):
#     rsdnts, consums = map(lambda x: int(x), input().split(' '))
#     cpr = consums//rsdnts
#     if cons[cpr] == 0:
#         cons[cpr] = [f"{rsdnts}-{cpr}"]
#     else:
#         cons[cpr].append(f"{rsdnts}-{cpr}")

#     total_rsdnts += rsdnts
#     consums_sum += consums

#   l = []
#   for i in range(201):
#       if cons[i]!=0:
#           for x in cons[i]:
#               l.append(x)
#   consum_avrg = round(consums_sum/total_rsdnts, 2)

#   print(f"Cidade# {cunt}:")
#   print(" ".join(l))
#   print(f"Consumo medio: %.2f m3."%(consum_avrg))
#   print()
print("Your name: ")
name = input()
