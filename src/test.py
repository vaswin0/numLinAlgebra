import matrix
#m = matrix.Matrix(3, 3)
#m.initRand(4, 4)
#m.initMatrix()



# Define a list of lists
mat = [
    [1.0, 2.0, 3.0],
    [4.0, 5.0, 6.0],
    [7.0, 8.0, 9.0]
]

# Initialize the matrix from the list of lists
m = matrix.Matrix(mat)

# Access elements
print(m(0, 0))  # Prints 1.0
print(m(1, 2))  # Prints 6.0

print('\n')

print(m)

