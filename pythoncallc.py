import ctypes

class StarList(ctypes.Structure):
   _fields_ = [("id",ctypes.c_float),
              ("ra",ctypes.c_float),
              ("dec",ctypes.c_float),
              ("x",ctypes.c_float),
              ("y",ctypes.c_float),
              ("mag",ctypes.c_float),
              ("mage",ctypes.c_float),
              ("distance",ctypes.c_float)]
objlen=12
reflen=10
objlength = (ctypes.c_int)(objlen)
reflength = (ctypes.c_int)(reflen)
obj = (StarList*objlen)()
ref = (StarList*reflen)()
match = (StarList*objlen)()

for i in range(0, objlen) : 
    obj[i].id = i
    obj[i].x = i + 0.1
    obj[i].y = i + 0.1

for j in range(0, reflen) : 
    ref[j].id = j
    ref[j].x = j + 0.2
    ref[j].y = j + 0.2

so = ctypes.CDLL("./dist/Debug/GNU-Linux-x86/libxxyymatch.so")
xxyymatch = so.xxyymatch
xxyymatch(ctypes.byref(obj), objlength, ctypes.byref(ref), reflength, ctypes.byref(match))

for i in range(0, objlen) : 
    print "%2d %f %f%2d %f %f %f" %(obj[i].id, obj[i].x, obj[i].y, match[i].id, match[i].x, match[i].y, match[i].distance)





