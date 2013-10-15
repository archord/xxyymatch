import ctypes

objlen=12
reflen=10
objlength = (ctypes.c_int)(objlen)
reflength = (ctypes.c_int)(reflen)

objid = (ctypes.c_int*objlen)()
objra = (ctypes.c_float*objlen)()
objdec = (ctypes.c_float*objlen)()
objx = (ctypes.c_float*objlen)()
objy = (ctypes.c_float*objlen)()
objmag = (ctypes.c_float*objlen)()
objmage = (ctypes.c_float*objlen)()

refid = (ctypes.c_int*reflen)()
refra = (ctypes.c_float*reflen)()
refdec = (ctypes.c_float*reflen)()
refx = (ctypes.c_float*reflen)()
refy = (ctypes.c_float*reflen)()
refmag = (ctypes.c_float*reflen)()
refmage = (ctypes.c_float*reflen)()

matchid = (ctypes.c_int*objlen)()
matchra = (ctypes.c_float*objlen)()
matchdec = (ctypes.c_float*objlen)()
matchx = (ctypes.c_float*objlen)()
matchy = (ctypes.c_float*objlen)()
matchmag = (ctypes.c_float*objlen)()
matchmage = (ctypes.c_float*objlen)()
matchDistance = (ctypes.c_float*objlen)()

for i in range(0, objlen) : 
    objid[i] = i
    objx[i] = i + 0.1
    objy[i] = i + 0.1

for j in range(0, reflen) : 
    refid[j] = j
    refx[j] = j + 0.2
    refy[j] = j + 0.2

so = ctypes.CDLL("./dist/Debug/GNU-Linux-x86/libxxyymatch.so")
xxyymatch = so.xxyymatch
xxyymatch(ctypes.byref(objid), ctypes.byref(objra), ctypes.byref(objdec), ctypes.byref(objx), ctypes.byref(objy), ctypes.byref(objmag), ctypes.byref(objmage), ctypes.byref(refid), ctypes.byref(refra), ctypes.byref(refdec), ctypes.byref(refx), ctypes.byref(refy), ctypes.byref(refmag), ctypes.byref(refmage), ctypes.byref(matchid), ctypes.byref(matchra), ctypes.byref(matchdec), ctypes.byref(matchx), ctypes.byref(matchy), ctypes.byref(matchmag), ctypes.byref(matchmage), ctypes.byref(matchDistance), objlength, reflength)

for i in range(0, objlen) : 
    print "%2d %f %f%2d %f %f %f" %(objid[i], objx[i], objy[i], matchid[i], matchx[i], matchy[i], matchDistance[i])








