import ctypes

class StarList(ctypes.Structure):
   _fields_ = [("id",ctypes.c_int),
              ("ra",ctypes.c_float),
              ("dec",ctypes.c_float),
              ("x",ctypes.c_float),
              ("y",ctypes.c_float),
              ("mag",ctypes.c_float),
              ("mage",ctypes.c_float),
              ("distance",ctypes.c_float)]
len=10
length = (ctypes.c_int)(len)
obj = (StarList*len)()
ref = (StarList*len)()
match = (StarList*len)()

for i in range(0, len) : 
    obj[i].id = i
    obj[i].x = i + 0.1
    obj[i].y = i + 0.1
    ref[i].id = i
    ref[i].x = i + 0.2
    ref[i].y = i + 0.2

so = ctypes.CDLL("./dist/Debug/GNU-Linux-x86/libxxyymatch.so")
xxyymatch = so.xxyymatch
xxyymatch(ctypes.byref(obj), ctypes.byref(ref), ctypes.byref(match), length)

for i in range(0, len) : 
    print "%2d %f %f%2d %f %f %f" %(obj[i].id, obj[i].x, obj[i].y, match[i].id, match[i].x, match[i].y, match[i].distance)





