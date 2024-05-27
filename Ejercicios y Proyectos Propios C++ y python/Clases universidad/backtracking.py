def backtrack(nums, actual, result):
    # Agregar la combinación actual al resultado si está completa
    if len(actual) == len(nums):
        result.append(actual[:])
        return
    
    # Recorrer todos los elementos posibles para el siguiente paso de la combinación
    for num in nums:
        # Si el elemento ya está en la combinación actual, pasar al siguiente
        if num in actual:
            continue
        
        actual.append(num) # Agregar el elemento a la combinación actual
        backtrack(nums, actual, result) # Llamar recursivamente a la función backtrack
        actual.pop() # Eliminar el elemento agregado para explorar otras opciones

def findCombinations(nums):
    result = []
    actual = []
    backtrack(nums, actual, result)
    return result

nums = [1, 2, 3]
combinations = findCombinations(nums)

print("Combinaciones posibles:")
for combination in combinations:
    print(combination)


    