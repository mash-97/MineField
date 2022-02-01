class Desc:
    def __set_name__(self, owner, name):
        print(f"__set_name__ > Owner: {owner}, Name: {name}")
        self.public_name = name 
        self.private_name = "_"+name
    
    def __get__(self, obj, obj_type=None):
        print(f"__get__ > Obj: {obj}, Obj Type: {obj_type}")
        return getattr(obj, self.private_name)
    
    def __set__(self, obj, value):
        print(f"__set__ > obj: {obj}, value: {value}")
        setattr(obj, self.private_name, value)

class Desc2:
    def __set_name__(self, owner, name):
        print(f"__set_name__ > Owner: {owner}, Name: {name}")
        self.public_name = name 
        self.private_name = "_"+name
    
    def __get__(self, obj, obj_type=None):
        print(f"__get__ > Obj: {obj}, Obj Type: {obj_type}")
        return getattr(obj, self.private_name)
    
    # def __set__(self, obj, value):
    #     print(f"__set__ > obj: {obj}, value: {value}")
    #     setattr(obj, self.private_name, value)


class D:
    def __get__(self, obj, t=None):
        return 5 


class A:
    d = Desc2()

    def __init__(self):
        self.d = 5
    
    def p(self):
        print(f"From A > self: {self}")
    
    
class B(A):
    d = Desc2()

    def __init__(self):
        self.d = 5
    
    def p(self):
        print(f"From B > self: {self}")
        super(B, self).p()


class C(A):
    def p(self):
        print(f"From C > self: {self}")
        super(C, self).p()


class T:
    def p(self):
        print(f"From T > self: {self}")

class TT(T):
    def p(self):
        print(f"From TT > self: {self}")
        super(TT, self).p()

class D(B, C):
    def p(self):
        print(f"From D > self: {self}")
        super(D, self).p()


class J(TT, D):
    def p(self):
        print(f"From J > self: {self}")
        super(J, self).p()
        super(J, self).p()



