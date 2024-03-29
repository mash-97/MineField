import sys
import matplotlib.pyplot as plt
def f(x):
  x.append(x[0] - x[len(x)//2] + x[len(x)-1])
  return x

if __name__=="__main__":
  print(sys.argv)
  if(len(sys.argv)!=5):
    raise Exception("Must give 4 values");

  x = [int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])]
  for _ in range(int(sys.argv[4])):
    f(x)

  plt.plot(list(range(len(x))), x)
  plt.xlabel("x - axis")
  plt.ylabel("y - axis")
  plt.title("first - middle + last")
  plt.show()

