def __m__(x, y):
    xm = sum(x)/len(x)
    ym = sum(y)/len(y)

    xym = sum(map(lambda i: i[0]*i[1], zip(x, y)))/len(x)
    xsm = sum(map(lambda i: i*i, x))/len(x)

    return round((xm*ym - xym) / (xm*xm - xsm), 2)

def __c__(xs, y):
    c = sum(y)/len(y)
    c -= sum([__m__(x, y)*sum(x)/len(x) for x in xs])
    return round(c, 2)

def getMultipleLinearRegressionFunct(xs, y):
    ms = [__m__(x, y) for x in xs]
    c = __c__(xs, y)

    print(f"ms: {ms}, c: {c}")

    def __mlr__(xs):
        msx = sum(map(lambda i: i[0]*i[1], zip(ms, xs)))
        return round(msx+c, 2)
    
    return __mlr__


if __name__ == '__main__':
    x1 = [1, 2, 4]
    x2 = [2, 3, 5]
    x3 = [3, 4, 6]

    y = [12, 9, 8]

    mlr = getMultipleLinearRegressionFunct([x1, x2, x3], y)

    print(mlr)
    print(mlr([5, 2, 9]))

    