from domain import *


def testCheckReal(): #test run for function checkReal
    assert(checkReal("7-0i")==True)
    assert(checkReal("-7+0i")==True)
    assert(checkReal("-7+9i")==False)
def testRealPart(): #test run for function realPart
    assert(realPart("7+9i")==7)
    assert(realPart("-9-8i")==-9)
    assert(realPart("0-7i")==0)
def testImaginaryPart(): #test run for function imaginaryPart
    assert(imaginaryPart("-1-1i")==-1)
    assert(imaginaryPart("7-9i")==-9)
    assert(imaginaryPart("0+0i")==0)
def testModuloComplex(): #test run for function moduloComplex
    assert(moduloComplex(0,0)==0)
    assert(moduloComplex(1,1)!=5)
    assert(moduloComplex(3,4)==5)
def testIntToString(): #test run for function intoToString
    assert(intToString(0,0)=="0+0i")
    assert(intToString(8,-1)=="8-1i")
    assert(intToString(-7,9)=="-7+9i")
    assert(intToString(-3,-4)=="-3-4i")