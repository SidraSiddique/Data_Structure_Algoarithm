
class Polynomial:
	def __init__(polynomial, degree):
		polynomial.degree = degree
		polynomial.coefficient = [0] * (polynomial.degree+1)
		polynomial.variable = 'x'
	
	def setCoefficient(polynomial, power, coefficient):
		polynomial.coefficient[power] = coefficient

	def printPolynomail(polynomial):
		i = polynomial.degree
		while i >= 0:
			if polynomial.coefficient[i] != 0:
				print(polynomial.coefficient[i], end='')
				print(polynomial.variable, end='')
				print('^', end='')
				print(i, end=' ')
				print('+' if polynomial.coefficient[i-1] > 0 else '', end=' ')
			i = i-1
		print()

	def value(polynomial, x):
		val = 0
		i = polynomial.degree
		while i >= 0:
			val = val + polynomial.coefficient[i] * pow(x, i)
			i = i-1
		return val

def main():
	e = Polynomial(3)
	e.setCoefficient(3, -2)
	e.setCoefficient(2, 5)
	e.setCoefficient(0, -1)
	e.printPolynomail()
	print(e.value(1))
	print(e.value(2))
	print(e.value(-5))

main()
