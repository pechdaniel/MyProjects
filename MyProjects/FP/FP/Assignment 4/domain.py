def checkReal(nr): #checks if the element is a real number
    '''

    in:param nr
    out:return:True if the element is real or False if it is not
    '''
    poz=nr.find('i')
    if not poz==-1:
        if (nr[poz-2]==' ' or nr[poz-2]=='+' or nr[poz-2]=='-') and nr[poz-1]=='0':
            return True
    elif poz==-1:
        return True
    return False
from math import sqrt
def moduloComplex(a,b): #returns the modulus of the complex number
    '''

    in:param a,b
    out:return: the modulus of a and b
    '''
    return sqrt(a*a+b*b)
def realPart(nr): #return the real part of nr (nr is complex)
    '''

    in:param nr:
    out:return: the real part of nr
    '''
    nr = nr.strip()
    x=-1
    real=0
    aux=nr[1:]
    if nr[0]=='-':
        if aux.find('+')==-1:
          real=int(aux[:aux.find('-')])
        elif aux.find('-')==-1:
          real=int(aux[:aux.find('+')])
        real=real*x
    else:
        if nr.find('+')==-1:
          real=int(nr[:nr.find('-')])
        elif nr.find('-')==-1:
          real=int(nr[:nr.find('+')])
    return real
def imaginaryPart(nr): #return the imaginary part of nr (nr is complex)
    '''

    in:param nr:
    out:return: the imaginary part of nr
    '''
    nr=nr.strip()
    if nr[0]=='-' or nr[0]=='+':
        aux=nr[1:]
    else:
        aux=nr[0:]
    if aux.find('+')!=-1:
        aux=aux[aux.find('+')+1:aux.find('i')]
    if aux.find('-')!=-1:
        aux=aux[aux.find('-'):aux.find('i')]
    img=int(aux)
    return img
def intToString(a,b): #converts 2 intiger numbers into a complex number (string type)
    '''

    in:param a,b
    out:return: string u
    '''
    if b<0:
        u=str(a)+str(b)+'i'
    else:
        u = str(a) + '+' + str(b) + 'i'
    return u
